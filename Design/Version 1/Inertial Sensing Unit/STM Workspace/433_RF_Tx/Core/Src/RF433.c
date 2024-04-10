#include "RF433.h"

/*
 *****************************************************************************************************************************
 *Adaptado de RH_ASK.cpp
 *****************************************************************************************************************************
 */
#define SIMBOLO_INICIO 0xb38
//flags de leitura e de escrita
volatile bool _rxBufCheio;

volatile bool _rxBufValido;

volatile bool _rxUltAmostra; //ultima amostra

volatile uint8_t _rxIntegrador;

volatile uint8_t _rxRampa;

volatile uint8_t _rxAtivo;
//ultimos 12 bits recebidos pra ver simbolo de inicio
volatile uint16_t _rxBits;

volatile uint8_t _rxBitCount;
//onde fica guardada a mensagem recebida
uint8_t _rxBuf[TAM_MAX_PACOTE];
//tamanho esperado da mensagem
volatile uint8_t _rxCount;
//tamanho do buffer de recebimento at� o momento
volatile uint8_t _rxBufTam;

uint8_t _txIndex;

uint8_t _txBit;

uint8_t _txAmostra;

uint8_t _txBuf[(TAM_MAX_PACOTE * 2) + TAM_PREAMBULO];

uint8_t _txBufTam;
uint16_t _txBom;

uint16_t _rxBom;

uint16_t _rxRuim;

volatile Modo _modo;
static uint8_t simbolos[] =
{
		0xd,  0xe,  0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c,
		0x23, 0x25, 0x26, 0x29, 0x2a, 0x2c, 0x32, 0x34
};

/*Aqui deve-se ter o microcontrolador com um timer de 16kHz
 * para amostragem de 8 vezes por bit. A velocidade de
 * transmiss�o � de 2kbs
 */


void poeModoTx()
{
	if (_modo != ModoTx)
	{
		//zera os contadores de controle de envio
		_txIndex = 0;
		_txBit = 0;
		_txAmostra = 0;

		_modo = ModoTx;
	}
}

void poeModoRx()
{
	if (_modo != ModoRx)
	{
		HAL_GPIO_WritePin(Tx_RF_GPIO_Port, Tx_RF_Pin, 0);
		_modo = ModoRx;
	}
}

void poeModoParado()
{
	if (_modo != ModoParado)
	{
		HAL_GPIO_WritePin(Tx_RF_GPIO_Port, Tx_RF_Pin, 0);
		_modo = ModoParado;
	}
}

bool disponivel()
{
	if(_modo == ModoTx)
		return false;
	poeModoRx();
	if(_rxBufCheio)
	{
		validaRxBuf();
		_rxBufCheio= false;
	}
	return _rxBufValido;
}

bool recb(uint8_t* buf, uint8_t* len)
{
	if(!disponivel())
		return false;
	if(buf && len)
	{
		uint8_t tam_msg = _rxBufTam - 3;
		if(*len > tam_msg)
			*len = tam_msg;
	memcpy(buf, _rxBuf+1, *len);
	}
	_rxBufValido = false;
	return true;
}

bool envia (const uint8_t* data, uint8_t len)
{
	uint8_t i;
	uint16_t index = 0;
	uint16_t crc = 0xffff;
	uint8_t *p = _txBuf + TAM_PREAMBULO;
	uint8_t count = len + 3;

	if(len > TAM_MAX_MSG)
		return false;

	esperaEnvio();

	//codifica o tamanho da mensagem passando de 4bits para 6 bits
	crc = atualiza_crc_xmodem(crc, count);
	p[index++] = simbolos[count >> 4];
	p[index++] = simbolos[count & 0xf];

	//codifica a mensagem
	for(i=0; i<len; i++)
	{
		crc = atualiza_crc_xmodem(crc,data[i]);
		p[index++] = simbolos[data[i] >> 4];
		p[index++] = simbolos[data[i] & 0xf];
	}

	//codifica o crc
	p[index++] = simbolos[(crc >> 12) & 0xf];
	p[index++] = simbolos[(crc >> 8) & 0xf];
	p[index++] = simbolos[(crc >> 4) & 0xf];
	p[index++] = simbolos[crc & 0xf];

	//Cada simbolo de 6bits guardado em um byte,
	//n�mero de simbolos para enviar
	_txBufTam = index + TAM_PREAMBULO;

	//liga o hardware para enviar
	poeModoTx();
	return true;
}

uint8_t simbolo_para_nibble(uint8_t simbolo)
{
	uint8_t i;
	uint8_t count;

	//busca linear, mas como o bit 5 da segunda metade � 1,
	//j� da pra pesquisar s� uma metade

	for (i = (simbolo>>2) & 8, count = 8; count-- ; i++)
		if(simbolo == simbolos[i]) return i;

	return -1;//n�o encontrou
}

void validaRxBuf()
{
	uint16_t crc = 0xffff;
	//o crc vai desde a contagem de bytes at� o CRC anexado
	for(uint8_t i = 0; i < _rxBufTam; i++)
		crc = atualiza_crc_xmodem(crc, _rxBuf[i]);
	if(crc != 0)//espera-se que o crc seja zero
	{
		_rxRuim++;
		_rxBufValido = false;
		return;
	}
	_rxBom++;
	_rxBufValido = true;
}

