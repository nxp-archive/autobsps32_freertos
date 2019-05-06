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
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <event_groups.h>
#include "hw_system.h"

#define MAIN_PRIORITY                ( tskIDLE_PRIORITY + 2 )
volatile uint32_t ui32_ms_cnt = 0;
volatile uint32_t task_1 = 0;
volatile uint32_t task_2 = 0;
volatile uint32_t task_3 = 0;
volatile uint32_t task_4 = 0;
volatile uint32_t task_5 = 0;
volatile uint32_t task_6 = 0;
volatile uint32_t error_sync = 0;
volatile uint32_t idle_task = 0;
volatile uint32_t int1 = 0;
volatile uint32_t int2 = 0;
volatile uint32_t timeout = 0;
volatile uint32_t stmInt[4] = {0, 0, 0, 0};
volatile uint32_t svcCnt = 0;
#if configUSE_IDLE_HOOK
void vApplicationIdleHook(void) {
    idle_task ++;
//    OSASM(" wfi                     \t\n");
}
#endif


void SVC_Handler(void)
{
    OSINTC_SET_ICC_SGI1R(2, 1);
    svcCnt ++;
}


SemaphoreHandle_t xSemaphore;

void vTask1( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;

    for( ;; ) {
        xSemaphoreGive( xSemaphore );
        if (task_3 <= task_1) {
            error_sync ++;
        }
        task_1 ++;
        vTaskDelay( 1 + ID);
        OSASM(" svc #0      \t\n");
    }
}

void vTask2( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;

    for( ;; ) {
        task_2 ++;
        vTaskDelay( 1 + ID );
    }
}

void vTask3( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;

    for( ;; ) {
        if (pdTRUE == xSemaphoreTake( xSemaphore, ( TickType_t )(1 + ID ) )) {
            if (task_4 != task_3) {
                error_sync ++;
            }
            task_3 ++;
        }
    }
}

EventGroupHandle_t xEventGroup;
void vTask4( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;
    EventBits_t uxBits;

    xEventGroup = xEventGroupCreate();
    for( ;; ) {
        uxBits = xEventGroupWaitBits( xEventGroup, 1, pdTRUE, pdFALSE, ( TickType_t )(1 + ID ) );
        if (1 == (uxBits & 1)) {
            task_4 ++;
        }
        else {
            timeout ++;
        }
    }
}

void vTask5(void *pvParameters) __attribute__ (( naked ));
void vTask5(void *pvParameters)
{
    /** prepare registers, r0 = 4 */
    OSASM(" add r1, r0, #1                  \t\n");
    OSASM(" add r2, r0, #2                  \t\n");
    OSASM(" add r3, r0, #3                  \t\n");
    OSASM(" add r4, r0, #4                  \t\n");
    OSASM(" add r5, r0, #5                  \t\n");
    OSASM(" add r6, r0, #6                  \t\n");
    OSASM(" add r7, r0, #7                  \t\n");
    OSASM(" add r8, r0, #8                  \t\n");
    OSASM(" add r9, r0, #9                  \t\n");
    OSASM(" add r10, r0, #10                \t\n");
    OSASM(" add r11, r0, #11                \t\n");
    OSASM(" add r12, r0, #12                \t\n");
    OSASM(" add r14, r0, #14                \t\n");
    OSASM(" 1:                              \t\n");
    OSASM(" cmp r0, #4                      \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r1, #5                      \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r2, #6                      \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r3, #7                      \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r4, #8                      \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r5, #9                      \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r6, #10                     \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r7, #11                     \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r8, #12                     \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r9, #13                     \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r10, #14                    \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r11, #15                    \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r12, #16                    \t\n");
    OSASM(" bne 1f                          \t\n");
    OSASM(" cmp r14, #18                    \t\n");
    OSASM(" bne 1f                          \t\n");
    
    OSASM(" stmfd sp!, {r0-r3, r12, r14}    \t\n");
    OSASM(" ldr r0, =task_5                 \t\n");
    OSASM(" ldr r1, [r0]                    \t\n");
    OSASM(" add r1, r1, #1                  \t\n");
    OSASM(" str r1, [r0]                    \t\n");
    OSASM(" bl vPortYield                   \t\n");
    OSASM(" ldmfd sp!, {r0-r3, r12, r14}    \t\n");
    OSASM(" b 1b                            \t\n");

    OSASM(" 1:                              \t\n");
    OSASM(" b 1b                            \t\n");
}

