/*
*   Copyright 2018 NXP
*/

#ifndef HW_WDG_H
#define HW_WDG_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /*****Watchdog *****/
    #define HWSWT_BASE_ADDR(coreId)     (HWSWT0_BASE_ADDR + ((coreId) << 14U)) /* Core0 -> SWT0 */
    #define SWT_SR_R  HWREG32(HWSWT_BASE_ADDR(CORE_ID) + 0x10)
    #define SWT_CR_R  HWREG32(HWSWT_BASE_ADDR(CORE_ID))

    /* Access the WatchDog for the other cores */
    #define HWWatchdogDisable() do {             \
            SWT_SR_R = 0xc520;                   \
            SWT_SR_R = 0xd928;                   \
            SWT_CR_R = 0xFF00010A;               \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif  /* HW_WDG_H */

