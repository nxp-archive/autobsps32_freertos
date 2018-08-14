#
#  Copyright 2018 NXP
#

OBJFILES_GENERIC += $(OUT_ROOT)/obj/$(TEST_NAME)/cbootstrap.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../generic/src/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $<

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../generic/src/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $<
