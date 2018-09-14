#
# Copyright 2018 NXP
#

# Project output file name
PROJECT := RTOSDemo
EXE     := $(PROJECT).elf
MAP     := $(PROJECT).map

# Defaul compiler
compiler := gcc

# List of compiler
compiler_list := gcc

# Compiler checking
ifneq ($(filter $(compiler),$(compiler_list)), $(compiler))
$(error Undefine compiler $(compiler), should use one of $(compiler_list))
endif

# Common directory
DIR_COMMON      := COMMON
DIR_LINKER      := LINKER_SCRIPTS/$(compiler)
DIR_SOURCES     := SOURCES
DIR_SOURCES_BOOT:= SOURCES_BOOT/$(compiler)
DIR_SOURCES_HW  := SOURCES_HW
DIR_T32_SCRIPT  := T32_S32V234
DIR_OS          := ../../Source
DIR_MEM         := $(DIR_OS)/portable/MemMang

# Please edit path to Lauterbach Trace32 software if necessary
EXPECT_DBG   := LAUTERBACH_PATH
DBGDIR       := $(subst \,/,$($(EXPECT_DBG)))

# T32 binary path related variables
T32_HOSTOS   := windows64
T32EXE       := t32marm

# t32m* relative path in the $(LAUTERBACH_PATH) tree
DBGEXE_RELPATH := bin/$(T32_HOSTOS)/$(T32EXE)

PLATFORM       := S32V234
BAT            := START.bat
CMM            := $(DIR_T32_SCRIPT)/$(PLATFORM).cmm


###############################################################################
# Please replace APP_CFLAG CORE_CFLAG APP_ASFLAG CORE_ASFLAG
# with the flags needed for your project
###############################################################################

###############################################################################
# IAR compiler settings
###############################################################################

ifeq ($(compiler),iar)

ifndef IARARM_TOOLCHAIN_PATH
$(error IARARM_TOOLCHAIN_PATH is not set, that must be set in environment variable)
endif
# Environment variable IARARM_TOOLCHAIN_PATH must be set
# Spaces are not allowed in the path
IAR_PATH := $(subst \,/,$(IARARM_TOOLCHAIN_PATH))


# IAR specific directory and .s file
DIR_CM4F     := $(DIR_OS)/portable/IAR/ARM_CM4F
SRC_CORE_ASM := $(DIR_CM4F)/portasm.s

# Compiler/Assembler/Linker Paths
CC   := $(IAR_PATH)/arm/bin/iccarm
ASM  := $(IAR_PATH)/arm/bin/iasmarm
LINK := $(IAR_PATH)/arm/bin/ilinkarm

# Assemble/compile/link flags
ASFLAGS      := --cpu Cortex-M4F --cpu_mode thumb -g
APP_ASFLAGS  := -DAPP_ASFLAG
CORE_ASFLAGS := -DCORE_ASFLAG

CFLAGS       := -On -e --cpu=Cortex-M4F --thumb --no_wrap_diagnostics --debug
CFLAGS       += -D$(PLATFORM) -DIAR --no_system_include
APP_CFLAGS   := -DAPP_CFLAG
CORE_CFLAGS  := -DCORE_CFLAG

LDFLAGS      := --no_wrap_diagnostics --skip_dynamic_initialization
LDFLAGS      += -L $(IAR_PATH)/arm/lib --map $(MAP)
LDFLAGS      += --config $(DIR_LINKER)/iar_ram.icf

LDFLAGS += --entry __startup

# IAR related includes
INCLUDES := -I$(IAR_PATH)/arm/inc
INCLUDES += -I$(IAR_PATH)/arm/inc/c

endif

ifeq ($(compiler),gcc)

# Environment variable GCCARM_TOOLCHAIN_PATH must be set
# Spaces are not allowed in the path

ifndef GCCARM_TOOLCHAIN_PATH
$(error GCCARM_TOOLCHAIN_PATH is not set, that must be set in environment variable)
endif

GCC_PATH := $(subst \,/,$(GCCARM_TOOLCHAIN_PATH))

