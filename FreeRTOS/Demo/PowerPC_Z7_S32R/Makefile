
#  Copyright 2018 NXP

# Include user-specific paths to various tools
# include user_paths.mk

# Include path to bash utils
# include tools.mk

CRT_DIR := $(shell pwd)

ifndef OUT_DIR
	OUT_DIR := $(CRT_DIR)
else
	OUT_DIR := $(shell cygpath -u -i $(OUT_DIR))
endif
OUT_ROOT:=$(OUT_DIR)/OUT

$(if $(S32DS_PPC_PATH),,$(error Path to Compiler's bin directory is not. Please define S32DS_PPC_PATH in your computer's environment and try again))
# convert paths to unix
COMPILER_ROOTDIR := $(shell cygpath -u -i $(S32DS_PPC_PATH)/Cross_Tools/powerpc-eabivle-4_9/bin/)
COMPILER_LIBS := $(shell cygpath -u -i $(S32DS_PPC_PATH)/S32DS/e200_ewl2/)
LAUTERBACH_PATH := $(shell cygpath -u -i $(T32SYS_PPC))
OS_ROOT := $(CRT_DIR)/../../

AS		:= $(COMPILER_ROOTDIR)powerpc-eabivle-as.exe
CC		:= $(COMPILER_ROOTDIR)powerpc-eabivle-gcc.exe
LD		:= $(COMPILER_ROOTDIR)powerpc-eabivle-gcc.exe
CPP		:= $(COMPILER_ROOTDIR)powerpc-eabivle-cpp.exe



ifndef PLATFORM
	PLATFORM ?= s32r372
endif

export COMPILER_ROOTDIR
export COMPILER_LIBS
export LAUTERBACH_PATH

export OS_ROOT

export AS
export CC
export LD
export CPP
export PLATFORM
export OUT_ROOT
export CRT_DIR
export CYGPATH

all: OUT_DIR_CREATE DEMO

clean:
	rm -rf $(OUT_ROOT)

OUT_DIR_CREATE:
	echo using platform: $(PLATFORM)
	rm -fr $(OUT_ROOT)
	mkdir -p $(OUT_ROOT)
	mkdir $(OUT_ROOT)/obj

DEMO: OUT_DIR_CREATE
	mkdir -p $(OUT_ROOT)/obj/DEMO
	make -C src_demo
