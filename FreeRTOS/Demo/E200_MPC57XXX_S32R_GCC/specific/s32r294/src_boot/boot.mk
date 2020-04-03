#
#  Copyright 2020 NXP
#

OBJFILES_BOOT := $(OUT_ROOT)/obj/$(TEST_NAME)/coreMasterStartup.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/coreSlaveStartup.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/cbootstrap.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/handlers.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/initcore.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../specific/$(MCU)/src_boot/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OUT_ROOT)/obj/$(TEST_NAME)/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.s: ../specific/$(MCU)/src_boot/%.s
	$(CPP) $(CPPFLAGS) -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)
