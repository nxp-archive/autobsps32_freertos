************************************************************************************
Demo application for FreeRTOS V9.0.0 on MPC574xx platforms.
************************************************************************************

This package contains a demo application for FreeRTOS V9.0.0 running on MPC5746C, MPC5748G, MPC5744P, S32R274.

1. Require:

    Cygwin and GNU make
    Cross compiler:
        - powerpc-eabivle-gcc.exe (GCC) 4.9.2 20141030 (Thu Sep 1 11:41:30 MSK 2016 build.sh rev= ELvle)
    Lauterbach T32

2. How to build and run demo:
    - Edit the user_path file, fill path of require software
    - Use 'make PLATFORM=mpc5746c' or 'make PLATFORM=mpc5748g' or 'make PLATFORM=mpc5744p' or 'make PLATFORM=s32r274'
    - Run T32_<platform>/start.bat

3. The directory structure is as follows:

./:
    LINKERSCRIPTS               ; Linker scripts
    SOURCES                     ; Generic source code
    SOURCES_BOOT                ; Source code of boot
    SOURCES_MPC57XX             ; Hardware source code
    T32_Calypso3M               ; Trace32 folder for MPC5746C
    T32_Calypso6M               ; Trace32 folder for MPC5748G
    T32_Panther                 ; Trace32 folder for MPC5744P
    T32_RaceRunner_Ultra        ; Trace32 folder for S32R274
    appl_common.mk              ; Make common
    compiler_options.mk         ; Define compiler options
    freeRTOS.mk                 ; Make freeRTOS
    heap.mk                     ; Make head
    Makefile                    ; Demo application make file
    readme.txt                  ; This file
    user_paths.mk               ; Define the path of the user

./LINKERSCRIPTS:
    flash_mpc5744p.ld           ; Demo linker script for MPC5744P
    flash_mpc5746c.ld           ; Demo linker script for MPC5746C
    flash_mpc5748g.ld           ; Demo linker script for MPC5748G
    flash_s32r274.ld            ; Demo linker script for S32R274

./SOURCES:
    FreeRTOSConfig.h            ; FreeRTOS configuration file
    IntQueueTimer.h             ; Initialization queue
    main.c                      ; Main demo application file
    main_full.c                 ; Main demo application file
    makefile                    ; Demo application make file
    reg_test.s                  ; Test register

./SOURCES_BOOT:
    boot.mk                     ; Make boot
    cbootstrap.c                ; C bootstrap source code
    crt0.s                      ; Demo startup code
    handlers.s                  ; Hardware interrupts handlers
    startup.s                   ; Startup code

./SOURCES_MPC57XX:
    mpc5744p                    ; Specific source code
    mpc5746c                    ; Specific source code
    mpc5748g                    ; Specific source code
    s32r274                     ; Specific source code
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

./mpc5744p
    cpudefs.h                   ; Specific definition

./mpc5746c
    cpudefs.h                   ; Specific definition

./mpc5748g
    cpudefs.h                   ; Specific definition

./s32r274
    cpudefs.h                   ; Specific definition

./T32_Calypso3M:
    5746c.cmm                   ; Calypso specific CMM file
    config.t32                  ; T32 support file
    flash.cmm                   ; CMM file to program flash
    start.bat                   ; BAT file to start the application

./T32_Calypso6M:
    5748g.cmm                   ; Calypso specific CMM file
    config.t32                  ; T32 support file
    flash.cmm                   ; CMM file to program flash
    start.bat                   ; BAT file to start the application

./T32_Panther:
    5744p.cmm                   ; Panther specific CMM file
    config.t32                  ; T32 support file
    flash.cmm                   ; CMM file to program flash
    start.bat                   ; BAT file to start the application

./T32_RaceRunner_Ultra:
    s32r274.cmm                 ; RaceRunner Ultra specific CMM file
    config.t32                  ; T32 support file
    flash.cmm                   ; CMM file to program flash
    start.bat                   ; BAT file to start the application
