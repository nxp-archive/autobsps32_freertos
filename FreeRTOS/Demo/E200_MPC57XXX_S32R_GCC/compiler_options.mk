#
#  Copyright 2018 NXP
#

PLATFORM_DEF := $(shell echo $(MCU) | tr a-z A-Z)

ASFLAGS  := -g --gdwarf-sections --gstabs+ -L -mregnames -mvle \
            -I$(shell cygpath -m -i $(CRT_DIR))/specific/$(MCU)/inc \
            -I$(shell cygpath -m -i $(CRT_DIR))/generic/inc \
            -I$(shell cygpath -m -i $(OS_ROOT))/Source/portable/GCC/PowerPC

CPPFLAGS  := -g -L -mregnames -mvle \
            -I$(shell cygpath -m -i $(CRT_DIR))/specific/$(MCU)/inc \
            -I$(shell cygpath -m -i $(CRT_DIR))/generic/inc \
            -I$(shell cygpath -m -i $(OS_ROOT))/Source/portable/GCC/PowerPC \
            -DCPU_$(PLATFORM_DEF) -DCORE_ID=$(core_id)

CFLAGS   :=  --sysroot=$(shell cygpath -m -i $(COMPILER_LIBS)) \
            -I$(shell cygpath -m -i $(OS_ROOT))/Source/include \
            -I$(shell cygpath -m -i $(OS_ROOT))/Source/portable/GCC/PowerPC \
            -I$(shell cygpath -m -i $(CRT_DIR))/specific/$(MCU)/inc \
            -I$(shell cygpath -m -i $(CRT_DIR))/generic/inc \
            -mcpu=$(CPU) -mfpu=sp_full -mvle -mfloat-gprs=yes -mhard-float -static \
            -O3 -g3 -fno-strict-aliasing -Wall -Wextra -Werror -Wdouble-promotion -Wfloat-equal \
            -Wconversion -Wpointer-arith -std=gnu99 -ffunction-sections -fdata-sections \
            -DCPU_$(PLATFORM_DEF)=1 -DCORE_ID=$(core_id)

ifeq ($(core_master),1)
CPPFLAGS += -DCORE_MASTER
CFLAGS += -DCORE_MASTER
else
CPPFLAGS += -DCORE_SLAVE
CFLAGS += -DCORE_SLAVE
endif

CFLAGS +=   -DTEST_DYNAMIC=1 -DconfigSUPPORT_STATIC_ALLOCATION=0 -DconfigSUPPORT_DYNAMIC_ALLOCATION=1

LDFLAGS :=  --sysroot=$(shell cygpath -m -i $(COMPILER_LIBS)) -mcpu=$(CPU) -mfpu=sp_full -Xlinker -Map=$(shell cygpath -m -i $(OUT_ROOT)/$(TEST_NAME).map) \
            -nostartfiles -T$(shell cygpath -m -i $(CRT_DIR))/specific/$(MCU)/linker/flash_$(MCU).ld -static -Xlinker --gc-sections -Xlinker --print-gc-sections
