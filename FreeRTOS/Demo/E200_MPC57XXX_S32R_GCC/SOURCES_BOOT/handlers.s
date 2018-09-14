/*
*   Copyright 2018 NXP
*/

    .section ".core_exceptions_table","ax"

    .extern vPortISRHandler
    .extern xPortSyscall


    .align 4
CI_ESR:
    e_li r0, 0x0
    e_b __generic_exception_handler

    .align 4
MC_ESR:
    e_li r0, 0x1
    e_b __generic_exception_handler

    .align 4
DS_ESR:
    e_li r0, 0x2
    e_b __generic_exception_handler

    .align 4
IS_ESR:
    e_li r0, 0x3
    e_b __generic_exception_handler

    .align 4
EI_ESR:
    e_b vPortISRHandler

    .align 4
Align_ESR:
    e_li r0, 0x5
    e_b __generic_exception_handler

    .align 4
Program_ESR:
    e_li r0, 0x6
    e_b __generic_exception_handler

    .align 4
FP_Unav_ESR:
    e_li r0, 0x7
    e_b __generic_exception_handler

    .align 4
SC_ESR:
    e_b xPortSyscall

    .align 4
AP_Unav_ESR:
    e_li r0, 0x9
    e_b __generic_exception_handler

    .align 4
DEC_ESR:
    e_li r0, 0xA
    e_b __generic_exception_handler

    .align 4
FIT_ESR:
    e_li r0, 0xB
    e_b __generic_exception_handler

    .align 4
WDT_ESR:
    e_li r0, 0xC
    e_b __generic_exception_handler

    .align 4
DTLB_error_ESR:
    e_li r0, 0xD
    e_b __generic_exception_handler

    .align 4
ITLB_error_ESR:
    e_li r0, 0xE
    e_b __generic_exception_handler

    .align 4
Debug_ESR:
    e_li r0, 0xF
    e_b __generic_exception_handler

    .align 4
__generic_exception_handler:

  e_b __generic_exception_handler


    .end
