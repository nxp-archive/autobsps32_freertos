#include "FreeRTOS.h"
#include "task.h"




extern volatile void * volatile pxCurrentTCB;
static UBaseType_t uxCriticalNesting = 0;
UBaseType_t uxInterruptNested = 0;
extern void vUpdateTimer(void);

void vPortYield(void)
{
    /** do not save R0, R1, R2, R3, R12 */
    OSASM(" mrc p15, 0, r2, c4, c6, 0                       \t\n");    /* get the ICC_PMR */
    OSASM(" mrs r3, cpsr                                    \t\n"); /* get the status */
    OSASM(" ldr r0, =pxCurrentTCB                           \t\n");
    OSASM(" ldr r1, [r0]                                    \t\n");
    OSASM(" stmfd sp!, {r2-r11, lr}                         \t\n"); /* interrupt priority mask, status register and callee-save registers using task stack */
    OSASM(" mov r2, #0                                      \t\n"); /* solicited */
    OSASM(" ldr r0, =uxCriticalNesting                      \t\n");
    OSASM(" ldr r3, [r0]                                    \t\n");
    OSASM(" stmfd sp!, {r2,r3}                              \t\n"); /* solicited context switched and uxCriticalNesting*/
    OSASM(" str sp, [r1]                                    \t\n"); /* save task top of stack */
    OSASM(" mov r2, %0\t\n": : "i" ( configMAX_SYSCALL_INTERRUPT_PRIORITY ): );
    OSASM(" mcr p15, 0, r2, c4, c6, 0                       \t\n");    /* Write r2 into ICC_PMR, enable OS call */
    OSASM(" bl vTaskSwitchContext                           \t\n");
    OSASM(" ldr r0, =pxCurrentTCB                           \t\n");
    OSASM(" ldr r0, [r0]                                    \t\n");
    OSASM(" ldr sp, [r0]                                    \t\n");    /* get new stack of the task */
    OSASM(" ldmfd sp!, {r0-r11,lr}                          \t\n"); /* r0 - sol/unsol, r1 critical, r2 int mask, r3 cpsr */
    OSASM(" ldr r12, =uxCriticalNesting                     \t\n");
    OSASM(" mcr p15, 0, r2, c4, c6, 0                       \t\n");    /* Write r2 into ICC_PMR, task mask level */
    OSASM(" str r1, [r12]                                   \t\n"); /* save critical */
    OSASM(" cmp r0, #0                                      \t\n");
    OSASM(" beq 1f                                          \t\n"); /* go to solicited, 1: */
    OSASM(" mov r0, sp                                      \t\n"); /* prepare exit from interrupt, r0 contains user SP */
    OSASM(" cpsid i                                         \t\n"); /* disable interrupts */
    OSASM(" add sp, sp, #24                                 \t\n"); /* user stack unload r0 - r3, r12, r14 */
    OSASM(" cps #0x12                                       \t\n"); /* enter in IRQ mode */
    OSASM(" msr spsr, r3                                    \t\n"); /* unsolicited */
    OSASM(" ldm r0, {r0-r3, r12, r14}                       \t\n"); /* get registers from user stack */
    OSASM(" subs pc, lr, #4                                 \t\n");    /* return from interrupt */
    OSASM(" 1:                                              \t\n");
    OSASM(" mrs r3, cpsr                                    \t\n"); /* unsolicited */
    OSASM(" mov pc, lr                                      \t\n"); /* return unsolicited */
}

void vPortStartFirstTask(void) __attribute__ (( naked ));
void vPortStartFirstTask(void)
{
    OSASM(" ldr r0, =pxCurrentTCB                           \t\n");
    OSASM(" ldr r0, [r0]                                    \t\n");
    OSASM(" ldr sp, [r0]                                    \t\n");    /* get new stack of the task */
    OSASM(" ldmfd sp!, {r0-r11,lr}                          \t\n"); /* r0 - sol/unsol, r1 critical, r2 int mask, r3 cpsr */
    OSASM(" ldr r12, =uxCriticalNesting                     \t\n");
    OSASM(" mcr p15, 0, r2, c4, c6, 0                       \t\n");    /* Write r2 into ICC_PMR, task mask level */
    OSASM(" str r1, [r12]                                   \t\n"); /* save critical */
    OSASM(" mov r0, sp                                      \t\n"); /* r0 contains user SP */
    OSASM(" add sp, sp, #24                                 \t\n");    /* unload user stack */
    OSASM(" msr CPSR_c, #0x80|0x12                          \t\n");
    OSASM(" msr spsr, r3                                    \t\n"); /* unsolicited */
    OSASM(" ldm r0, {r0-r3, r12, r14}                       \t\n");
    OSASM(" subs pc, lr, #4                                 \t\n");    /* return from interrupt */
}