# GCC specific directory
DIR_CM4F := $(DIR_OS)/portable/GCC/ARM_CM4F

# Compiler/Assembler/Linker paths
CC   := $(GCC_PATH)/bin/arm-none-eabi-gcc
ASM  := $(GCC_PATH)/bin/arm-none-eabi-gcc
LINK := $(GCC_PATH)/bin/arm-none-eabi-gcc

# Assemble/Compile/Link flags
ASFLAGS      := -x assembler-with-cpp -mcpu=cortex-m4 -mthumb -c
ASFLAGS      += -g3 -gdwarf-2 -nostdlib
APP_ASFLAGS  := -DAPP_ASFLAG
CORE_ASFLAGS := -DCORE_ASFLAG

CFLAGS       :=  -Os -Wall -c -fmessage-length=0 -fplan9-extensions
CFLAGS       += -fomit-frame-pointer -mfloat-abi=softfp
CFLAGS       += -mcpu=cortex-m4 -g3 -mthumb 
CFLAGS       += -D$(PLATFORM) -DGCC
APP_CFLAGS   := -DAPP_CFLAG
CORE_CFLAGS  := -DCORE_CFLAG

LDFLAGS      := -gdwarf-2 -mcpu=cortex-m4 -g3 -mthumb --entry __startup
LDFLAGS      += -Wl,-Map,$(MAP) -specs=nosys.specs
LDFLAGS      += --sysroot=$(GCC_PATH)/arm-none-eabi/newlib
LDFLAGS      += -T$(DIR_LINKER)/gcc_ram.ld


# GCC related includes
INCLUDES := -I$(GCC_PATH)/arm-none-eabi/include

endif

###############################################################################
# List of the common source files
###############################################################################

# List of core files
SRC_CORE_C := $(DIR_CM4F)/port.c \
              $(DIR_OS)/list.c  \
              $(DIR_OS)/queue.c \
              $(DIR_OS)/tasks.c \
              $(DIR_OS)/timers.c

# List of application files
SRC_APP_ASM += $(DIR_SOURCES_BOOT)/crt0.s

SRC_APP_C += $(DIR_SOURCES_HW)/arm_cm4.c \
             $(DIR_SOURCES_HW)/start.c \
             $(DIR_SOURCES_HW)/sysinit.c \
             $(DIR_SOURCES_HW)/vectors.c \
             $(DIR_COMMON)/startup.c \
             $(DIR_MEM)/heap_2.c


###############################################################################
# List of the specific application files
###############################################################################

SRC_APP_C += $(DIR_SOURCES)/main.c

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
INCLUDES += -I$(DIR_OS)/include
INCLUDES += -I$(DIR_CM4F)
INCLUDES += -I$(DIR_COMMON)
INCLUDES += -I$(DIR_SOURCES)
INCLUDES += -I$(DIR_SOURCES_HW)
INCLUDES += -I$(DIR_SOURCES_HW)/platform
INCLUDES += -I$(DIR_SOURCES_BOOT)

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
	$(CC) $(CFLAGS) $(call get_cflags,$^) $(INCLUDES) $^ -o $@

.s.o:
	$(ASM) $(ASFLAGS) $(call get_asflags,$^) $^ -o $@

$(BAT):
	@ECHO Make BAT file $@
	@ECHO 'if not defined $(EXPECT_DBG) goto defaultDBG'                                                                              > $@
	@ECHO 'set DBG_PATH=%$(EXPECT_DBG)%'                                                                                             >> $@
	@ECHO 'goto startDBG'                                                                                                            >> $@
	@ECHO ':defaultDBG'                                                                                                              >> $@
	@ECHO 'set DBG_PATH=$(DBGDIR)'                                                                                                   >> $@
	@ECHO ':startDBG'                                                                                                                >> $@
	@ECHO 'start %DBG_PATH%/$(DBGEXE_RELPATH) -c %DBG_PATH%/config.t32,$(CMM) $(shell cygpath -w -a $(abspath $(EXE)))' >> $@
	@CHMOD +rwx $@

clean:
	rm -f $(OBJECTS) $(EXE) $(MAP) $(BAT)