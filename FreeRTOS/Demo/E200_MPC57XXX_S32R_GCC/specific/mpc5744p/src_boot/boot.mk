#
#  Copyright 2018 NXP
#

OBJFILES_BOOT := $(OUT_ROOT)/obj/$(TEST_NAME)/coreMasterStartup.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/coreSlaveStartup.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/cbootstrap.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/handlers.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/initcore.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../SOURCES_BOOT/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OUT_ROOT)/obj/$(TEST_NAME)/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.s: ../SOURCES_BOOT/%.s
	$(CPP) $(CPPFLAGS) -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)
