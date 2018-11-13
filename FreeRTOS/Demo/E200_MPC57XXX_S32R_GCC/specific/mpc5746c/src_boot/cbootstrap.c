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

#include <string.h>

void CBootstrap(void) __attribute__ ((section (".startup")));

void CBootstrap(void)
{

    /* SBSS */
    extern  char * __sbss_start__;
    extern  char * __sbss_end__;

    /* SBSS */
    extern  char * __bss_start__;
    extern  char * __bss_end__;

    memset( (char*)&__sbss_start__, 0x0, (size_t)((char*)&__sbss_end__ - (char*)&__sbss_start__) );
    memset( (char*)&__bss_start__,  0x0, (size_t)((char*)&__bss_end__  - (char*)&__bss_start__ ) );

    /* DATA */
    extern  char * __data_flash_start__;
    extern  char * __user_data_start__;

    /* SDATA */
    extern  char * __sdata_end__;

    memcpy((void *)&__user_data_start__,  /* DST */
           (const void *)&__data_flash_start__,  /* SRC */
           (size_t)((char*)&__sdata_end__ - (char*)&__user_data_start__) /* SIZE */);
}
