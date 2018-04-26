#
#  Copyright 2018 NXP
#

CFLAGS += -I$(shell cygpath -m -i $(OS_ROOT))/Demo/Common/include

OBJFILES_APPL := $(OUT_ROOT)/obj/$(TEST_NAME)/dynamic.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/IntQueue.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/BlockQ.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/blocktim.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/GenQTest.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/recmutex.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/death.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/semtest.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/TimerDemo.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/countsem.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/QueueOverwrite.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/EventGroupsDemo.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/TaskNotify.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/IntSemTest.o \
                 $(OUT_ROOT)/obj/$(TEST_NAME)/flop.o

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OS_ROOT)/Demo/Common/Minimal/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)

$(OUT_ROOT)/obj/$(TEST_NAME)/%.o: $(OS_ROOT)/Demo/Common/Full/%.c
	$(CC) $(CFLAGS) -c -o $(shell cygpath -m -i $@) $(shell cygpath -m -i $<)
