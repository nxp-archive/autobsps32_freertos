/*
 *
 * Copyright 2018 NXP
 *
 * File:    s32k116_crt0.s
 * Purpose: Lowest level routines for Kinetis.
 *
 * Notes:
 *
 */

    .syntax unified
    .arch armv6-m

    .section .startup

    .text
    .thumb

    .equiv VTOR_REG, 0xE000ED08

    .thumb_func
    .align 2
    .globl __startup
    .weak __startup
    .type __startup, %function
__startup:

    ldr     r1,=0x0
    ldr     r2,=0x0
    ldr     r3,=0x0
    ldr     r4,=0x0
    ldr     r5,=0x0
    ldr     r6,=0x0
    ldr     r7,=0x0
    mov     r8,r7
    mov     r9,r7
    mov     r10,r7
    mov     r11,r7
    mov     r12,r7
    /* Init ECC RAM */
    ldr     r2,=__StackLimit
    mov     r13,r2
    ldr     r2,=0x0
    /* Relocate vector table to RAM */
    ldr  r0, =VTOR_REG
    ldr  r1, =__vector_table
    /* ldr  r2, =(1 << 29) */
    /* orr  r1, r2  r1 = r1 | r2 */
    str  r1,[r0]

    bl      start                  /* call the C code */

__done:
    b       __done
