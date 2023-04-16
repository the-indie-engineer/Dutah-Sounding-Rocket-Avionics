/*
 * HX710B.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Dutah/Thiruvarulselvan K
 */

#ifndef INC_HX710B_H_
#define INC_HX710B_H_

#define LSBFIRST 0
#define MSBFIRST 1

typedef uint8_t byte;

unsigned long readHX();
uint8_t shiftIn(GPIO_TypeDef* dataPort, uint16_t dataPin, GPIO_TypeDef* clockPort, uint16_t clockPin, uint8_t bitOrder);



#endif /* INC_HX710B_H_ */
