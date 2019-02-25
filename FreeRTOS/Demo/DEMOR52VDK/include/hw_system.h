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

/** STM */
#define STM_BASE(id)                        (0x4011C000 + (id) * 0x4000)
#define STM_ENABLE(id, div)                 (SYS_REG32(STM_BASE(id)) = 3 + ((0xff & (div)) << 8))
#define STM_ENABLE_CHAN(id, chan, cmp)      {                                                                       \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x14) = 1;                 \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x18) = (cmp);             \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x10) = 1;                 \
                                            }
#define STM_UPDATE_CHAN(id, chan, new)      {                                                                       \
                                                uint32_t oldVal = SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x18);   \
                                                oldVal += (new);                                                    \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x14) = 1;                 \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x18) = oldVal;            \
                                            }
                                               
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

/* Interrupt Router base address */
#define IR_BASE_ADDR 0x40198000UL

#define IR_SPRC(x) SYS_REG16( IR_BASE_ADDR + 0x880 + ((x)<<1) ) /**< Interrupt Router Shared Peripheral Routing Control */
#define IR_ROUTE_INT(id,cluster)    IR_SPRC(id)=(cluster)       /**< route interrupt to cluster, id=0->111, cluster={0,1} */


#define IR_ROUTE_2_CLUSTER0     (1UL)
#define IR_ROUTE_2_CLUSTER1     (2UL)

#define IR_ROUTE_NO_INT     (248UL)

/* route all interrupts to selected cluster */
#define IR_ROUTE_ALL_2_CPU(cluster)                 \
            {                                       \
                int x;                              \
                for (x=0; x<IR_ROUTE_NO_INT; x++) { \
                        IR_ROUTE_INT(x, (cluster)); \
                    }                               \
            }                                       \

typedef struct
{
    void* mp_Handler;
    int m_Priority;
} InterruptCfg_t;
        
typedef struct
{
    int m_TimerId;
    int m_ChannelId;
    int m_Val;
    int m_Div;
} TimerCfg_t;
            
extern void vInitInterruptTable(int, void*);
extern void vSetupStm(TimerCfg_t*, InterruptCfg_t*);

#ifdef __cplusplus
}
#endif

#endif /** HW_SYSTEM_H */