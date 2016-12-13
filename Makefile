# This file was automagically generated by mbed.org. For more information, 
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded
#With OBJECTS .o autofinder by BRODOLINE Ilya. ilya.brodoline@ensea.fr

# cross-platform directory manipulation
ifeq ($(shell echo $$OS),$$OS)
    MAKEDIR = if not exist "$(1)" mkdir "$(1)"
    RM = rmdir /S /Q "$(1)"
else
    MAKEDIR = $(SHELL) -c "mkdir -p "$(1)""
    RM = $(SHELL) -c "rm -rf "$(1)""
endif

ifeq (,$(filter .build,$(notdir $(CURDIR))))
.SUFFIXES:
OBJDIR := .build
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKETARGET = $(MAKE) --no-print-directory -C $(OBJDIR) -f $(mkfile_path) 		SRCDIR=$(CURDIR) $(MAKECMDGOALS)
.PHONY: $(OBJDIR) clean
all:
	+@$(call MAKEDIR,$(OBJDIR))
	+@$(MAKETARGET)
$(OBJDIR): all
Makefile : ;
% :: $(OBJDIR) ; :
clean :
	$(call RM,$(OBJDIR))

else

VPATH = .. 

GCC_BIN = 
PROJECT = ROBOT_PROG
OBJECTS = main.o PwmStepMotor.o GeneralItem.o StepMotor.o Point.o
SYS_OBJECTS = mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_flash_ramfunc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/board.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/cmsis_nvic.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/hal_tick.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/mbed_overrides.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/retarget.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/startup_stm32f401xe.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_adc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_adc_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_can.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cec.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cortex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_crc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cryp.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_cryp_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dac.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dac_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dcmi.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dcmi_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dma.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dma2d.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dma_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_dsi.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_eth.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_flash.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_flash_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_fmpi2c_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_fmpi2c.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_msp_template.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_gpio.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_hash.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_hash_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_hcd.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2c.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2c_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2s.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_i2s_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_irda.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_iwdg.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_lptim.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_ltdc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_ltdc_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_smartcard.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_nand.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_nor.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pccard.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pcd.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pcd_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pwr.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_pwr_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_qspi.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rcc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rcc_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rng.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rtc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_rtc_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sai.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sai_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sd.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sdram.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_spdifrx.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_spi.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_sram.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_tim.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_tim_ex.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_uart.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_usart.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_hal_wwdg.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_fmc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_fsmc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_sdmmc.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/stm32f4xx_ll_usb.o mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/system_stm32f4xx.o 
INCLUDE_PATHS = -I../. -I../mbed/. -I../mbed/TARGET_NUCLEO_F401RE -I../mbed/TARGET_NUCLEO_F401RE/TARGET_STM -I../mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4 -I../mbed/TARGET_NUCLEO_F401RE/TARGET_STM/TARGET_STM32F4/TARGET_NUCLEO_F401RE -I../mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM 
LIBRARY_PATHS = -L../mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM 
LIBRARIES = -lmbed 
LINKER_SCRIPT = ../mbed/TARGET_NUCLEO_F401RE/TOOLCHAIN_GCC_ARM/STM32F401XE.ld

############################################################################### 
AS      = $(GCC_BIN)arm-none-eabi-as
CC      = $(GCC_BIN)arm-none-eabi-gcc
CPP     = $(GCC_BIN)arm-none-eabi-g++
LD      = $(GCC_BIN)arm-none-eabi-gcc
OBJCOPY = $(GCC_BIN)arm-none-eabi-objcopy
OBJDUMP = $(GCC_BIN)arm-none-eabi-objdump
SIZE    = $(GCC_BIN)arm-none-eabi-size 

ifeq ($(HARDFP),1)
	FLOAT_ABI = hard
else
	FLOAT_ABI = softfp
endif


CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=$(FLOAT_ABI) 
CC_FLAGS = -c -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -fno-builtin -ffunction-sections -fdata-sections -funsigned-char -MMD -fno-delete-null-pointer-checks -fomit-frame-pointer -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Os -std=gnu99 -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -DTARGET_LIKE_MBED -DTARGET_NUCLEO_F401RE -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DMBED_BUILD_TIMESTAMP=1480005636.59 -DTOOLCHAIN_GCC -DTARGET_CORTEX_M -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_SERIAL=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_I2C=1 -DDEVICE_PORTOUT=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_STM32F401RE -DTARGET_FF_MORPHO -D__FPU_PRESENT=1 -DTARGET_FF_ARDUINO -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DDEVICE_PORTINOUT=1 -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DDEVICE_ERROR_RED=1 -DDEVICE_SPISLAVE=1 -DDEVICE_ANALOGIN=1 -DDEVICE_PWMOUT=1 -DARM_MATH_CM4 -include mbed_config.h -MMD -MP
CPPC_FLAGS = -c -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -fno-builtin -ffunction-sections -fdata-sections -funsigned-char -MMD -fno-delete-null-pointer-checks -fomit-frame-pointer -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Os -std=gnu++98 -fno-rtti -Wvla -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -DTARGET_LIKE_MBED -DTARGET_NUCLEO_F401RE -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DMBED_BUILD_TIMESTAMP=1480005636.59 -DTOOLCHAIN_GCC -DTARGET_CORTEX_M -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_SERIAL=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_I2C=1 -DDEVICE_PORTOUT=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_STM32F401RE -DTARGET_FF_MORPHO -D__FPU_PRESENT=1 -DTARGET_FF_ARDUINO -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DDEVICE_PORTINOUT=1 -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DDEVICE_ERROR_RED=1 -DDEVICE_SPISLAVE=1 -DDEVICE_ANALOGIN=1 -DDEVICE_PWMOUT=1 -DARM_MATH_CM4 -include mbed_config.h -MMD -MP
ASM_FLAGS = -x assembler-with-cpp -D__CMSIS_RTOS -D__FPU_PRESENT=1 -DARM_MATH_CM4 -D__CORTEX_M4 -D__MBED_CMSIS_RTOS_CM -c -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -fmessage-length=0 -fno-exceptions -fno-builtin -ffunction-sections -fdata-sections -funsigned-char -MMD -fno-delete-null-pointer-checks -fomit-frame-pointer -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Os
CC_SYMBOLS = -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -DTARGET_LIKE_MBED -DTARGET_NUCLEO_F401RE -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -DDEVICE_SERIAL_ASYNCH=1 -DTARGET_STM32F4 -D__CMSIS_RTOS -DMBED_BUILD_TIMESTAMP=1480005636.59 -DTOOLCHAIN_GCC -DTARGET_CORTEX_M -DTARGET_LIKE_CORTEX_M4 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DDEVICE_SERIAL=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_I2C=1 -DDEVICE_PORTOUT=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DTARGET_STM32F401RE -DTARGET_FF_MORPHO -D__FPU_PRESENT=1 -DTARGET_FF_ARDUINO -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DTARGET_STM -DDEVICE_SERIAL_FC=1 -DDEVICE_PORTINOUT=1 -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DDEVICE_ERROR_RED=1 -DDEVICE_SPISLAVE=1 -DDEVICE_ANALOGIN=1 -DDEVICE_PWMOUT=1 -DARM_MATH_CM4 

LD_FLAGS =-Wl,--gc-sections -Wl,--wrap,main -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp 
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys


ifeq ($(DEBUG), 1)
  CC_FLAGS += -DDEBUG -O0
else
  CC_FLAGS += -DNDEBUG -Os
endif


.PHONY: all lst size

all: $(PROJECT).bin $(PROJECT).hex size



.asm.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC) $(CPU) -c $(ASM_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<
.s.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC) $(CPU) -c $(ASM_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<
.S.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC) $(CPU) -c $(ASM_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<

.c.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CC)  $(CC_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<

.cpp.o:
	+@$(call MAKEDIR,$(dir $@))
	$(CPP) $(CPPC_FLAGS) $(CC_SYMBOLS) $(INCLUDE_PATHS) -o $@ $<



$(PROJECT).elf: $(OBJECTS) $(SYS_OBJECTS) $(LINKER_SCRIPT)
	$(LD) $(LD_FLAGS) -T$(filter %.ld, $^) $(LIBRARY_PATHS) -o $@ $(filter %.o, $^) -Wl,--start-group $(LIBRARIES) $(LD_SYS_LIBS) -Wl,--end-group


$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

$(PROJECT).hex: $(PROJECT).elf
	@$(OBJCOPY) -O ihex $< $@

$(PROJECT).lst: $(PROJECT).elf
	@$(OBJDUMP) -Sdh $< > $@

lst: $(PROJECT).lst

size: $(PROJECT).elf
	$(SIZE) $(PROJECT).elf

DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)


endif