/*
*   Copyright 2018 NXP
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "cpudefs.h"
/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

    #define configUSE_PREEMPTION                        1
    #define configTICK_RATE_HZ                          ((TickType_t) 1000 )
    #define configMAX_PRIORITIES                        7
    #define configMINIMAL_STACK_SIZE                    ((unsigned portSHORT ) 256)
    #define configMAX_TASK_NAME_LEN                     13
    #define configUSE_16_BIT_TICKS                      0
    #define configIDLE_SHOULD_YIELD                     1
    #define configUSE_MUTEXES                           1

    /* HOOK function related definitions. */
    #define configUSE_IDLE_HOOK                         0
    #define configUSE_TICK_HOOK                         1

    /* Memory allocation related definitions. */
    #define configTOTAL_HEAP_SIZE                       ((size_t) (20 * 1024) )
    #define configCHECK_FOR_STACK_OVERFLOW              0

    /* Run time and task stats gathering related definitions. */
    #define configUSE_TRACE_FACILITY                    0

    /* Co-routine definitions. */
    #define configUSE_CO_ROUTINES                       0
    #define configMAX_CO_ROUTINE_PRIORITIES             ( 4 )

    /* Set the following definitions to 1 to include the API function, or zero
    to exclude the API function. */
    #define INCLUDE_vTaskPrioritySet                    0
    #define INCLUDE_uxTaskPriorityGet                   0
    #define INCLUDE_vTaskDelete                         0
    #define INCLUDE_vTaskCleanUpResources               0
    #define INCLUDE_vTaskSuspend                        0
    #define INCLUDE_vResumeFromISR                      0
    #define INCLUDE_vTaskDelayUntil                     0
    #define INCLUDE_vTaskDelay                          1
    #define INCLUDE_xTaskGetSchedulerState              0
    #define INCLUDE_xTaskGetCurrentTaskHandle           0
    #define INCLUDE_uxTaskGetStackHighWaterMark         0

    /* Interrupt nesting behaviour configuration. */
    #define configMAX_API_CALL_INTERRUPT_PRIORITY       8

    // #define vPortISRHandler  /* define macro of EI_ESR */
    // #define xPortSyscall  /* define macro of SC_ESR */

    // #define prvPortTimerSetup prvPortTimerSetup /* define macro of timer setup function */
    #define prvPortTimerReset resetTimer /* define macro of timer reset function */

#ifdef __cplusplus
}
#endif

#endif /* FREERTOS_CONFIG_H */
