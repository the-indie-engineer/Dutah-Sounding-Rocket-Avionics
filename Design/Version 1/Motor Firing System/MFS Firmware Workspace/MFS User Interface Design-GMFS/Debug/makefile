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


BUILD_ARTIFACT_NAME := MFS User Interface Design-GMFS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MFS\ User\ Interface\ Design-GMFS.elf \

MAP_FILES += \
MFS\ User\ Interface\ Design-GMFS.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MFS\ User\ Interface\ Design-GMFS.list \


# All Target
all: main-build

# Main-build Target
main-build: MFS\ User\ Interface\ Design-GMFS.elf secondary-outputs

# Tool invocations
MFS\ User\ Interface\ Design-GMFS.elf MFS\ User\ Interface\ Design-GMFS.map: $(OBJS) $(USER_OBJS) C:\Dutah\ Yukesh\Dutah-Sounding-Rocket-Avionics\Dutah-Sounding-Rocket-Avionics\Design\Motor\ Firing\ System\MFS\ Firmware\ Workspace\MFS\ User\ Interface\ Design-GMFS\STM32F446RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "MFS User Interface Design-GMFS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Dutah Yukesh\Dutah-Sounding-Rocket-Avionics\Dutah-Sounding-Rocket-Avionics\Design\Motor Firing System\MFS Firmware Workspace\MFS User Interface Design-GMFS\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MFS User Interface Design-GMFS.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MFS\ User\ Interface\ Design-GMFS.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MFS User Interface Design-GMFS.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) MFS\ User\ Interface\ Design-GMFS.elf MFS\ User\ Interface\ Design-GMFS.list MFS\ User\ Interface\ Design-GMFS.map MFS\\ User\\ Interface\\ Design-GMFS.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
