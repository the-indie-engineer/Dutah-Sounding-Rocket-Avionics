/*
 * DataPkt.h
 *
 *  Created on: 28-Dec-2022
 *      Author: USER
 */

#ifndef INC_DATAPKT_H_
#define INC_DATAPKT_H_



#endif /* INC_DATAPKT_H_ */


//Message packet structure
union Transmission
{
float dataframe[18];
struct Telemetry	// From Controller
{
	float Altitude;  // 0X90
	float Ax;  // 0XEB
	float Ay;
	float Az;
	float Gx;
	float Gy;
	float Gz;
	float CPM_Voltage;
	float H_Voltage;
	float CPM_Current;
	float H_Current;
	float latitude;
	char NS;
	float longitude;
	char EW;
	float M_Temp;
	float NC_Press;
}tlm1;
};

union Reception
{
char dataframe[11];
struct Command	// From Controller
{
	uint8_t ucHeader1;  // 0X90
	uint8_t ucHeader2;  // 0XEB
	uint8_t ucAMDIsysID;
	uint8_t ucZone;
	uint8_t ucSector;
	uint8_t ucCalibreSetting;
	uint16_t ucStatus;
	uint8_t ucSpare1;
	uint8_t ucSpare2;
	uint8_t ucFooter;	// 0XAA
}cmd1;
};


void PackTx(char* TxBuff, union Transmission* trans1 );

union Transmission trans1;
union Reception rx1;
