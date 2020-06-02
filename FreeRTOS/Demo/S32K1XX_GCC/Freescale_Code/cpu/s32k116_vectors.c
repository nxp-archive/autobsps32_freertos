/******************************************************************************
*
* Copyright 2018 NXP
*
* File:    s32k116_vectors.c
*
* Purpose: Configure interrupt vector table for Kinetis.
* Copyright 2018 NXP
*
******************************************************************************/

#include "s32k116_vectors.h"
#include "common.h"

/******************************************************************************
* Vector Table
******************************************************************************/
typedef void (*vector_entry)(void);

#if defined(IAR)
    #pragma location = ".intvec"
    const vector_entry  __vector_table[] = //@ ".intvec" =
#elif defined(CW)
    #pragma define_section vectortable ".vectortable" ".vectortable" ".vectortable" far_abs R
    #define VECTOR __declspec(vectortable)
    const VECTOR vector_entry  __vector_table[] = //@ ".intvec" =
#elif defined(GCC)
    const __attribute__((section(".intvec"))) vector_entry __vector_table[] __attribute__((used)) =
#endif

{
    VECTOR_000,           /* Initial SP */
    VECTOR_001,           /* Initial PC */
    VECTOR_002,
    VECTOR_003,
    VECTOR_004,
    VECTOR_005,
    VECTOR_006,
    VECTOR_007,
    VECTOR_008,
    VECTOR_009,
    VECTOR_010,
    VECTOR_011,
    VECTOR_012,
    VECTOR_013,
    VECTOR_014,
    VECTOR_015,
    VECTOR_016,
    VECTOR_017,
    VECTOR_018,
    VECTOR_019,
    VECTOR_020,
    VECTOR_021,
    VECTOR_022,
    VECTOR_023,
    VECTOR_024,
    VECTOR_025,
    VECTOR_026,
    VECTOR_027,
    VECTOR_028,
    VECTOR_029,
    VECTOR_030,
    VECTOR_031,
    VECTOR_032,
    VECTOR_033,
    VECTOR_034,
    VECTOR_035,
    VECTOR_036,
    VECTOR_037,
    VECTOR_038,
    VECTOR_039,
    VECTOR_040,
    VECTOR_041,
    VECTOR_042,
    VECTOR_043,
    VECTOR_044,
    VECTOR_045,
    VECTOR_046,
    VECTOR_047,
    CONFIG_1,
    CONFIG_2,
    CONFIG_3,
    CONFIG_4,
};
/* VECTOR_TABLE end */
/******************************************************************************
* default_isr(void)
*
* Default ISR definition.
*
* In:  n/a
* Out: n/a
******************************************************************************/

void default_isr(void)
{
    for( ;; );
}
/******************************************************************************/
/* End of "vectors.c" */
