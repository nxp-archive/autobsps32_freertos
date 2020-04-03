/*-----------------------------------------------------------
 *
 *  Copyright 2020 NXP
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

    .section ".core_exceptions_table","ax"

    .extern vPortISRHandler
    .extern xPortSyscall


    .align 4
CI_ESR:
    e_b CI_ESR

    .align 4
MC_ESR:
    e_b MC_ESR

    .align 4
DS_ESR:
    e_b DS_ESR

    .align 4
IS_ESR:
    e_b IS_ESR

    .align 4
EI_ESR:
    e_b vPortISRHandler

    .align 4
Align_ESR:
    e_b Align_ESR

    .align 4
Program_ESR:
    e_b Program_ESR

    .align 4
FP_Unav_ESR:
    e_b FP_Unav_ESR

    .align 4
SC_ESR:
    e_b xPortSyscall

    .align 4
AP_Unav_ESR:
    e_b AP_Unav_ESR

    .align 4
DEC_ESR:
    e_b DEC_ESR

    .align 4
FIT_ESR:
    e_b FIT_ESR

    .align 4
WDT_ESR:
    e_b WDT_ESR

    .align 4
DTLB_error_ESR:
    e_b DTLB_error_ESR

    .align 4
ITLB_error_ESR:
    e_b ITLB_error_ESR

    .align 4
Debug_ESR:
    e_b Debug_ESR

    .align 4
__generic_exception_handler:

  e_b __generic_exception_handler


    .end
