#
#  Copyright 2018 NXP
#

OBJFILES_SPECIFIC += $(OUT_ROOT)/obj/$(TEST_NAME)/hw_platform.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/hw_flashrchw.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../specific/$(PLATFORM)/src_hw/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $<

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../specific/$(PLATFORM)/src_hw/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $<
