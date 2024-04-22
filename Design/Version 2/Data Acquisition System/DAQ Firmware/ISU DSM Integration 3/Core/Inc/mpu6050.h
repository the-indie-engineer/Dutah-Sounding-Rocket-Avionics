/*
 * mpu6050.h
 *
 *  Created on: 01-Mar-2023
 *      Author: Thiruvarulselvan K
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

void MPU6050_Init (void);
void MPU6050_Read_Accel (float* Ax, float* Ay, float* Az);
void MPU6050_Read_Gyro (float* Gx, float* Gy, float* Gz);


#endif /* INC_MPU6050_H_ */