volatile uint32_t InterruptCounter = 0;
void SGI0_Handler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE, xResult = pdFAIL;
    InterruptCounter ++;
    xResult = xEventGroupSetBitsFromISR( xEventGroup, 1, &xHigherPriorityTaskWoken );

    if( xResult != pdFAIL ) {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
    OSINTC_SET_ICC_SGI1R(1, 1);
}

void SGI1_Handler(void)
{
    int1 ++;
}

void SGI2_Handler(void)
{
    int2 ++;
}

EventGroupHandle_t xEventGroup1;
void vTask6( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;
    EventBits_t uxBits;

    xEventGroup1 = xEventGroupCreate();
    for( ;; ) {
        uxBits = xEventGroupWaitBits( xEventGroup1, 1, pdTRUE, pdFALSE, ( TickType_t )(1 + ID ) );
        if (1 == (uxBits & 1)) {
            task_6 ++;

            if (task_6 & 1) {
                vTaskPrioritySet( NULL, MAIN_PRIORITY - 2);
            }
            else {
                vTaskPrioritySet( NULL, MAIN_PRIORITY + 3);
            }
        }
        else {
            timeout ++;
        }
    }
}

void Stm_Handler0(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE, xResult = pdFAIL;

    STM_UPDATE_CHAN(0, 0, ((OS_TICK >> 2) + (stmInt[0] & 0xfff)));
    stmInt[0] ++;
    xResult = xEventGroupSetBitsFromISR( xEventGroup1, 1, &xHigherPriorityTaskWoken );

    if( xResult != pdFAIL ) {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void Stm_Handler1(void)
{
    STM_UPDATE_CHAN(1, 0, ((OS_TICK >> 2) + (stmInt[1] & 0xfff)));
    stmInt[1] ++;
}

void Stm_Handler2(void)
{
    STM_UPDATE_CHAN(2, 0, ((OS_TICK >> 2) + (stmInt[2] & 0xfff)));
    stmInt[2] ++;
}

TimerCfg_t stm0 = {0, 0, (OS_TICK >> 2) + (OS_TICK >> 6), 0};
InterruptCfg_t intStm0 = {(void*)Stm_Handler0, 3};

TimerCfg_t stm1 = {1, 0, (OS_TICK >> 2) + (OS_TICK >> 5), 0};
InterruptCfg_t intStm1 = {(void*)Stm_Handler1, 4};

TimerCfg_t stm2 = {2, 0, (OS_TICK >> 2) + (OS_TICK >> 5), 0};
InterruptCfg_t intStm2 = {(void*)Stm_Handler2, 11};

int main(void)
{
    vGicInit();
    xSemaphore = xSemaphoreCreateBinary();
    xTaskCreate( vTask1, ( const char * const ) "Task1", configMINIMAL_STACK_SIZE, (void*)0x0, MAIN_PRIORITY, NULL);
    xTaskCreate( vTask2, ( const char * const ) "Task2", configMINIMAL_STACK_SIZE, (void*)0x1, MAIN_PRIORITY, NULL);
    xTaskCreate( vTask3, ( const char * const ) "Task3", configMINIMAL_STACK_SIZE, (void*)0x2, MAIN_PRIORITY + 1, NULL);
    xTaskCreate( vTask4, ( const char * const ) "Task4", configMINIMAL_STACK_SIZE, (void*)0x3, MAIN_PRIORITY + 2, NULL);
    xTaskCreate( vTask5, ( const char * const ) "Task5", configMINIMAL_STACK_SIZE, (void*)0x4, MAIN_PRIORITY - 2, NULL);
    xTaskCreate( vTask6, ( const char * const ) "Task6", configMINIMAL_STACK_SIZE, (void*)0x5, MAIN_PRIORITY + 3, NULL);
    vInitInterruptTable(0, SGI0_Handler);
    vGicEnableInterrupt(0, 2);
    
    vInitInterruptTable(1, SGI1_Handler);
    vGicEnableInterrupt(1, 10);
    vInitInterruptTable(2, SGI2_Handler);
    vGicEnableInterrupt(2, 9);
    vSetupStm(&stm0, &intStm0);
    vSetupStm(&stm1, &intStm1);
    vSetupStm(&stm2, &intStm2);
    vTaskStartScheduler();

    while (1) {
    }
    return 0;
}

void vAssertCalled(uint32_t ulLine, const char *pcFile)
{

}

void vApplicationStackOverflowHook(xTaskHandle pxTask, char *pcTaskName)
{

}

void vApplicationTickHook(void)
{
    ui32_ms_cnt ++;
    OSINTC_SET_ICC_SGI1R(0, 1);
}

uint32_t _sbrk (int incr)
{
    return incr;
}

void vApplicationMallocFailedHook(void)
{

}