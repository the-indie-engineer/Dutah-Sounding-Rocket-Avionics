################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.elf \

MAP_FILES += \
CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.list \


# All Target
all: main-build

# Main-build Target
main-build: CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.elf secondary-outputs

# Tool invocations
CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.elf CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.map: $(OBJS) $(USER_OBJS) C:\THIRUVARULSELVAN\Dutah-Sounding-Rocket-Avionics\Design\Inertial\ Sensing\ Unit\STM\ Workspace\CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure\STM32F446RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\THIRUVARULSELVAN\Dutah-Sounding-Rocket-Avionics\Design\Inertial Sensing Unit\STM Workspace\CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.elf CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.list CPM_Voltage_Gyro_Acc_Motor_Temp_Baro_Curr5A_Curr20A_GPS_NCPressure.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
