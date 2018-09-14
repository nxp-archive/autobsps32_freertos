#
#  Copyright 2018 NXP
#

OBJFILES_PLATFORM  :=  $(OUT_ROOT)/obj/$(TEST_NAME)/hw_flashrchw.o \
                       $(OUT_ROOT)/obj/$(TEST_NAME)/hw_platform.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../SOURCES_HARDWARE/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $<

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: ../SOURCES_HARDWARE/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $<
