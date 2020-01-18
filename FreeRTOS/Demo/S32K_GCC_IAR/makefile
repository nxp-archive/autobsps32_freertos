#
# Copyright 2018 NXP
#

# Project/output file name
PROJECT := RTOSDemo
EXE     := $(PROJECT).elf
MAP     := $(PROJECT).map

# Default compiler
compiler := gcc

# Default platform
platform := s32k144HT

PROC := cortex-m4
CPU_DEFINE := CPU_S32K144HT
CPU_file_name := cortex-m4


# Default load type
load_type := flash

# List of supported load types
load_types := ram flash

# Load type checking
ifneq ($(filter $(load_type),$(load_types)),$(load_type))
$(error Undefined load type: '$(load_type)', use one from: $(load_types))
endif

# Common directories containing source/header files
DIR_COMPILER := Freescale_Code/compilers
DIR_PLATFORM := Freescale_Code/platform/$(platform)
DIR_LINKER   := $(DIR_COMPILER)/$(compiler)/linker
DIR_COMMON   := Freescale_Code/common
DIR_CPU      := Freescale_Code/cpu
DIR_WDOG     := Freescale_Code/drivers/wdog
DIR_SRC      := ../../Source
DIR_MEM      := $(DIR_SRC)/portable/MemMang
DIR_MIN      := ../Common/Minimal

# Please edit path to Lauterbach Trace32 software if necessary
EXPECT_DBG   := T32SYS
DBGDIR       := $(subst \,/,$($(EXPECT_DBG)))

# T32 binary path related variables
T32_HOSTOS   := windows
T32EXE       := t32marm

# t32m* relative path in the $(LAUTERBACH_PATH) tree
DBGEXE_RELPATH := bin/$(T32_HOSTOS)/$(T32EXE)

PLATFORM       := $(platform)
BAT            := $(PLATFORM).bat
CMM            := $(PLATFORM).cmm

###############################################################################
# Please replace -DAPP_CFLAG -DCORE_CFLAG -DAPP_ASFLAG -DCORE_ASFLAG
# with the flags needed by your project
###############################################################################

###############################################################################
# GCC compiler settings
###############################################################################

# Environment variable GCC_ARM_6_3_PATH must be set
# Spaces are not allowed in the path
GCC_PATH := $(subst \,/,"$(GCC_ARM_6_3_PATH)")

# Compiler/Assembler/Linker paths
CC   := $(GCC_PATH)/bin/arm-none-eabi-gcc.exe
ASM  := $(GCC_PATH)/bin/arm-none-eabi-gcc.exe
LINK := $(GCC_PATH)/bin/arm-none-eabi-gcc.exe

OPTIMIZATION := -O0
# Assemble/Compile/Link flags
ASFLAGS      := -c -x assembler-with-cpp $(OPTIMIZATION)
ASFLAGS      += -mcpu=$(PROC) -mthumb -D$(CPU_DEFINE)
ASFLAGS      += -g3 -gdwarf-2 -nostdlib

CFLAGS       :=  $(OPTIMIZATION) -Wall -c -fmessage-length=0 -fplan9-extensions
CFLAGS       += -mcpu=$(PROC) -g3 -mthumb -DGCC -D$(CPU_DEFINE)

LDFLAGS      := -gdwarf-2 -mcpu=$(PROC) -g3 -mthumb --entry __startup
LDFLAGS      += -Wl,-Map,$(MAP)
LDFLAGS      += -T$(DIR_LINKER)/$(platform)_$(load_type).ld
LDFLAGS      += --sysroot=$(GCC_PATH)/arm-none-eabi/newlib --specs=nosys.specs

APP_ASFLAGS  := -DAPP_ASFLAG
CORE_ASFLAGS := -DCORE_ASFLAG

APP_CFLAGS   := -DAPP_CFLAG
CORE_CFLAGS  := -DCORE_CFLAG

CFLAGS       += -fomit-frame-pointer -mfloat-abi=softfp
DIR_CMXX := $(DIR_SRC)/portable/GCC/ARM_CM4F

ifeq ($(load_type),flash)
CFLAGS += -DAPP_FLASH
endif

# GCC related includes
INCLUDES := -I$(GCC_PATH)/arm-none-eabi/include

###############################################################################
# List of the common source files
###############################################################################

# List of core files
SRC_CORE_C := $(DIR_CMXX)/port.c $(DIR_SRC)/list.c $(DIR_SRC)/queue.c
SRC_CORE_C += $(DIR_SRC)/tasks.c $(DIR_SRC)/timers.c

