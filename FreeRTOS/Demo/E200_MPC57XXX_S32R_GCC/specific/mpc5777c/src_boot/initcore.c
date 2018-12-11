/*
*   Copyright 2018 NXP
*/

/* Include hardware configuration */
#include "hw_platform.h"

static void loop(void);

void hw_init(void)
{
/*enable slave core by set 0 to CORE1 bit in SIU_HLT1*/
    SIU_HLT1 = (uint32_t)0x00000000;
/*after enable slave core, primary core will jump to infinite loop*/
    loop();
}


void loop(void)
{
    for(;;) {}
}
