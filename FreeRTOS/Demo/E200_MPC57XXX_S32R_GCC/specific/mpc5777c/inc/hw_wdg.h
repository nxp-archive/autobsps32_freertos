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
    #define HWSWT_BASE_ADDR(coreId)     (HWSWT0_BASE_ADDR + (coreId << 14U)) /* Core0 -> SWT0 */
    #define SWT_SR_R(coreId)  HWREG32(HWSWT_BASE_ADDR(coreId) + 0x10U)
    #define SWT_CR_R(coreId)  HWREG32(HWSWT_BASE_ADDR(coreId))

    /* Access the WatchDog for the other cores */
    #define HWWatchdogDisable(coreId) do { \
            SWT_SR_R(coreId) = 0xc520;     \
            SWT_SR_R(coreId) = 0xd928;     \
            SWT_CR_R(coreId) = 0xFF00010A; \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif  /* HW_WDG_H */

