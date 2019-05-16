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
#include <stdint.h>
#include "gicv3.h"

void vGicInit(void)
{
    /** check if the Group0 is disabled and Group1 is enabled */
    uint32_t i = GET_GIC_GROUPS_STATUS;
    
    if ((OSINTC_D_GROUP_0 & i)) {
        SET_GIC_GROUP(OSINTC_D_GROUP_0, 0); /* disable group 0 FIQ */
    }
    if (!(OSINTC_D_GROUP_1 & i)) {
        SET_GIC_GROUP(OSINTC_D_GROUP_1, 1); /* enable group 1 IRQ */
    }
    /* Redistributor settings */
    WAKE_UP_PE;
    /* default priority mask. */
    OSINTC_SET_INT_PRI_MASK(OSINTC_GIC_CONVERT_PRIO_SET( OSINTC_GIC_MIN_PRIO ));
    /* reset EOImode & CBPR*/
    i = OSINTC_GET_ICC_CTRL & (~3ul);
    OSINTC_SET_ICC_CTRL(i);
    
    /* Core interface disable Fiq enable Irq */
    if (OSINTC_GET_ICC_GRPEN0 & 1) {
        OSINTC_SET_ICC_GRPEN0(0);
    }
    
    if (!(OSINTC_GET_ICC_GRPEN1 & 1)) {
        OSINTC_SET_ICC_GRPEN1(1);
    }
    
    
    /*set to 1 to supports interrupt grouping for group1*/
    OSINTC_SET_ICC_CTRL(1);
    
    /* clear redistributor interrupts */
    for (i = 0; i < 32; i ++) {
        OSINTC_GIC_DISABLE_INTX(i);        /**< disable interrupt       */
        OSINTC_GIC_CLEAR_PENDING_INTX(i);  /**< clear pending interrupt */
        OSINTC_SET_PRIO_INTX(i, OSINTC_GIC_CONVERT_PRIO_SET( OSINTC_GIC_MIN_PRIO ));     /**< set priority to MIN */
    }
    for (i = 32; i < 1024; i ++) {
        OSINTC_GIC_DISABLE_INTX(i);        /**< disable interrupt       */
        OSINTC_GIC_CLEAR_PENDING_INTX(i);  /**< clear pending interrupt */
        OSINTC_SET_PRIO_INTX(i, OSINTC_GIC_CONVERT_PRIO_SET( OSINTC_GIC_MIN_PRIO ));     /**< set priority to MIN */
    }
}

void vGicEnableInterrupt(int index, int prio)
{
    OSINTC_GIC_GROUP_INTX(index, 1);
    OSINTC_GIC_CONFIG_INTX(index, 0);
    OSINTC_SET_PRIO_INTX(index, OSINTC_GIC_CONVERT_PRIO_SET(prio)); /**<  set priority */
    OSINTC_GIC_ROUTE_INTX(index, (0));
    OSINTC_GIC_ENABLE_INTX(index); /**< enable interrupt       */
}
