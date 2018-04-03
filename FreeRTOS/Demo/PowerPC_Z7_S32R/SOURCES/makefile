
#  Copyright 2018 NXP


TEST_NAME := DEMO

#force dynamic test

include ../SOURCES_HARDWARE/platform.mk
include ../SOURCES_BOOT/boot.mk
include ../compiler_options.mk
include ../freeRTOS.mk


# test generic files
OBJFILES := $(OBJFILES_OS) $(OBJFILES_PLATFORM) $(OBJFILES_BOOT) $(OBJFILES_APPL) $(OBJFILES_HEAP)

# test specific files
OBJFILES +=  $(OUT_ROOT)/obj/$(TEST_NAME)/main.o

# default goal
all: $(OUT_ROOT)/$(TEST_NAME).elf

# Compiling
$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ./%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $<

# Assembling
$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ./%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $<

# Linking
$(OUT_ROOT)/$(TEST_NAME).elf: $(OBJFILES)
	$(LD) $(LDFLAGS) -Xlinker -o -Xlinker $(shell cygpath -m -i $@) $(shell cygpath -m -i $(OBJFILES))

