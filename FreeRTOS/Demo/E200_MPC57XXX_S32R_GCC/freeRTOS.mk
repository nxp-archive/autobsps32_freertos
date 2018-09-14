#
#  Copyright 2018 NXP
#

OBJFILES_OS  := $(OUT_ROOT)/obj/$(TEST_NAME)/tasks.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/timers.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/event_groups.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/queue.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/list.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/croutine.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/port.o \
				$(OUT_ROOT)/obj/$(TEST_NAME)/portasm.o

include ../heap.mk

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OS_ROOT)/Source/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OS_ROOT)/Source/portable/GCC/PowerPC/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OUT_ROOT)/obj/$(TEST_NAME)/%.s
	$(AS) $(ASFLAGS) -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.s: $(OS_ROOT)/Source/portable/GCC/PowerPC/%.s
	$(CPP) $(CPPFLAGS) -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)
