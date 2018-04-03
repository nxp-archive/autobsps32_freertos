
#  Copyright 2018 NXP

OBJFILES_BOOT := $(OUT_ROOT)/obj/$(TEST_NAME)/startup.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/cbootstrap.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/handlers.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../SOURCES_BOOT/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $<

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../SOURCES_BOOT/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $<