

#ifndef SRC_RFMODSTM32F4X_H_
#define SRC_RFMODSTM32F4X_H_

/*
 *****************************************************************************************************************************
 *Adaptado de RH_ASK.h
 *****************************************************************************************************************************
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"


#define TAM_MAX_PACOTE 67
#define TAM_MAX_MSG (TAM_MAX_PACOTE - 3)

#define AMOSTRAS_POR_BIT 8
#define COMP_RAMPA 160
#define INCR_RAMPA (COMP_RAMPA/AMOSTRAS_POR_BIT)
#define TRANSICAO_RAMPA COMP_RAMPA/2
#define AJUSTE_RAMPA 9
#define INCR_RAMPA_ATRASO (INCR_RAMPA - AJUSTE_RAMPA)
#define INCR_RAMPA_AVANCO (INCR_RAMPA + AJUSTE_RAMPA)

//bytes do preambulo: 36 bits de treinamento + 12 bits de in�cio
#define TAM_PREAMBULO 8

bool disponivel();

bool recb(uint8_t* buf, uint8_t* len);

bool envia(const uint8_t* data, uint8_t len);

void poeModoTx();

void poeModoRx();

void poeModoParado();

//traduz o s�mbolo de 6 bits para o nibble de 4 bits
uint8_t simbolo_para_nibble(uint8_t simbolo);

//fun��o que executa a cada estouro do timer se em modo Rx
void TimerRecb();

//fun��o que executa a cada estouro do timer se em modo Tx
void TimerEnvia();

//deve ser colocada na rotina de interrup��o do timer de amostragem
void TimerRotinaInterrupcao();

//fun��o que confere se o CRC deu certo
void validaRxBuf();
//depura��o---------------
//uint8_t marca;
//------------------------


/*
 *****************************************************************************************************************************
 *Adaptado de RHGenericDriver.h
 *****************************************************************************************************************************
 */

typedef enum
{
ModoParado,
ModoTx,
ModoRx,
} Modo;

bool rf_init();//coloca o pre�mbulo (bits de treino + palavra de in�cio) no _txBuf e ModoParado

bool esperaEnvio();
//n�o implementado - diagn�stico do buffer. buf seleciona o buffer
//static void printBuffer(const char* prompt, const uint8_t* buf, uint8_t len);

uint16_t rxRuim();

uint16_t rxBom();

uint16_t txBom();


/*
 *****************************************************************************************************************************
 *Adaptado de RHCRC.h
 *****************************************************************************************************************************
 */
extern uint16_t atualiza_crc_xmodem(uint16_t crc, uint8_t data);

#endif /* SRC_RFMODSTM32F4X_H_ */
