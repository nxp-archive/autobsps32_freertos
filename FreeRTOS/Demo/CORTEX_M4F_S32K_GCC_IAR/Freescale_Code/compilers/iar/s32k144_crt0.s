/*
 *
 * Copyright 2018 NXP
 *
 * File:    s32k118_crt0.s
 * Purpose: Lowest level routines for Kinetis.
 *
 * Notes:
 *
 */

;         AREA   Crt0, CODE, READONLY      ; name this block of code


    SECTION .noinit : CODE
    EXPORT  __startup
    EXTERN __vector_table
    EXTERN  __StackLimit

VTOR_REG EQU 0xE000ED08

__startup

    MOV     r0,#0                   ; Initialize the GPRs
    MOV     r1,#0
    MOV     r2,#0
    MOV     r3,#0
    MOV     r4,#0
    MOV     r5,#0
    MOV     r6,#0
    MOV     r7,#0
    MOV     r8,#0
    MOV     r9,#0
    MOV     r10,#0
    MOV     r11,#0
    MOV     r12,#0

    LDR     r13, =__StackLimit

    /* Relocate vector table to RAM */
    LDR  r0, =VTOR_REG
    LDR  r1, =__vector_table
    STR  r1,[r0]

        import start
        BL      start                  ; call the C code
__done
        B       __done


        END
