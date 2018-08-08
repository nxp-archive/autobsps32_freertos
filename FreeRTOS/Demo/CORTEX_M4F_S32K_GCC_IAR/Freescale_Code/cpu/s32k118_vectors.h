/******************************************************************************
*
* Copyright 2018 NXP
*
* File:    s32k118_vectors.h
*
* Purpose: Provide custom interrupt service routines for Kinetis.
*
* NOTE: This vector table is a superset table, so interrupt sources might be
*       listed that are not available on the specific Kinetis device you are
*       using.
******************************************************************************/

#ifndef __S32K118_VECTORS_H__
#define __S32K118_VECTORS_H__     1

/* The kernel interrupts - in their CMSIS form. */
extern void SVC_Handler( void );
extern void PendSV_Handler( void );
extern void SysTick_Handler( void );

/* The button interrupt. */
extern void vPort_C_ISRHandler( void );

/* Function prototype for default_isr in vectors.c */
void default_isr(void);

/* Interrupt Vector Table Function Pointers */
typedef void pointer(void);

extern void __startup(void);

extern unsigned long __BOOT_STACK_ADDRESS[];
extern void __iar_program_start(void);
                                            /* Address     Vector IRQ   Source module   Source description                               */
#define VECTOR_000      (pointer*)__BOOT_STACK_ADDRESS  /*              ARM core        Initial Stack Pointer                            */
#define VECTOR_001      __startup           /* Initial Program Counter                          */
#define VECTOR_002      default_isr         /* Non-maskable Interrupt (NMI)                     */
#define VECTOR_003      default_isr         /* Hard Fault                                       */
#define VECTOR_004      default_isr         /* MemManage Fault                                  */
#define VECTOR_005      default_isr         /* Bus Fault                                        */
#define VECTOR_006      default_isr         /* default ISR */
#define VECTOR_007      default_isr         /* default ISR */
#define VECTOR_008      default_isr         /* default ISR */
#define VECTOR_009      default_isr         /* default ISR */
#define VECTOR_010      default_isr         /* default ISR */
#define VECTOR_011      SVC_Handler         /* Supervisor call (SVCall)                        */
#define VECTOR_012      default_isr         /* default ISR */
#define VECTOR_013      default_isr         /* default ISR */
#define VECTOR_014      PendSV_Handler      /* Pendable request for system service (PendableSrvReq) */
#define VECTOR_015      SysTick_Handler     /* System tick timer (SysTick)                     */
#define VECTOR_016      default_isr         /* default ISR */
#define VECTOR_017      default_isr         /* default ISR */
#define VECTOR_018      default_isr         /* default ISR */
#define VECTOR_019      default_isr         /* default ISR */
#define VECTOR_020      default_isr         /* default ISR */
#define VECTOR_021      default_isr         /* default ISR */
#define VECTOR_022      default_isr         /* default ISR */
#define VECTOR_023      default_isr         /* default ISR */
#define VECTOR_024      default_isr         /* default ISR */
#define VECTOR_025      default_isr         /* default ISR */
#define VECTOR_026      default_isr         /* default ISR */
#define VECTOR_027      default_isr         /* default ISR */
#define VECTOR_028      default_isr         /* default ISR */
#define VECTOR_029      default_isr         /* default ISR */
#define VECTOR_030      default_isr         /* default ISR */
#define VECTOR_031      default_isr         /* default ISR */
#define VECTOR_032      default_isr         /* default ISR */
#define VECTOR_033      default_isr         /* default ISR */
#define VECTOR_034      default_isr         /* default ISR */
#define VECTOR_035      default_isr         /* default ISR */
#define VECTOR_036      default_isr         /* default ISR */
#define VECTOR_037      default_isr         /* default ISR */
#define VECTOR_038      default_isr         /* default ISR */
#define VECTOR_039      default_isr         /* default ISR */
#define VECTOR_040      default_isr         /* default ISR */
#define VECTOR_041      default_isr         /* default ISR */
#define VECTOR_042      default_isr         /* default ISR */
#define VECTOR_043      default_isr         /* default ISR */
#define VECTOR_044      default_isr         /* default ISR */
#define VECTOR_045      default_isr         /* default ISR */
#define VECTOR_046      default_isr         /* default ISR */
#define VECTOR_047      default_isr         /* default ISR */
#define CONFIG_1        (pointer*)0xffffffff
#define CONFIG_2        (pointer*)0xffffffff
#define CONFIG_3        (pointer*)0xffffffff
#define CONFIG_4        (pointer*)0xffff7ffe

#endif /*__S32K118_VECTORS_H__*/

/* End of "vectors.h" */
