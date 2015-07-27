# Project/output file name
PROJECT := RTOSDemo
EXE     := $(PROJECT).elf

# Common directories containing source/header files
DIR_COMPILER := Freescale_Code/compilers
DIR_PLATFORM := Freescale_Code/platform
DIR_LINKER   := $(DIR_COMPILER)/$(compiler)/linker
DIR_COMMON   := Freescale_Code/common
DIR_CPU      := Freescale_Code/cpu
DIR_UART     := Freescale_Code/drivers/uart
DIR_WDOG     := Freescale_Code/drivers/wdog
DIR_SRC      := ../../Source
DIR_MEM      := $(DIR_SRC)/portable/MemMang
DIR_MIN      := ../Common/Minimal

# Default compiler
compiler := iar

# List of supported compilers
compilers_list := iar gcc

# Compiler checking
ifneq ($(filter $(compiler),$(compilers_list)),$(compiler))
$(error Undefined compiler type: '$(compiler)', use one from: $(compilers_list))
endif

# Default load type
load_type := ram

# List of supported load types
load_types := ram flash

# Load type checking
ifneq ($(filter $(load_type),$(load_types)),$(load_type))
$(error Undefined load type: '$(load_type)', use one from: $(load_types))
endif

###############################################################################
# IAR compiler settings
###############################################################################

ifeq ($(compiler),iar)

# Environment variable IARARM_7.2_PATH must be set
# Spaces are not allowed in the path
# IAR_PATH := $(subst \,/,$(IARARM_7.2_PATH))
IAR_PATH := "C:/Program Files (x86)/IAR Systems/Embedded Workbench 7.2"

# IAR specific directory and .s file
DIR_CM4F := $(DIR_SRC)/portable/IAR/ARM_CM4F
SRC_ASM  := $(DIR_CM4F)/portasm.s

# Compiler/Assembler/Linker Paths
CC   := $(IAR_PATH)/arm/bin/iccarm
ASM  := $(IAR_PATH)/arm/bin/iasmarm
LINK := $(IAR_PATH)/arm/bin/ilinkarm

# Assemble/compile/link flags
ASFLAGS := --cpu Cortex-M4F --cpu_mode thumb -g
CFLAGS  := -On -e --cpu=Cortex-M4F --thumb --no_wrap_diagnostics --debug
CFLAGS  += -DS32K -DIAR --no_system_include
LDFLAGS := --no_wrap_diagnostics --skip_dynamic_initialization
LDFLAGS += -L $(IAR_PATH)/arm/lib --map $(PROJECT).map
LDFLAGS += --config $(DIR_LINKER)/512KB_P$(load_type).icf

ifeq ($(load_type),ram)

LDFLAGS += --entry __startup

else

CFLAGS += -DAPP_FLASH
LDFLAGS += --entry __iar_program_start

endif

# IAR related includes
INCLUDES := -I$(IAR_PATH)/arm/inc
INCLUDES += -I$(IAR_PATH)/arm/inc/c

endif

###############################################################################
# GCC compiler settings
###############################################################################

ifeq ($(compiler),gcc)

# Environment variable GCC_4.9_PATH must be set
# Spaces are not allowed in the path
GCC_PATH := $(subst \,/,$(GCC_4.9_PATH))

# GCC specific directory
DIR_CM4F := $(DIR_SRC)/portable/GCC/ARM_CM4F
SRC_ASM  :=

# Compiler/Assembler/Linker Paths
CC   := $(GCC_PATH)/bin/arm-none-eabi-gcc
ASM  := $(GCC_PATH)/bin/arm-none-eabi-gcc
LINK := $(GCC_PATH)/bin/arm-none-eabi-gcc

# Assemble/compile/link flags
ASFLAGS := -x assembler-with-cpp -mcpu=cortex-m4 -mthumb -c
ASFLAGS += -g3 -gdwarf-2 -nostdlib

OPTIMIZATION := -Os
CFLAGS  :=  $(OPTIMIZATION) -Wall -c -fmessage-length=0 -fplan9-extensions
CFLAGS  += -fomit-frame-pointer -mfloat-abi=softfp
CFLAGS  += -mcpu=cortex-m4 -g3 -mthumb -DS32K -DGCC
LDFLAGS := -gdwarf-2 -mcpu=cortex-m4 -g3 -mthumb --entry __startup
LDFLAGS += -Wl,-Map,$(PROJECT).map -specs=nosys.specs
LDFLAGS += -L $(GCC_PATH)/arm-none-eabi/lib/armv7-m
LDFLAGS += -T$(DIR_LINKER)/512KB_P$(load_type).ld

ifeq ($(load_type),flash)

CFLAGS += -DAPP_FLASH

endif

# GCC related includes
INCLUDES := -I$(GCC_PATH)/arm-none-eabi/include

endif

###############################################################################

# List of the common source files
SRC_ASM += $(DIR_COMPILER)/$(compiler)/crt0.s
SRC_C   := $(DIR_CPU)/arm_cm4.c $(DIR_MEM)/heap_2.c $(DIR_SRC)/list.c
SRC_C   += $(DIR_CM4F)/port.c
SRC_C   += $(DIR_CPU)/start.c $(DIR_SRC)/queue.c $(DIR_COMMON)/startup.c
SRC_C   += $(DIR_CPU)/sysinit.c $(DIR_SRC)/timers.c $(DIR_SRC)/tasks.c
SRC_C   += $(DIR_UART)/uart.c $(DIR_CPU)/vectors.c $(DIR_WDOG)/wdog.c

# List of the specific source files

ifeq ($(mode),full)

# SRC_C += ParTest.c
SRC_C += $(DIR_MIN)/BlockQ.c $(DIR_MIN)/PollQ.c $(DIR_MIN)/semtest.c
SRC_C += $(DIR_MIN)/blocktim.c $(DIR_MIN)/countsem.c $(DIR_MIN)/GenQTest.c
SRC_C += $(DIR_MIN)/QPeek.c $(DIR_MIN)/recmutex.c $(DIR_MIN)/TimerDemo.c
SRC_C += $(DIR_MIN)/death.c $(DIR_MIN)/dynamic.c
SRC_C += main-full.c

else

SRC_C += main_blinky.c

endif

# List of the objects files to be compiled/assembled
OBJECTS_ASM := $(SRC_ASM:.s=.o)
OBJECTS_C   := $(SRC_C:.c=.o)
OBJECTS     := $(OBJECTS_ASM) $(OBJECTS_C)

# Project related includes
INCLUDES += -I.
INCLUDES += -I../Common/include
INCLUDES += -I$(DIR_SRC)/include
INCLUDES += -I$(DIR_CM4F)
INCLUDES += -I$(DIR_COMMON)
INCLUDES += -I$(DIR_CPU)
INCLUDES += -I$(DIR_UART)
INCLUDES += -I$(DIR_WDOG)
INCLUDES += -I$(DIR_PLATFORM)
INCLUDES += -I$(DIR_COMPILER)/$(compiler)

###############################################################################

all: $(EXE)

$(EXE): $(OBJECTS)
	$(LINK) $(OBJECTS) $(LDFLAGS) -o $(EXE)

.c.o:
	$(info $@)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $(<:.c=.o)

.s.o:
	$(info $@)
	$(ASM) $(ASFLAGS) $< -o $(<:.s=.o)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXE) $(PROJECT).map