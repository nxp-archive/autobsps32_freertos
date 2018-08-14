#
#  Copyright 2018 NXP
#

OBJFILES_SPECIFIC += $(OUT_ROOT)/obj/$(TEST_NAME)/startup.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/handlers.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../specific/$(PLATFORM)/src_boot/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $<

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../specific/$(PLATFORM)/src_boot/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $<
