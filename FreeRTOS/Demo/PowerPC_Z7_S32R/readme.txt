************************************************************************************
Demo application for FreeRTOS V9.0.0 on S32R372.
************************************************************************************

This package contains a demo application for FreeRTOS V9.0.0 running on S32R372.

1. Require:

    Cygwin and GNU make
    Cross compiler:
        - powerpc-eabivle-gcc.exe (GCC) 4.9.2 20141030 (Thu Sep 1 11:41:30 MSK 2016 build.sh rev= ELvle)
    Lauterbach T32

2. How to build and run demo:
    - Edit the user_path file, fill path of require software
    - Use 'make PLATFORM=s32r372'
    - Run T32_<platform>/start.bat

3. The directory structure is as follows:

./:
    LINKERSCRIPTS/              ; Linker scripts
    SOURCES/                    ; Generic source code
    SOURCES_BOOT/               ; Source code of boot
    SOURCES_HARDWARE/           ; Hardware source code
    T32_RaceRunner_Skinny/      ; Trace32 folder for RaceRunner Skinny
    appl_common.mk              ; Make common
    compiler_options.mk         ; Define compiler options
    freeRTOS.mk                 ; Make freeRTOS
    heap.mk                     ; Make head
    Makefile                    ; Demo application make file
    readme.txt                  ; This file

./LINKERSCRIPTS:
    flash_s32r372.ld            ; Demo linker script for s32r372

./SOURCES:
    FreeRTOSConfig.h            ; FreeRTOS configuration file
    main.c                      ; Main demo application file
    makefile                    ; Demo application make file

./SOURCES_BOOT:
    boot.mk                     ; Make boot
    cbootstrap.c                ; C bootstrap source code
    handlers.s                  ; Hardware interrupts handlers
    startup.s                   ; Startup code

./SOURCES_HARDWARE:
    s32r372/                    ; Specific source code
    hw_base.h                   ; Platform peripheral base addresses
    hw_clock.h                  ; Platform specific clock support
    hw_flashrchw.c              ; Flash header
    hw_gpio.h                   ; GPIO code
    hw_intc.h                   ; Interrupt controller
    hw_pit.h                    ; PIT timer
    hw_platform.c               ; Platform specific code
    hw_platform.h               ; Platform specific header
    hw_typedefs.h               ; Hardware specific typedefs
    hw_wdg.h                    ; Watchdog code
    platform.mk                 ; make platform

./s32r372
    cpudefs.h                   ; Specific definition

./T32_RaceRunner_Skinny:
    s32r372.cmm                 ; RaceRunner Skinny specific CMM file
    config.t32                  ; T32 support file
    flash.cmm                   ; CMM file to program flash
    start.bat                   ; BAT file to start the application