void TimerRecb()
{

	bool rxAmostra;
	rxAmostra = HAL_GPIO_ReadPin(Rx_RF_GPIO_Port, Rx_RF_Pin);
	//depura��o---------------
	//marca = 0;
	//------------------------

	if (rxAmostra)
		_rxIntegrador++;
	if (rxAmostra != _rxUltAmostra)
	{
	//quando o sinal mudou de estado, tem que reavaliar a sincronia
		if(_rxRampa < TRANSICAO_RAMPA)
			_rxRampa += INCR_RAMPA_ATRASO;
		else
			_rxRampa += INCR_RAMPA_AVANCO;
		_rxUltAmostra = rxAmostra;
	}
	else
		_rxRampa += INCR_RAMPA;

	if(_rxRampa >= COMP_RAMPA)//terminou o periodo de um bit
	{
		_rxBits >>= 1;
		// se a m�dia for mais pr�xima de 1, o bit lido � 1
		if(_rxIntegrador >= 5)
			_rxBits |= 0x800;

		_rxRampa -= COMP_RAMPA;
		_rxIntegrador = 0;
		//depura��o-------------------------------------
		//marca = 1;

		//----------------------------------------------

		if(_rxAtivo)
		{
		//j� recebeu o s�mbolo de in�cio, o que t� chegando � dado
			if(++_rxBitCount >= 12)
			{
				//12 bits = 2 sibolos de 6 = 1 byte de dado
				//6 lsb do s�mbolo chegaram primeiro, s�o o high nibble do byte
				uint8_t this_byte =
						(simbolo_para_nibble(_rxBits & 0x3f) << 4)
						| simbolo_para_nibble(_rxBits >> 6);
				//depura��o-------------------------------------
				//marca = 2; //recebi o byte de cima!

				//----------------------------------------------
				//se for o primeiro byte, ele � o n�mero de bytes na mensagem
				if(_rxBufTam == 0)
				{
					_rxCount = this_byte;
					if(_rxCount < 4 || _rxCount > TAM_MAX_PACOTE)
					{
						//tamanhos menores que o m�nimo e maiores que o m�ximo
						_rxAtivo = false;
						_rxRuim++;
						return;
					}
				}
				_rxBuf[_rxBufTam++] = this_byte;

				if(_rxBufTam >= _rxCount)
				{
					//j� leu todos os bytes
					_rxAtivo = false;
					_rxBufCheio = true;
					poeModoParado();
				}
				_rxBitCount = 0;
			}
		}
		//se n�o estiver dentro de uma mensagem, s� aguardando
		else if(_rxBits == SIMBOLO_INICIO)
		{
		//recebeu um s�bolo de in�cio
			//depura��o-------------------------------------
			//marca = 3; //in�cio!

			//----------------------------------------------
			_rxAtivo = true;
			_rxBitCount = 0;
			_rxBufTam = 0;
		}
	}
}

void TimerEnvia()
{
	if(_txAmostra++ == 0)//contador para esperar 8 amostras
	{
		if(_txIndex >= _txBufTam)//se terminou de mandar
		{
			poeModoParado();
			_txBom++;
		}
		else
		{
			bool  sinal;
			sinal = (_txBuf[_txIndex] & (1 << _txBit++));
			HAL_GPIO_WritePin(Tx_RF_GPIO_Port, Tx_RF_Pin, sinal);
			if(_txBit >= 6)
			{
				_txBit = 0;
				_txIndex++;
			}
		}
	}
	if(_txAmostra > 7)
		_txAmostra = 0;
}

//chamar essa fun��o dentro da rotina de interrup��o do timer
void TimerRotinaInterrupcao()
{
	if(_modo == ModoRx)
		TimerRecb();
	else if (_modo == ModoTx)
		TimerEnvia();
}

/*
 *****************************************************************************************************************************
 *Adaptado de RHGenericDriver.cpp
 *****************************************************************************************************************************
 */

bool rf_init()
{
	 uint8_t preambulo[TAM_PREAMBULO] = {0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x38, 0x2c};
	 memcpy(_txBuf, preambulo, sizeof(preambulo));//inicia o _txbuf colocando o preambulo
	 _modo = ModoParado;
	return true;
}

bool esperaEnvio()
{
	while(_modo == ModoTx)//fica aqui at� terminar a transmiss�o
	{
	//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	//HAL_Delay(2000);
	}
	return true;
}

uint16_t rxRuim()
{
    return _rxRuim;
}

uint16_t rxBom()
{
    return _rxBom;
}

uint16_t txBom()
{
    return _txBom;
}

/*
 *****************************************************************************************************************************
 *Adaptado de RHCRC.c
 *****************************************************************************************************************************
 */

uint16_t atualiza_crc_xmodem(uint16_t crc, uint8_t data)
{
    //padr�o crc xmodem ou ccitt, mas parece que ccitt � um nome errado
	//ser� usado com resto inicial crc = 0xffff
	//polinomio truncado = 0x1021
	//16 bits de crc
	//pega um byte e atualiza o crc com esse byte que foi "encaixado" na palavra
	int i;

    crc = crc ^ ((uint16_t)data << 8);
    for (i=0; i<8; i++)
    {
	if (crc & 0x8000)
	    crc = (crc << 1) ^ 0x1021;
	else
	    crc <<= 1;
    }

    return crc;
}

