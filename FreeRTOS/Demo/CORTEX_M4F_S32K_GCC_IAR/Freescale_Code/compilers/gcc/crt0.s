/*
 * File:	crt0.s
 * Purpose:	Lowest level routines for Kinetis.
 *
 * Notes:
 *
 */

.syntax unified
.arch armv7-m

.section .startup

.text

.equiv VTOR_REG, 0xE000ED08

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
	/* Setup only for FPGA */
	ldr     r13, =__BOOT_STACK_ADDRESS

	/* Relocate vector table to RAM */
	ldr  r0, =VTOR_REG
	ldr  r1, =__vector_table
	/* ldr  r2, =(1 << 29) */
	/* orr  r1, r2  r1 = r1 | r2 */
	str  r1,[r0]

	bl      start                  /* call the C code */

__done:
    b       __done