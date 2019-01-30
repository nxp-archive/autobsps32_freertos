
	.extern vPortInterruptDispatcher
    .extern vPortSVCDispatcher
	.extern SystemInit
	.align 5
	.section .startup,"ax"
	.globl el2_Reset_Handler
el2_Reset_Handler:
	/* el2 vector table */
.globl el2_vector_table
el2_vector_table:
	ldr pc, =el2_reset_exception
	ldr pc, =el2_undefined_exception
	ldr pc, =el2_svc_exception
	ldr pc, =el2_prefetch_exception
	ldr pc, =el2_abort_exception
	nop
	ldr pc, =el2_irq_exception
	ldr pc, =el2_fiq_exception
	.ltorg

	.align 5
	/* el1 vector table */
.globl el1_vector_table
el1_vector_table:
	ldr pc, =el2_Reset_Handler			/* the processor goes to el2 after reset */
	ldr pc, =el1_undefined_exception
	ldr pc, =vPortSVCDispatcher
	ldr pc, =el1_prefetch_exception
	ldr pc, =el1_abort_exception
	nop
	ldr pc, =vPortInterruptDispatcher
	ldr pc, =el1_fiq_exception
	.ltorg

	/* unsupported exceptions */
	.align 2
el2_undefined_exception:
el1_undefined_exception:
	b .
el2_svc_exception:
	b .
el2_prefetch_exception:
el1_prefetch_exception:
	b .
el2_abort_exception:
el1_abort_exception:
	b .
el2_irq_exception:
	b .
el2_fiq_exception:
el1_fiq_exception:
	b .

el2_reset_exception:
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
	eor r8, r8, r8
	eor r9, r9, r9
	eor r10, r10, r10
	eor r11, r11, r11
	eor r12, r12, r12

	ldr r0, =e1_code
	msr elr_hyp, r0
	mrs r0, spsr_hyp
	and r0, r0, #~0x1F					/* reset mode */
	orr r0, r0, #0x13					/* supervisor mode */
	msr spsr_hyp, r0
	eret								/* jump to e1_code */

e1_code:
	/* stack initialization only irq and system processor modes will have a stack */
	/* set irq stack */
	cps #0x12                           /* enter in irq mode, 1KB */
	ldr r13, =(_Stack_start + 4)        /* set irq stack, full */
	cps #0x13                           /* supervisor mode (svc) 2.5KB */
	ldr r13, =(_Stack_start - 0x3fc)    /* set svc stack, full */
	cps #0x1f                           /* system mode (sys) 0.5KB, used by main function */
	ldr r13, =(_Stack_start - 0xdfc)    /* set sys stack, full */

	/* set vtor */
	ldr r0, =el1_vector_table
	mcr p15, 0, r0, c12, c0, 0
	/* call system initialization first */
	ldr	r0, =SystemInit
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
	b . 							/* in case main returns */
	.ltorg

.section .stack_main,"aw"
.balign 4
#ifdef __STACK_SIZE
.equ Stack_Size, __STACK_SIZE
#else
.equ Stack_Size, 0x1000
#endif
.space Stack_Size


