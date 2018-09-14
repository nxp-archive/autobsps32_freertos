/*
 * File:	crt0.s
 * Purpose:	Lowest level routines for s32v234.
 *
 * Notes:
 *
 */

.syntax unified
.arch armv7-m

.section .startup

.text

.equiv VTOR_REG, 0xE000ED08

/* CPACR is located at address 0xE000ED88 */
.equiv CPACR_REG, 0xE000ED88

.align 2

.globl __startup
.type __startup, %function

__startup:

	mov     r0,#0                   /* Initialize the GPRs */
	mov     r1,#0
	mov     r2,#0
	mov     r3,#0
	mov     r4,#0
	mov     r5,#0
	mov     r6,#0
	mov     r7,#0
	mov     r8,#0
	mov     r9,#0
	mov     r10,#0
	mov     r11,#0
	mov     r12,#0
    
	/* Load stack pointer in case the CMM doesn't do it */
	ldr     r13, =__BOOT_STACK_ADDRESS

	/* Relocate vector table to RAM */
	ldr  r0, =VTOR_REG
	ldr  r1, =__vector_table
	str  r1,[r0]

	/* disable SWT4 watchdog*/
	ldr r0, =0x40086010
	ldr r1, =0xC520
	str r1, [r0]
	ldr r1, =0xD928
	str r1, [r0]
	ldr r0, =0x40086000
	ldr r1, [r0]
	and r1, r1, 0xFFFFFFFE
	str r1, [r0]
	ldr r1, [r0]
	orr r1, r1, 0x40
	str r1, [r0]
	
	/* Enable FPU */

	/* Read CPACR */
	ldr  r0, =CPACR_REG

	/* Set bits 20-23 to enable CP10 and CP11 coprocessors */
	ldr  r1, [r0]
	ldr  r2, =(0xF << 20)
	orr  r1, r2

	/* Write back the modified value to the CPACR */
	str  r1,[r0]

	dsb

	/* Reset pipeline now the FPU is enabled */
	isb

	bl      start                  /* call the C code */

__done:
    b       __done