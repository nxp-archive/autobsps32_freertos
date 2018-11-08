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

#include <sys/stat.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Include FreeRTOS kennel*/
#include "FreeRTOS.h"
#include "task.h"

/* Include hardware configuration */
#include "hw_platform.h"


volatile uint32_t ui32_ms_cnt_hook = 0;
volatile uint32_t ui32_coreID = 0;
volatile uint32_t ui32_vLedTask0 = 0;
volatile uint32_t ui32_vLedTask1 = 0;

uint32_t led0_deylay = (500/portTICK_PERIOD_MS);
uint32_t led1_deylay = (1000/portTICK_PERIOD_MS);

void vLedTask0( void *pvParameters );
void vLedTask1( void *pvParameters );
void vApplicationTickHook(void);

void vApplicationTickHook(void)
{
    // increments every 1ms if configCPU_CLOCK_HZ is set correctly
    ui32_ms_cnt_hook++;
}

void vLedTask0( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;
    for( ;; )
    {
        /* Not very exiting - just delay*/
        vTaskDelay( led0_deylay );
        /* set the GIO pin to 1 */
        SetGPIO(ID);
        /* delay */
        vTaskDelay( led0_deylay );
        /* clear the GIO pin */
        ClrGPIO(ID);
        ui32_vLedTask0++;
    }
}

void vLedTask1( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;
    for( ;; )
    {
        /* Not very exiting - just delay*/
        vTaskDelay( led1_deylay );
        /* set the GIO pin to 1 */
        SetGPIO(ID);
        /* delay */
        vTaskDelay( led1_deylay );
        /* clear the GIO pin */
        ClrGPIO(ID);
        ui32_vLedTask1++;
    }
}

int main(void)
{

    GET_CORE_ID(ui32_coreID);
    HWPeriphEnableAll();
    HWWatchdogDisable(ui32_coreID);
    InitGPIO(LED0);
    InitGPIO(LED1);
    OS_PlatformInit();
    xTaskCreate( vLedTask0, ( const char * const ) "LedTask", configMINIMAL_STACK_SIZE, (void*)LED0, tskIDLE_PRIORITY, NULL );
    xTaskCreate( vLedTask1, ( const char * const ) "LedTask1", configMINIMAL_STACK_SIZE, (void*)LED1, tskIDLE_PRIORITY, NULL );
    /* Start the scheduler. */
    vTaskStartScheduler();
    // Will only get here if there was insufficient memory to create the idle
    // task.
    for( ;; );

}
