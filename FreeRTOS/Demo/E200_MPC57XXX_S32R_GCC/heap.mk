#
#  Copyright 2018 NXP
#

OBJFILES_OS += $(OUT_ROOT)/obj/$(TEST_NAME)/heap_4.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OS_ROOT)/Source/portable/MemMang/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)
