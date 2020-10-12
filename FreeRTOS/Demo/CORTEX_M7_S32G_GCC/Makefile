####################################################################################
 # Copyright 2019, 2020 NXP.
 #
 # Permission is hereby granted, free of charge, to any person obtaining a copy of
 # this software and associated documentation files (the "Software"), to deal in
 # the Software without restriction, including without limitation the rights to
 # use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 # the Software, and to permit persons to whom the Software is furnished to do so,
 # subject to the following conditions:
 #
 # The above copyright notice and this permission notice shall be included in all
 # copies or substantial portions of the Software.
 #
 # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 # IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 # FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 # COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 # IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 # CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 #
####################################################################################
CYGPATH := C:/cygwin64/bin/cygpath.exe
#Path to Tool Directory
CrossToolDir := C:/tools/gcc-6.3-arm32-eabi
#Path to FreeRtos Directory
OsPath := D:/workspace_rtos/freertos-git.freescale.com/FreeRTOS
OutDir := Output


AS := $(CrossToolDir)/bin/arm-none-eabi-as.exe
CC := $(CrossToolDir)/bin/arm-none-eabi-gcc.exe
LD := $(CrossToolDir)/bin/arm-none-eabi-ld.exe

OSCFLAGS := -g -O3 -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -Wall -I"$(OsPath)/Source/include" -I"$(OsPath)/Source/portable/GCC/ARM_CM7/r0p1" -I"include"
OSASFLAGS := -g -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard 
LDFLAGS := -nostartfiles -T image.ld -Wl,-Map=$(OutDir)/image.map -L$(CrossToolDir)/arm-none-eabi/newlib/lib/thumb/v8-m.main/fpv5/hard -lc -L$(CrossToolDir)/lib/gcc/arm-none-eabi/6.3.1/thumb/v8-m.main/fpv5/hard -lgcc

OBJFILES_OS := $(OutDir)/tasks.o \
			   $(OutDir)/timers.o \
			   $(OutDir)/event_groups.o \
			   $(OutDir)/queue.o \
			   $(OutDir)/list.o \
			   $(OutDir)/croutine.o \
			   $(OutDir)/port.o \
			   $(OutDir)/heap_4.o

$(OutDir)/%.o: $(OsPath)/Source/%.c
	$(CC) $(OSCFLAGS) -c -o $(shell $(CYGPATH) -m -i $@) $(shell $(CYGPATH) -m -i $<)

$(OutDir)/%.o: $(OsPath)/Source/portable/GCC/ARM_CM7/r0p1/%.c
	$(CC) $(OSCFLAGS) -c -o $(shell $(CYGPATH) -m -i $@) $(shell $(CYGPATH) -m -i $<)

$(OutDir)/%.o: $(OsPath)/Source/portable/MemMang/%.c
	$(CC) $(OSCFLAGS) -c -o $(shell $(CYGPATH) -m -i $@) $(shell $(CYGPATH) -m -i $<)

OBJFILES_APP := $(OutDir)/vector.o \
                $(OutDir)/startup.o \
				$(OutDir)/hw_system.o \
				$(OutDir)/main.o

$(OutDir)/%.o: source/%.c
	$(CC) $(OSCFLAGS) -c -o $(shell $(CYGPATH) -m -i $@) $(shell $(CYGPATH) -m -i $<)

$(OutDir)/%.o: source/%.asm
	$(AS) $(OSASFLAGS) -c -o $(shell $(CYGPATH) -m -i $@) $(shell $(CYGPATH) -m -i $<)
				
OBJFILES := $(OBJFILES_OS) $(OBJFILES_APP)

# default goal
all: clean make_dir $(OutDir)/image.elf

clean:
	rm -f $(OutDir)/*
	rm -fr $(OutDir)

make_dir:
	mkdir $(OutDir)
# Linking
$(OutDir)/image.elf: $(OBJFILES)
	$(CC) $(LDFLAGS) -o $(shell $(CYGPATH) -m -i $@) $(shell $(CYGPATH) -m -i $(OBJFILES))