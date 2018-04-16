#==================================================================================================
#
#  (c) Copyright 2015 Freescale Semiconductor Inc.
#  Copyright 2017-2018 NXP
#  
#  This program is free software; you can redistribute it and/or modify it under
#  the terms of the GNU General Public License (version 2) as published by the
#  Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.
#
#  ***************************************************************************
#  >>!   NOTE: The modification to the GPL is included to allow you to     !<<
#  >>!   distribute a combined work that includes FreeRTOS without being   !<<
#  >>!   obliged to provide the source code for proprietary components     !<<
#  >>!   outside of the FreeRTOS kernel.                                   !<<
#  ***************************************************************************
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
#================================================================================================*/

# Include user-specific paths to various tools
include user_paths.mk

# Include path to bash utils
include tools.mk

CRT_DIR := $(shell pwd)

ifndef OUT_DIR
	OUT_DIR := $(CRT_DIR)
else
	OUT_DIR := $(shell $(CYGPATH) -u -i $(OUT_DIR))
endif
OUT_ROOT:=$(OUT_DIR)/OUT

# convert paths to unix
COMPILER_ROOTDIR := $(shell $(CYGPATH) -u -i $(COMPILER_ROOTDIR))
COMPILER_LIBS := $(shell $(CYGPATH) -u -i $(COMPILER_LIBS))
OS_ROOT := $(shell $(CYGPATH) -u -i $(OS_ROOT))
LAUTERBACH_PATH := $(shell $(CYGPATH) -u -i $(LAUTERBACH_PATH))

AS		:= $(COMPILER_ROOTDIR)powerpc-eabivle-as.exe
CC		:= $(COMPILER_ROOTDIR)powerpc-eabivle-gcc.exe
LD 		:= $(COMPILER_ROOTDIR)powerpc-eabivle-gcc.exe
CPP		:= $(COMPILER_ROOTDIR)powerpc-eabivle-cpp.exe



ifndef PLATFORM
	PLATFORM := mpc5746c
endif

export COMPILER_ROOTDIR
export COMPILER_LIBS
export LAUTERBACH_PATH

OS_ROOT := $(CRT_DIR)/../../
export OS_ROOT

export AS
export CC
export LD
export CPP
export PLATFORM
export OUT_ROOT
export CRT_DIR
export CYGPATH

all: OUT_DIR_CREATE GEN_001

clean:
	$(RM) -rf $(OUT_ROOT)
	$(FIND) . -name start.bat -exec $(SED) -i 's/T32_PATH=.*/T32_PATH=/' {} \;

OUT_DIR_CREATE:
	$(ECHO) using platform: $(PLATFORM)
	$(RM) -fr $(OUT_ROOT)
	$(MKDIR) -p $(OUT_ROOT)
	$(MKDIR) $(OUT_ROOT)/obj

GEN_001: OUT_DIR_CREATE START_BAT_FILE
	$(MKDIR) -p $(OUT_ROOT)/obj/GEN_001
	$(MAKE) -C SOURCES

START_BAT_FILE:
	$(FIND) . -name start.bat -exec $(SED) -i 's/T32_PATH=.*/T32_PATH=$(subst \,\\,$(shell $(CYGPATH) -w -i -a $(LAUTERBACH_PATH)))/' {} \;
