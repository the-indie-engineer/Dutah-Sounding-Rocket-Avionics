/*
 * RTC.h
 *
 *  Created on: 09-Apr-2023
 *      Author: Thiruvarulselvan K
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include "main.h"

#define DS3231_ADDRESS 0xD0

typedef struct {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hour;
	uint8_t dayofweek;
	uint8_t dayofmonth;
	uint8_t month;
	uint8_t year;
} TIME_Handle;

uint8_t decToBcd(int val);
int bcdToDec(uint8_t val);


#endif /* INC_RTC_H_ */
