#cluster selection
CLUSTER := 
cluster := cluster0
ifeq ($(cluster),cluster0)
CLUSTER += -DCLUSTER0
endif
ifeq ($(cluster),cluster1)
CLUSTER += -DCLUSTER1
endif

#compiler flags for specific board
BOARDFLAG := 
board := vdk
ifeq ($(board),vdk)
BOARDFLAG += -DOS_FOR_VDK 
endif
ifeq ($(board),fpga)
BOARDFLAG += -DOS_FOR_FPGA 
endif
#Path to Tool Directory
CrossToolDir ?= C:/tools/gcc-6.3-arm32-eabi
#Path to FreeRtos Directory
OsPath ?= ../..
OutDir := Output


AS := $(CrossToolDir)/bin/arm-none-eabi-as.exe
CC := $(CrossToolDir)/bin/arm-none-eabi-gcc.exe
LD := $(CrossToolDir)/bin/arm-none-eabi-ld.exe

OSCFLAGS := -g -O3 -mcpu=cortex-r52 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -Wall \
			-I"$(OsPath)/Source/include" -I"$(OsPath)/Source/portable/GCC/ARM_CR52_GIC" \
			-I"include" $(BOARDFLAG) $(CLUSTER)
OSASFLAGS := -g -mcpu=cortex-r52 -mfpu=fpv5-sp-d16 -mfloat-abi=hard 
LDFLAGS := -nostartfiles -T image.ld -Wl,-Map=$(OutDir)/image.map \
			-L$(CrossToolDir)/arm-none-eabi/newlib/lib/v8-r/fpv5/hard -lc \
			-L$(CrossToolDir)/lib/gcc/arm-none-eabi/6.3.1/v8-r/fpv5/hard -lgcc

OBJFILES_OS := $(OutDir)/tasks.o \
			$(OutDir)/timers.o \
			$(OutDir)/event_groups.o \
			$(OutDir)/queue.o \
			$(OutDir)/list.o \
			$(OutDir)/croutine.o \
			$(OutDir)/port.o \
			$(OutDir)/heap_4.o

$(OutDir)/%.o: $(OsPath)/Source/%.c
	$(CC) $(OSCFLAGS) -c -o $@ $<

$(OutDir)/%.o: $(OsPath)/Source/portable/GCC/ARM_CR52_GIC/%.c
	$(CC) $(OSCFLAGS) -c -o $@ $<

$(OutDir)/%.o: $(OsPath)/Source/portable/MemMang/%.c
	$(CC) $(OSCFLAGS) -c -o $@ $<

OBJFILES_APP := $(OutDir)/vector.o \
				$(OutDir)/startup.o \
				$(OutDir)/hw_system.o \
				$(OutDir)/main.o

$(OutDir)/%.o: source/%.c
	$(CC) $(OSCFLAGS) -c -o $@ $<

$(OutDir)/%.o: source/%.asm
	$(AS) $(OSASFLAGS) -c -o $@ $<

OBJFILES := $(OBJFILES_OS) $(OBJFILES_APP)

# default goal
all: clean make_dir $(OutDir)/image.elf

clean:
	rm -f $(OutDir)/*

make_dir:
	mkdir -p $(OutDir)
# Linking
$(OutDir)/image.elf: $(OBJFILES)
	$(CC) $(LDFLAGS) -o $@ $(OBJFILES)