/*
 * Initialise the stack
 */
StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
{
    pxTopOfStack --;
    *pxTopOfStack -- = (StackType_t)pxCode + 4;                /* R14_IRQ */
    *pxTopOfStack -- = (StackType_t)0x12121212;                /* R12 */
    *pxTopOfStack -- = (StackType_t)0x03030303;                /* R3 */
    *pxTopOfStack -- = (StackType_t)0x02020202;                /* R2 */
    *pxTopOfStack -- = (StackType_t)0x01010101;                /* R1 */
    *pxTopOfStack -- = (StackType_t)pvParameters;              /* R0 */

    *pxTopOfStack -- = (StackType_t)0xFFFFFFFF;                /* R14_USR, invalid return */
    *pxTopOfStack -- = (StackType_t)0x11111111;                /* R11 */
    *pxTopOfStack -- = (StackType_t)0x10101010;                /* R10 */
    *pxTopOfStack -- = (StackType_t)0x09090909;                /* R9 */
    *pxTopOfStack -- = (StackType_t)0x08080808;                /* R8 */
    *pxTopOfStack -- = (StackType_t)0x07070707;                /* R7 */
    *pxTopOfStack -- = (StackType_t)0x06060606;                /* R6 */
    *pxTopOfStack -- = (StackType_t)0x05050505;                /* R5 */
    *pxTopOfStack -- = (StackType_t)0x04040404;                /* R4 */
    *pxTopOfStack -- = (StackType_t)0x0000001f;                /* CPSR mode system, A32 */
    *pxTopOfStack -- = (StackType_t)0x000000f8;                /* Task interrupt mask */
    *pxTopOfStack -- = (StackType_t)0;                         /* critical */
    *pxTopOfStack = (StackType_t)0x00000001;                   /* unsolicited context */

    return pxTopOfStack;
}
/*-----------------------------------------------------------*/
extern void prvSetupTimerInterrupt(void);
BaseType_t xPortStartScheduler( void )
{
    /* Start the timer that generates the tick ISR.  Interrupts are disabled here already. */
    prvSetupTimerInterrupt();
    /* Start the first task. */
    vPortStartFirstTask();

    /* Should not get here! */
    return 0;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
    /* It is unlikely that the ARM port will require this function as there
    is nothing to return to.  */
}

/*-----------------------------------------------------------*/

void vPortEnterCritical( void )
{
    portDISABLE_INTERRUPTS();
    uxCriticalNesting++;
}
/*-----------------------------------------------------------*/

