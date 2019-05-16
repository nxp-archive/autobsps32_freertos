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
#ifndef ACCESS_MACROS_H
#define ACCESS_MACROS_H

#define OSSTRING(x) #x
#define OSREG32( address )  ( *(volatile uint32_t*)(address) )

/** coprocessor access macros */
/* write 32bit to coprocessor */
#define __MCR(coproc, opcode1, Rd, CRn, CRm, opcode2) \
            __asm volatile(" "OSSTRING(mcr p##coproc)", "OSSTRING(opcode1)", %0, "OSSTRING(c##CRn)", "OSSTRING(c##CRm)", "OSSTRING(opcode2)" ": : "r"(Rd))
/* read 32bit from coprocessor */
#define __MRC(coproc, opcode1, CRn, CRm, opcode2) ({ \
            register uint32_t _tempRegRt; \
            __asm volatile(" "OSSTRING(mrc p##coproc)", "OSSTRING(opcode1)", %0, "OSSTRING(c##CRn)", "OSSTRING(c##CRm)", "OSSTRING(opcode2)" ": "=r"(_tempRegRt));   \
            _tempRegRt; })
/* write 64bit to coprocessor */
#define __MCRR(coproc, opcode1, Rd, Rd2, CRm) ({ \
            __asm volatile(" "OSSTRING(mcrr p##coproc)", "OSSTRING(opcode1)", %0, %1, "OSSTRING(c##CRm)" ": : "r"(Rd), "r"(Rd2)); })
/* read 64bit from coprocessor */
#define __MRRC(coproc, opcode1, CRm) ({ \
            uint32_t Rd, Rd2;                           \
            uint64_t retval;                            \
            __asm volatile(" "OSSTRING(mrrc p##coproc)", "OSSTRING(opcode1)", %0, %1, "OSSTRING(c##CRm)" ": "=r"(Rd), "=r"(Rd2): ); \
            retval = ((uint64_t)Rd2);                   \
            retval = (retval << 32);                    \
            retval |= Rd;                               \
            retval;})

#endif /* ACCESS_MACROS_H */
