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


.extern VTABLE
.extern SystemInit

.section .startup,"ax"

.thumb

.equ VTOR_REG, 0xE000ED08
.equ START_ITCM, 0x00000000
.equ ITCMCR, 0xE000EF90
.equ DTCMCR, 0xE000EF94

.align 2
.globl Reset_Handler
Reset_Handler:
_start:
    ldr  r0, =VTOR_REG
    ldr  r1, =VTABLE
    ldr  r2, =0xFFFFFF80
	ldr  r3, [r1]					/* main statck initialization */
    and  r1, r2  					/* r1 = r1 & r2 */
	mov  sp, r3
    str  r1,[r0]					/* vector table initialization */

/* Zero fill the bss segment */
    ldr  r2, =__bss_start__
    ldr  r4, =__bss_end__
    mov   r3, #0

FillZerobss:
    str   r3, [r2]
    add   r2, r2, #4
    cmp   r2, r4
    bcc   FillZerobss
  
/* call system initialization first */
    bl SystemInit


/* call application entry point */
    bl main

    b . /* in case main returns */


.globl OSInterruptDispatcher
OSInterruptDispatcher:
	b OSInterruptDispatcher

.globl OSNmiException
OSNmiException:
	b OSNmiException

.globl OSHardFaultException
OSHardFaultException:
	b OSHardFaultException

.globl OSMemManageException
OSMemManageException:
	b OSMemManageException

.globl OSBusFaultException
OSBusFaultException:
	b OSBusFaultException
.globl OSUsageFaultException
OSUsageFaultException:
	b OSUsageFaultException

.globl OSDebugMonitorException
OSDebugMonitorException:
	b OSDebugMonitorException

.globl OSReservedException
OSReservedException:
	b OSReservedException




.section .stack_main,"aw"
.balign 4
#ifdef __STACK_SIZE
.equ Stack_Size, __STACK_SIZE
#else
.equ Stack_Size, 0x200
#endif
.space Stack_Size