# List of application files
SRC_APP_ASM += $(DIR_COMPILER)/$(compiler)/$(platform)_crt0.s

SRC_APP_C += $(DIR_CPU)/$(CPU_file_name).c $(DIR_CPU)/start.c
SRC_APP_C += $(DIR_CPU)/$(platform)_vectors.c
SRC_APP_C += $(DIR_COMMON)/startup.c $(DIR_MEM)/heap_2.c
SRC_APP_C += $(DIR_WDOG)/wdog.c

###############################################################################
# List of the specific application files
###############################################################################

ifeq ($(mode),full)

ifeq ($(load_type),ram)
$(error The full demo can't be run from RAM)
endif

SRC_APP_C += ParTest.c
SRC_APP_C += $(DIR_MIN)/BlockQ.c $(DIR_MIN)/PollQ.c $(DIR_MIN)/semtest.c
SRC_APP_C += $(DIR_MIN)/blocktim.c $(DIR_MIN)/countsem.c $(DIR_MIN)/GenQTest.c
SRC_APP_C += $(DIR_MIN)/QPeek.c $(DIR_MIN)/recmutex.c $(DIR_MIN)/TimerDemo.c
SRC_APP_C += $(DIR_MIN)/death.c $(DIR_MIN)/dynamic.c
SRC_APP_C += main-full.c

else

SRC_APP_C += main_blinky.c

endif

# List of the objects files to be compiled/assembled
OBJECTS_CORE_ASM := $(SRC_CORE_ASM:.s=.o)
OBJECTS_CORE_C   := $(SRC_CORE_C:.c=.o)
OBJECTS_CORE     := $(OBJECTS_CORE_ASM) $(OBJECTS_CORE_C)

OBJECTS_APP_ASM  := $(SRC_APP_ASM:.s=.o)
OBJECTS_APP_C    := $(SRC_APP_C:.c=.o)
OBJECTS_APP      := $(OBJECTS_APP_ASM) $(OBJECTS_APP_C)

OBJECTS          := $(OBJECTS_CORE) $(OBJECTS_APP)

# Project related includes
INCLUDES += -I.
INCLUDES += -I../Common/include
INCLUDES += -I$(DIR_SRC)/include
INCLUDES += -I$(DIR_CMXX)
INCLUDES += -I$(DIR_COMMON)
INCLUDES += -I$(DIR_CPU)
INCLUDES += -I$(DIR_WDOG)
INCLUDES += -I$(DIR_PLATFORM)
INCLUDES += -I$(DIR_COMPILER)/$(compiler)

###############################################################################

# Functions

define get_cflags
$(if $(filter $1,$(SRC_CORE_C)),$(CORE_CFLAGS),$(APP_CFLAGS))
endef

define get_asflags
$(if $(filter $1,$(SRC_CORE_ASM)),$(CORE_ASFLAGS),$(APP_ASFLAGS))
endef

###############################################################################

.PHONY: clean core app $(BAT)

all: $(EXE) $(BAT)

$(EXE): core app
	$(LINK) $(OBJECTS) $(LDFLAGS) -o $(EXE)

core: $(OBJECTS_CORE_ASM) $(OBJECTS_CORE_C)

app: $(OBJECTS_APP_ASM) $(OBJECTS_APP_C)

.c.o:
	$(info $file)
	$(CC) $(CFLAGS) $(call get_cflags,$^) $(INCLUDES) $^ -o $@

.s.o:
	$(info $file)
	$(ASM) $(ASFLAGS) $(call get_asflags,$^) $(INCLUDES) $^ -o $@

$(BAT):
	@ECHO Make BAT file $@
	@ECHO 'if not defined $(EXPECT_DBG) goto defaultDBG'                                                                              > $@
	@ECHO 'set DBG_PATH=%$(EXPECT_DBG)%'                                                                                             >> $@
	@ECHO 'goto startDBG'                                                                                                            >> $@
	@ECHO ':defaultDBG'                                                                                                              >> $@
	@ECHO 'set DBG_PATH=$(DBGDIR)'                                                                                                   >> $@
	@ECHO ':startDBG'                                                                                                                >> $@
	@ECHO 'start %DBG_PATH%/$(DBGEXE_RELPATH) -c %DBG_PATH%/config.t32,$(CMM) $(load_type) $(shell cygpath -w -a $(abspath $(EXE)))' >> $@
	@CHMOD +rwx $@

clean:
	rm -f $(OBJECTS) $(EXE) $(MAP) $(BAT)
