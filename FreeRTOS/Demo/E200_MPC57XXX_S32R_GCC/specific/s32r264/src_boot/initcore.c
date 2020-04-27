/*-----------------------------------------------------------
 *
 *  Copyright 2018 NXP
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/
 * or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 *----------------------------------------------------------*/

/* Include hardware configuration */
#include "hw_platform.h"


volatile uint32_t ui32_ms_cnt_loop = 0;

#define KEY_VALUE 0x5AF0ul

extern void __startSlave(void);

void hw_init()
{
    uint32_t mctl = MC_ME_MCTL;
#if CORE_ID == 1
    /* enable core 1 in all modes */
    MC_ME_CCTL(1) = 0x00FE;
    /* Set Start address for core 1: Will reset and start */
    MC_ME_CADDR(1) = (uint32_t)(__startSlave) | 0x1;
#endif
#if CORE_ID == 2
    MC_ME_CCTL(2) = 0x00FE;
    /* Set Start address for core 1: Will reset and start */
    MC_ME_CADDR(2) = (uint32_t)(__startSlave) | 0x1;
#endif
    MC_ME_MCTL = (mctl & 0xffff0000ul) | KEY_VALUE;
    MC_ME_MCTL =  mctl; /* key value 2 always from MCTL */
}

int loop(void)
{
    for(;;) {
        ui32_ms_cnt_loop++;
    }
}
