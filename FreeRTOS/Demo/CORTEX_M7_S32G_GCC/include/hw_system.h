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
#ifndef HW_SYSTEM_H
#define HW_SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

/* register access */
#define SYS_REG32(address)      ( *(volatile int   *)(address) ) /**<  32-bit register */
#define SYS_REG16(address)      ( *(volatile short *)(address) ) /**<  16-bit register */
#define SYS_REG8(address)       ( *(volatile char  *)(address) ) /**<   8-bit register */

#define SWT4_BASE           (0x40200000)
#define SWT_UNLOCK_SEQ1_U32 (0x0000C520UL)
#define SWT_UNLOCK_SEQ2_U32 (0x0000D928UL)
#define SWT_WDG_ENABLED_U32 (0x00000001UL)

typedef struct {
    unsigned int CR;
    unsigned int IR;
    unsigned int TO;
    unsigned int WN;
    unsigned int SR;
    unsigned int KO;
    unsigned int SK;
} swt_t;

#define OS_FOR_VDK 1

/* Interrupt Router base address */
#define IR_BASE_ADDR 0x40198000UL

/* Interrupt Router registers */
#define IR_CP0IR   SYS_REG32( IR_BASE_ADDR + 0x800 ) /**< Interrupt Router CP0 Interrupt */
#define IR_CP1IR   SYS_REG32( IR_BASE_ADDR + 0x804 ) /**< Interrupt Router CP1 Interrupt */
#define IR_CP2IR   SYS_REG32( IR_BASE_ADDR + 0x808 ) /**< Interrupt Router CP2 Interrupt */

#define IR_CPGIR   SYS_REG32( IR_BASE_ADDR + 0x820 ) /**< Interrupt Router CPU Generate Interrupt */
#define IR_SPRC(x) SYS_REG16( IR_BASE_ADDR + 0x880 + ((x)<<1) ) /**< Interrupt Router Shared Peripheral Routing Control */
    
    
/* Interrupt Router user interface */
#define IR_CP0_CLEAR_SW_INT(x)  IR_CP0IR=(1<<(x))  /**< clear sw interrupt flag for CPU0 */
#define IR_CP1_CLEAR_SW_INT(x)  IR_CP1IR=(1<<(x))  /**< clear sw interrupt flag for CPU1 */
#define IR_CP2_CLEAR_SW_INT(x)  IR_CP2IR=(1<<(x))  /**< clear sw interrupt flag for CPU2 */

#define IR_GEN_SW_INT_2_CP0(x)  IR_CPGIR=((1<<16)|(x))  /**< generate sw interrupt for CPU0, x={0,1,2,3} */
#define IR_GEN_SW_INT_2_CP1(x)  IR_CPGIR=((1<<17)|(x))  /**< generate sw interrupt for CPU1, x={0,1,2,3} */
#define IR_GEN_SW_INT_2_CP2(x)  IR_CPGIR=((1<<18)|(x))  /**< generate sw interrupt for CPU1, x={0,1,2,3} */

#define IR_ROUTE_INT(id,cpu)    IR_SPRC(id)=(cpu)       /**< route interrupt to cpu, id=0->111, cpu={0,1} */


#define IR_ROUTE_2_CPU0     (1UL)
#define IR_ROUTE_2_CPU1     (2UL)
#define IR_ROUTE_2_CPU2     (4UL)
#define IR_ROUTE_2_CPU3     (8UL)
#define IR_ROUTE_NO_INT     (248UL)

/* route all interrupts to selected cpu */
#define IR_ROUTE_ALL_2_CPU(cpu)                     \
            {                                       \
                int x;                              \
                for (x=0; x<IR_ROUTE_NO_INT; x++) { \
                        IR_ROUTE_INT(x, (cpu));     \
                    }                               \
            }                                       \


#ifdef __cplusplus
}
#endif

#endif /** HW_SYSTEM_H */