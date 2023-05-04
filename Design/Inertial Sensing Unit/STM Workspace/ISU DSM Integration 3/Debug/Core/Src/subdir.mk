################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BMP180.c \
../Core/Src/DataPacket.c \
../Core/Src/HX710B.c \
../Core/Src/MAX6675.c \
../Core/Src/NMEA.c \
../Core/Src/RTC.c \
../Core/Src/fatfs_sd.c \
../Core/Src/main.c \
../Core/Src/mpu6050.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/uartRingBuffer.c 

OBJS += \
./Core/Src/BMP180.o \
./Core/Src/DataPacket.o \
./Core/Src/HX710B.o \
./Core/Src/MAX6675.o \
./Core/Src/NMEA.o \
./Core/Src/RTC.o \
./Core/Src/fatfs_sd.o \
./Core/Src/main.o \
./Core/Src/mpu6050.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/uartRingBuffer.o 

C_DEPS += \
./Core/Src/BMP180.d \
./Core/Src/DataPacket.d \
./Core/Src/HX710B.d \
./Core/Src/MAX6675.d \
./Core/Src/NMEA.d \
./Core/Src/RTC.d \
./Core/Src/fatfs_sd.d \
./Core/Src/main.d \
./Core/Src/mpu6050.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/uartRingBuffer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/BMP180.cyclo ./Core/Src/BMP180.d ./Core/Src/BMP180.o ./Core/Src/BMP180.su ./Core/Src/DataPacket.cyclo ./Core/Src/DataPacket.d ./Core/Src/DataPacket.o ./Core/Src/DataPacket.su ./Core/Src/HX710B.cyclo ./Core/Src/HX710B.d ./Core/Src/HX710B.o ./Core/Src/HX710B.su ./Core/Src/MAX6675.cyclo ./Core/Src/MAX6675.d ./Core/Src/MAX6675.o ./Core/Src/MAX6675.su ./Core/Src/NMEA.cyclo ./Core/Src/NMEA.d ./Core/Src/NMEA.o ./Core/Src/NMEA.su ./Core/Src/RTC.cyclo ./Core/Src/RTC.d ./Core/Src/RTC.o ./Core/Src/RTC.su ./Core/Src/fatfs_sd.cyclo ./Core/Src/fatfs_sd.d ./Core/Src/fatfs_sd.o ./Core/Src/fatfs_sd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mpu6050.cyclo ./Core/Src/mpu6050.d ./Core/Src/mpu6050.o ./Core/Src/mpu6050.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/uartRingBuffer.cyclo ./Core/Src/uartRingBuffer.d ./Core/Src/uartRingBuffer.o ./Core/Src/uartRingBuffer.su

.PHONY: clean-Core-2f-Src

