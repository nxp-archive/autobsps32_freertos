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
    EXPORT __startup
    EXTERN __vector_table
    EXTERN __StackLimit

VTOR_REG EQU 0xE000ED08

__startup

    LDR     r0,=0                   ; Initialize the GPRs
    LDR     r1,=0
    LDR     r2,=0
    LDR     r3,=0
    LDR     r4,=0
    LDR     r5,=0
    LDR     r6,=0
    LDR     r7,=0
    MOV     r8,r7
    MOV     r9,r7
    MOV     r10,r7
    MOV     r11,r7
    MOV     r12,r7

    LDR     r0, =__StackLimit
    MOV     r13,r0
    LDR     r0,=0
    /* Relocate vector table to RAM */
    LDR  r0, =VTOR_REG
    LDR  r1, =__vector_table
    STR  r1,[r0]

        import start
        BL      start                  ; call the C code
__done
        B       __done


        END
