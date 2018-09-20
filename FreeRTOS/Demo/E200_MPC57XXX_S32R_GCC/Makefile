#
#  Copyright 2018 NXP
#

CRT_DIR := $(shell pwd)

ifndef OUT_DIR
	OUT_DIR := $(CRT_DIR)
else
	OUT_DIR := $(subst \\,/,$(OUT_DIR))
endif
OUT_ROOT:=$(OUT_DIR)/OUT

$(if $(S32DS_PPC_PATH),,$(error Path to Compiler's directory not found.\
                          Please define S32DS_PPC_PATH in your computer's environment and try again))
# convert paths to unix
COMPILER_ROOTDIR := $(subst \\,/,$(S32DS_PPC_PATH)/Cross_Tools/powerpc-eabivle-4_9/bin/)
COMPILER_LIBS := $(subst \\,/,$(S32DS_PPC_PATH)/S32DS/e200_ewl2/)
LAUTERBACH_PATH := $(subst \\,/,$(T32SYS_PPC))
OS_ROOT := $(CRT_DIR)/../../

AS		:= $(COMPILER_ROOTDIR)powerpc-eabivle-as.exe
CC		:= $(COMPILER_ROOTDIR)powerpc-eabivle-gcc.exe
LD		:= $(COMPILER_ROOTDIR)powerpc-eabivle-gcc.exe
CPP		:= $(COMPILER_ROOTDIR)powerpc-eabivle-cpp.exe


ifndef PLATFORM
PLATFORM ?= s32r274_z4a
endif

$(if $($(findstring _,$(PLATFORM))),,$(error Format of PLATFORM parameter is not match.\
                                       PLATFORM use format "MCU_CORE" 'eg. s32r274_z4a'))

CPU := e200$(shell echo $(word 2,$(subst _, ,$(PLATFORM))) | grep -o "z[0-9]")
CORE := $(word 2,$(subst _, ,$(PLATFORM)))
MCU := $(word 1,$(subst _, ,$(PLATFORM)))

export MCU
export CORE
export CPU

include devices_list.mk

export COMPILER_ROOTDIR
export COMPILER_LIBS
export LAUTERBACH_PATH
export OS_ROOT

export AS
export CC
export LD
export CPP
export OUT_ROOT
export CRT_DIR
export CYGPATH


START_BAT_PATH := specific/$(MCU)/t32/startup.bat

all: OUT_DIR_CREATE DEMO

clean:
	rm -rf $(OUT_ROOT) $(START_BAT_PATH)

test: OUT_DIR_CREATE DEMO
	$(if $(T32SYS_PPC),,$(error Path to Lauterbach's directory not found.\
                          Please define T32SYS_PPC in your computer's environment and try again,\
                          or you can set T32_PATH in ./T32_$(MCU)/startup.bat file then run it))
	@cd $(dir $(START_BAT_PATH)) && ./$(notdir startup.bat)

PRINT:
	@echo $(CPU)
	@echo $(MCU)

OUT_DIR_CREATE:
	echo using platform: $(MCU) $(CORE)--$(CPU)
	rm -fr $(OUT_ROOT)
	mkdir -p $(OUT_ROOT)
	mkdir $(OUT_ROOT)/obj

DEMO: OUT_DIR_CREATE START_BAT_FILE
	mkdir -p $(OUT_ROOT)/obj/DEMO
	make -C src_demo

START_BAT_FILE:
	@echo "REM" > $(START_BAT_PATH)
	@echo "REM eg. T32_PATH=C:\T32" >> $(START_BAT_PATH)
	@echo "REM" >> $(START_BAT_PATH)
	@echo "" >> $(START_BAT_PATH)
	@echo "SET T32_PATH= $(subst /,\\,$(LAUTERBACH_PATH))" >> $(START_BAT_PATH)
	@echo "start %T32_PATH%\bin\windows64\t32mppc.exe -c .\config.t32,$(MCU)_core_$(CORE).cmm 20001 $(CPU) USB CORE=1 %T32_PATH%" >> $(START_BAT_PATH)
