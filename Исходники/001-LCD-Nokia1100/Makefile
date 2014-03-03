#-------------------------------------------------------------------------------
# Makefile @ Denis Zheleznyakov http://ziblog.ru
#-------------------------------------------------------------------------------

OPTIMIZATION = s

SRC_C  = main.c
SRC_C += macros.c
SRC_C += lcd_nokia1100.c
SRC_C += stm32f4xx_rcc.c

SRC_ASM += startup_stm32f4xx.s

CROSS_PATH = D:/Tools/CodeSourcery/

CROSS_VERSION = 2012-03-56

CROSS = $(CROSS_PATH)$(CROSS_VERSION)/bin/arm-none-eabi-

INCLUDES += -I$(CROSS_PATH)/arm-none-eabi/include
INCLUDES += -I$(CROSS_PATH)/arm-none-eabi/include/lib
INCLUDES += -Imcu
INCLUDES += -Imcu/core
INCLUDES += -Imcu/startup
INCLUDES += -Imcu/peripherals
INCLUDES += -Imcu/std_lib/inc
INCLUDES += -Imcu/std_lib/src
INCLUDES += -Iutility

VPATH += mcu
VPATH += mcu/core
VPATH += mcu/startup
VPATH += mcu/peripherals
VPATH += mcu/std_lib/inc
VPATH += mcu/std_lib/src
VPATH += utility

FLAGS_C  = $(INCLUDES) -I.
FLAGS_C += -O$(OPTIMIZATION)
FLAGS_C += -gdwarf-2
FLAGS_C += -Wall
FLAGS_C += -c
FLAGS_C += -fmessage-length=0
FLAGS_C += -fno-builtin
FLAGS_C += -ffunction-sections
FLAGS_C += -fdata-sections
FLAGS_C += -msoft-float
FLAGS_C += -mapcs-frame
FLAGS_C += -D__thumb2__=1
FLAGS_C += -mno-sched-prolog
FLAGS_C += -fno-hosted
FLAGS_C += -mtune=cortex-m4
FLAGS_C += -mcpu=cortex-m4
FLAGS_C += -mthumb
FLAGS_C += -mfix-cortex-m3-ldrd
FLAGS_C += -fno-strict-aliasing
FLAGS_C += -ffast-math
FLAGS_C += -std=c99

FLAGS_LD = -Xlinker -Map=target/target.map
FLAGS_LD += -Wl,--gc-sections
FLAGS_LD += -mcpu=cortex-m4
FLAGS_LD += -mthumb
FLAGS_LD += -static   
#FLAGS_LD += -stdlib
#FLAGS_LD += -nostartfiles

#LIB_LD = -lm

FLAGS_ASM  = -D__ASSEMBLY__
FLAGS_ASM += -g $(FLAGS_C)
FLAGS_ASM += -I. -x assembler-with-cpp

all: clean
	@make -s -j job_target

job_target: target.elf

%.elf: $(SRC_ASM:%.S=target/%.o) $(SRC_C:%.c=target/%.o)
	@echo Linking: $@
	@$(CROSS)gcc $(FLAGS_LD) -T'mcu/startup/stm32f4xx_flash.ld' -o 'target/$@' $^ $(LIB_LD)
	@echo '--------------------------------------------------------------------'
	@$(CROSS)size 'target/target.elf'
	@$(CROSS)objcopy -O binary 'target/target.elf' 'target/target.bin'
	@$(CROSS)objcopy -O ihex 'target/target.elf' 'target/target.hex'
	@$(CROSS)objdump -h -S -z 'target/target.elf' > 'target/target.lss'
	@$(CROSS)nm -n 'target/target.elf' > 'target/target.sym'
	@rm -f target/*.o

$(SRC_C:%.c=target/%.o): target/%.o: %.c
	@echo Compiling: $<
	@$(CROSS)gcc $(FLAGS_C) -c $< -o $@

$(SRC_ASM:%.s=target/%.o): target/%.o: %.s
	@echo Compiling asm: $<
	@$(CROSS)gcc $(FLAGS_ASM) -c $< -o $@

clean:
	@echo '-----------------------------------------------------------'
	@mkdir -p target
	@rm -f target/*.*