void vPortExitCritical( void )
{
    configASSERT( uxCriticalNesting );
    uxCriticalNesting--;
    if( uxCriticalNesting == 0 )
    {
        portENABLE_INTERRUPTS();
    }
}
extern void* InterruptsTable[];
/*-----------------------------------------------------------*/
void vPortInterruptDispatcher(void) __attribute__ (( naked ));
void vPortInterruptDispatcher(void)
{
    OSASM(" push {r3, r12, r14}                             \t\n");    /* save r12, r14 to interrupt stack */
    OSASM(" mrc p15, 0, r14, c12, c12, 0                    \t\n");    /* get interrupt id, r14 */
    OSASM(" mrc p15, 0, r12, c12, c11, 3                    \t\n"); /* get interrupt priority, r12 */
    OSASM(" cmp r12,%0\t\n"::"i" ( configMAX_SYSCALL_INTERRUPT_PRIORITY ):);
    OSASM(" bhi osInt                                       \t\n"); /* OS interrupt */
    OSASM(" stmfd sp!, {r0-r2}                              \t\n"); /* save volatiles to IRQ stack, r12 & r14 already saved */
    OSASM(" ldr r0, =InterruptsTable                        \t\n");
    OSASM(" mrs r1, LR_svc                                  \t\n");
    OSASM(" mrs r2, SPSR_svc                                \t\n");
    OSASM(" mrs r3, SPSR                                    \t\n");
    OSASM(" push {r1, r2, r3, r14}                          \t\n"); /* save: LR_svc, SPSR_svc, SPSR_irq and the interrupt ID */
    OSASM(" ldr r2, [r0, r14, lsl #2]                       \t\n"); /* get user interrupt vector */
    OSASM(" cpsie i, #0x13                                  \t\n"); /* enable interrupts and enter to svc mode */
    OSASM(" cmp r2, #0                                      \t\n");
    OSASM(" blxne r2                                        \t\n"); /* call user interrupt handler */
    OSASM(" cpsid i, 0x12                                   \t\n"); /* disable interrupts and enter to irq mode */
    OSASM(" pop {r1, r2, r3, r14}                           \t\n"); /* restore: LR_svc, SPSR_svc, SPSR_irq and the interrupt ID */
    OSASM(" msr LR_svc, r1                                  \t\n");
    OSASM(" msr SPSR_svc, r2                                \t\n");
    OSASM(" msr SPSR, r3                                    \t\n");
    OSASM(" mcr p15, 0, r14, c12, c12, 1                    \t\n"); /* End Of Interrupt */
    OSASM(" ldmfd sp!, {r0-r3, r12, r14}                    \t\n"); /* restore user registers */
    OSASM(" subs pc, lr, #4                                 \t\n"); /* return from irq */
    OSASM(" osInt:                                          \t\n"); /* OS interrupt handler */
    OSASM(" ldr r12, =uxInterruptNested                     \t\n");
    OSASM(" ldr r3, [r12]                                   \t\n");
    OSASM(" cmp r3, #0                                      \t\n");
    OSASM(" add r3, r3, #1                                  \t\n"); /* inc uxInterruptNested */
    OSASM(" str r3, [r12]                                   \t\n"); /* save uxInterruptNested */
    OSASM(" stmnedb sp!, {r0-r2}                            \t\n"); /* uxInterruptNested != 0, using irq stack */
    OSASM(" bne 1f                                          \t\n"); /* jump to "prepare Call user handler" */
    OSASM(" mrs r12, SP_usr                                 \t\n"); /* get user stack to r12 */
    OSASM(" sub r12, r12, #12                               \t\n"); /* space for r3, r12, r14 */
    OSASM(" stmdb    r12!, {r0-r2}                          \t\n"); /* save users regs to user stack, */
    OSASM(" ldmfd sp!, {r0-r2}                              \t\n"); /* get r3 -> r0, r12 -> r1, r14-> r2, unload irq stack */
    OSASM(" add r3, r12, #24                                \t\n");
    OSASM(" stmdb r3, {r0-r2}                               \t\n");
    OSASM(" msr SP_usr, r12                                 \t\n"); /* update user stack, save r12*/
    OSASM(" ldr r1, =pxCurrentTCB                           \t\n");
    OSASM(" ldr r1, [r1]                                    \t\n");
    OSASM(" push {r1}                                       \t\n"); /* current task TCB to IRQ stack */
    OSASM(" 1:                                              \t\n"); /* prepare Call user handler */
    OSASM(" ldr r0, =InterruptsTable                        \t\n");
    OSASM(" mrs r1, LR_svc                                  \t\n");
    OSASM(" mrs r2, SPSR_svc                                \t\n");
    OSASM(" mrs r3, SPSR                                    \t\n");
    OSASM(" push {r1, r2, r3, r14}                          \t\n"); /* save: LR_svc, SPSR_svc, SPSR_irq and the interrupt ID */
    OSASM(" ldr r2, [r0, r14, lsl #2]                       \t\n");
    OSASM(" cpsie i, #0x13                                  \t\n"); /* enable interrupts, go to svc mode */
    OSASM(" cmp r2, #0                                      \t\n");
    OSASM(" blxne r2                                        \t\n"); /* call user interrupt handler */
    OSASM(" cpsid i, #0x12                                  \t\n"); /* disable interrupts, enter in IRQ mode */
    OSASM(" pop {r1, r2, r3, r14}                           \t\n"); /* restore: LR_svc, SPSR_svc, SPSR_irq and the interrupt ID */
    OSASM(" ldr r12, =uxInterruptNested                     \t\n");
    OSASM(" msr LR_svc, r1                                  \t\n");
    OSASM(" msr SPSR_svc, r2                                \t\n");
    OSASM(" msr SPSR, r3                                    \t\n");
    OSASM(" mcr p15, 0, r14, c12, c12, 1                    \t\n"); /* End Of Interrupt */
    OSASM(" ldr r3, [r12]                                   \t\n");
    OSASM(" subs r3, r3, #1                                 \t\n"); /* inc uxInterruptNested */
    OSASM(" str r3, [r12]                                   \t\n"); /* save uxInterruptNested */
    OSASM(" ldmnefd sp!, {r0-r3, r12, r14}                  \t\n"); /* return from irq uxInterruptNested != 0 */
    OSASM(" subnes pc, lr, #4                               \t\n"); /* return from irq uxInterruptNested != 0 */
    OSASM(" mrs r0, SP_usr                                  \t\n"); /* get user stack to r0 */
    OSASM(" ldr r14, =pxCurrentTCB                          \t\n");
    OSASM(" pop {r1}                                        \t\n"); /* get prev TCB from IRQ stack */
    OSASM(" ldr r14, [r14]                                  \t\n");
    OSASM(" cmp r14, r1                                     \t\n"); /* compare crt TCB with previous TCB */
    OSASM(" addeq r1, r0, #24                               \t\n"); /* unload user stack, no schedule */
    OSASM(" msreq SP_usr, r1                                \t\n"); /* update user stack, no schedule */
    OSASM(" beq nothingToDo                                 \t\n");
    OSASM(" mrc p15, 0, r2, c4, c6, 0                       \t\n");
    OSASM(" mrs r3, spsr                                    \t\n");
    OSASM(" stmfd r0, {r2-r11, r14}^                        \t\n"); /* sr + int_mask + save registers r14_usr, old task */
    OSASM(" ldr r3, =uxCriticalNesting                      \t\n");
    OSASM(" sub r0, r0, #44                                 \t\n"); /* update r0 */
    OSASM(" mov r2, #1                                      \t\n"); /* unsolicited */
    OSASM(" ldr r3, [r3]                                    \t\n");
    OSASM(" stmfd r0!, {r2, r3}                             \t\n"); /* write type of yield, and critical to user task stack */
    OSASM(" str r0, [r1]                                    \t\n"); /* save stack pointer to old task TCB */
    OSASM(" ldr r0, [r14]                                   \t\n"); /* get new task stack */
    OSASM(" ldmfd r0!, {r2-r5}                              \t\n"); /* get switch type, critical, intmask and SR */
    OSASM(" mcr p15, 0, r4, c4, c6, 0                       \t\n");    /* Write r4 into ICC_PMR, task mask level */
    OSASM(" ldr r4, =uxCriticalNesting                      \t\n");
    OSASM(" msr spsr, r5                                    \t\n");    /* save spsr, unsolicited */
    OSASM(" str r3, [r4]                                    \t\n"); /* store critical */
    OSASM(" ldmfd r0!, {r4-r11, r14}                        \t\n"); /* Get saved regs + r14_usr to r14_irq */
    OSASM(" cmp r2, #0                                      \t\n");    /* is solicited? */
    OSASM(" msreq SP_usr, r0                                \t\n"); /* solicited update user stack */
    OSASM(" moveqs pc, lr                                   \t\n"); /* exit from interrupt, solicited return, no need to subs */
    OSASM(" add r1, r0, #24                                 \t\n");
    OSASM(" msr SP_usr, r1                                  \t\n"); /* update user stack register */
    OSASM(" msr LR_usr, r14                                 \t\n"); /* update user link register */
    OSASM(" nothingToDo:                                    \t\n");
    OSASM(" add r0, r0, #4                                  \t\n");
    OSASM(" ldmfd    r0!, {r1-r3, r12, r14}                 \t\n"); /* save r14_irq to user stack, */
    OSASM(" ldr r0, [r0, #-24]                              \t\n");
    OSASM(" subs pc, lr, #4                                 \t\n"); /* exit from interrupt */
}

