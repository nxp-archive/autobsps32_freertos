
#  Copyright 2018 NXP

PLATFORM_DEF := $(shell echo $(PLATFORM) | tr a-z A-Z)

ASFLAGS  :=  -g --gdwarf-sections --gstabs+ -L -mregnames -mvle -I$(shell cygpath -m -i $(CRT_DIR))/SOURCES -I$(shell cygpath -m -i $(CRT_DIR))/SOURCES_HARDWARE/$(PLATFORM) \
			 -I$(shell cygpath -m -i $(OS_ROOT))/Source/portable/GCC/PowerPC

CPPFLAGS  := -g -L -mregnames -mvle -I$(shell cygpath -m -i $(CRT_DIR))/SOURCES -I$(shell cygpath -m -i $(CRT_DIR))/SOURCES_HARDWARE/$(PLATFORM) \
			 -I$(shell cygpath -m -i $(OS_ROOT))/Source/portable/GCC/PowerPC \
			 -D$(PLATFORM_DEF)=1


CFLAGS   :=  --sysroot=$(shell cygpath -m -i $(COMPILER_LIBS)) \
			-I$(shell cygpath -m -i $(OS_ROOT))/Source/include \
			-I$(shell cygpath -m -i $(OS_ROOT))/Source/portable/GCC/PowerPC \
			-I$(shell cygpath -m -i $(CRT_DIR))/SOURCES \
			-I$(shell cygpath -m -i $(CRT_DIR))/SOURCES_HARDWARE \
			-I$(shell cygpath -m -i $(CRT_DIR))/SOURCES_HARDWARE/$(PLATFORM)\
			-mcpu=e200z7 -mfpu=sp_full -mvle -mfloat-gprs=yes -mhard-float -static \
			-O3 -g3 -fno-strict-aliasing -Wall -Wextra -Werror -Wdouble-promotion -Wfloat-equal \
			-Wconversion -Wpointer-arith -std=gnu99 -ffunction-sections -fdata-sections \
			-D$(PLATFORM_DEF)=1

CFLAGS +=   -DTEST_DYNAMIC=1 -DconfigSUPPORT_STATIC_ALLOCATION=0 -DconfigSUPPORT_DYNAMIC_ALLOCATION=1

LDFLAGS :=  --sysroot=$(shell cygpath -m -i $(COMPILER_LIBS)) -mcpu=e200z7 -mfpu=sp_full -Xlinker -Map=$(shell cygpath -m -i $(OUT_ROOT)/$(TEST_NAME).map) \
			-nostartfiles -T$(shell cygpath -m -i $(CRT_DIR))/LINKERSCRIPTS/flash_$(PLATFORM).ld -static -Xlinker --gc-sections -Xlinker --print-gc-sections
