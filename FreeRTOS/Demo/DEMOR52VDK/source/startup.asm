/*
 * Copyright 2019 NXP.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

    .extern vPortInterruptDispatcher
    .extern vPortSVCDispatcher
    .extern SystemInit
    .align 5
    .section .startup,"ax"
    .globl Reset_Handler
Reset_Handler:
    /* vector table */
.globl vector_table
vector_table:
    b reset_exception
    .align 2   
    b undefined_exception
    .align 2
    b vPortSVCDispatcher
    .align 2
    b prefetch_exception
    .align 2
    b abort_exception
    .align 2
    nop
    .align 2
    b vPortInterruptDispatcher
    .align 2
    b .                     /* FIQ */

    /* unsupported exceptions */
    .align 2
undefined_exception:
    b .
prefetch_exception:
    b .
abort_exception:
    b .
fiq_exception:
    b .

reset_exception:
    /* ARMv8-R cores are in EL2 (hypervisor mode) after reset, and we need */
    /* to first descend to EL1 (supervisor mode) before the traditional SP */
    /* setting code can be run. */
    /* zeros r0 - r12 */
    eor r0, r0, r0
    eor r1, r1, r1
    eor r2, r2, r2
    eor r3, r3, r3
    eor r4, r4, r4
    eor r5, r5, r5
    eor r6, r6, r6
    eor r7, r7, r7
    mov r8, r0
    mov r9, r0
    mov r10, r0
    mov r11, r0
    mov r12, r0

    ldr r0, =0xffff
    mcr p15, 4, r0, c1, c0, 1       /* Write R0 to HACTLR */
    ldr r0, =e1_code
    msr elr_hyp, r0
    mrs r0, spsr_hyp
    mov r1, #0x1F
    mvn r1, r1
    mov r2, #0x13
#if defined (__thumb__)
    add r2, #0x20                   /* enable thumb mode */
#endif
    and r0, r1                      /* reset mode */
    orr r0, r2                      /* supervisor mode */
    msr spsr_hyp, r0
    eret                            /* jump to e1_code */

e1_code:

    /* set vtor */
    ldr r0, =vector_table
    mcr p15, 0, r0, c12, c0, 0

    /* stack initialization only irq and system processor modes will have a stack */
    /* set irq stack */
    cps #0x12                           /* enter in irq mode, 1KB */
    ldr r0, =(_Stack_start + 4)         /* set irq stack, full */
    mov r13, r0
    cps #0x13                           /* supervisor mode (svc) 2.5KB */
    ldr r0, =(_Stack_start - 0x3fc)     /* set svc stack, full */
    mov r13, r0
    cps #0x1f                           /* system mode (sys) 0.5KB, used by main function */
    ldr r0, =(_Stack_start - 0xdfc)     /* set sys stack, full */
    mov r13, r0

    /** Cache I = 1 << 12, data 1 << 2 */
    mrc p15, 0, r0, c1, c0, 0           /* Read SCTLR into R0 */
    movw r1, #((1 << 12))
    orr r0, r1
    mcr p15, 0, r0, c1, c0, 0            /* Write R0 to SCTLR */

    /* call system initialization first */
    ldr r0, =SystemInit
    blx r0
    /* Zero fill the bss segment */
    ldr  r0, =__bss_start__
    ldr  r1, =__bss_end__
    mov   r2, #0
1:
    str r2, [r0]
    add r0, r0, #4
    cmp r1, r2
    bcc 1b
    /* Jump to main */
    mov r0, #0
    mov r1, #0
    ldr r2, =main
    blx r2
    b .                             /* in case main returns */
    .ltorg

.section .stack_main,"aw"
.balign 4
#ifdef __STACK_SIZE
.equ Stack_Size, __STACK_SIZE
#else
.equ Stack_Size, 0x1000
#endif
.space Stack_Size