void xPortSysTickHandler( void )
{
    vUpdateTimer();
    /* The SysTick runs at the lowest interrupt priority, so when this interrupt
    executes all interrupts must be unmasked.  There is therefore no need to
    save and then restore the interrupt mask value as its value is already
    known. */
    portDISABLE_INTERRUPTS();
    {
        /* Increment the RTOS tick. */
        if( xTaskIncrementTick() != pdFALSE )
        {
            vTaskSwitchContext();
        }
    }
    portENABLE_INTERRUPTS();
}

extern void SVC_Handler(unsigned long* info);
void vPortSVCDispatcher(void) __attribute__ (( naked ));
void vPortSVCDispatcher(void)
{
    OSASM(" stmfd r13!, {r0-r3, r12, r14}   \t\n");    /* save r0 - r3, r12, r14 to SVC stack */
    OSASM(" cpsie i                         \t\n"); /* enable interrupts */
    OSASM(" mov r0, r13                     \t\n");
    OSASM(" ldr r3, =SVC_Handler            \t\n");
    OSASM(" cmp r3, #0                      \t\n");
    OSASM(" blxne r3                        \t\n"); /* call user svc handler */
    OSASM(" cpsid i                         \t\n"); /* disable interrupts */
    OSASM(" ldmfd r13!, {r0-r3, r12, pc}^   \t\n");    /* restore r0 - r3, r12, r15 to SVC stack */
}
