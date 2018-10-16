/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/*
 * main-blinky.c is included when the "Blinky" build configuration is used.
 * main-full.c is included when the "Full" build configuration is used.
 *
 * main-blinky.c (this file) defines a very simple demo that creates two tasks,
 * one queue, and one timer.  It also demonstrates how Cortex-M3 interrupts can
 * interact with FreeRTOS tasks/timers.
 *
 * This simple demo project runs 'stand alone' (without the rest of the tower
 * system) on the TWR-K60N512 tower module, which is populated with a K60N512
 * Cortex-M4 microcontroller.
 *
 * The idle hook function:
 * The idle hook function demonstrates how to query the amount of FreeRTOS heap
 * space that is remaining (see vApplicationIdleHook() defined in this file).
 *
 * The main() Function:
 * main() creates one software timer, one queue, and two tasks.  It then starts
 * the scheduler.
 *
 * The Queue Send Task:
 * The queue send task is implemented by the prvQueueSendTask() function in
 * this file.  prvQueueSendTask() sits in a loop that causes it to repeatedly
 * block for 200 milliseconds, before sending the value 100 to the queue that
 * was created within main().  Once the value is sent, the task loops back
 * around to block for another 200 milliseconds.
 *
 * The Queue Receive Task:
 * The queue receive task is implemented by the prvQueueReceiveTask() function
 * in this file.  prvQueueReceiveTask() sits in a loop that causes it to
 * repeatedly attempt to read data from the queue that was created within
 * main().  When data is received, the task checks the value of the data, and
 * if the value equals the expected 100, toggles the blue LED.  The 'block
 * time' parameter passed to the queue receive function specifies that the task
 * should be held in the Blocked state indefinitely to wait for data to be
 * available on the queue.  The queue receive task will only leave the Blocked
 * state when the queue send task writes to the queue.  As the queue send task
 * writes to the queue every 200 milliseconds, the queue receive task leaves the
 * Blocked state every 200 milliseconds, and therefore toggles the blue LED
 * every 200 milliseconds.
 *
 * The LED Software Timer and the Button Interrupt:
 * The user button SW7 is configured to generate an interrupt each time it is
 * pressed.  The interrupt service routine switches the green LED on, and
 * resets the LED software timer.  The LED timer has a 5000 millisecond (5
 * second) period, and uses a callback function that is defined to just turn the
 * LED off again.  Therefore, pressing the user button will turn the LED on, and
 * the LED will remain on until a full five seconds pass without the button
 * being pressed.
 */



#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"


/* Freescale includes. */
#include "common.h"


#define LED0                        24U


void vLedTask0( void *pvParameters );

#if configUSE_TICK_HOOK > 0

void vApplicationTickHook(void);


/*
 * Setup the GPIO output.
 */
static void prvSetupHardware( void );
/*
* Global variable
*/
volatile uint32_t ui32_ms_cnt = 0;
volatile uint32_t ui32_vLedTask0 = 0;
volatile unsigned int IdleHook_Tick = 0;
volatile unsigned int AppHook_Tick = 0;

uint32_t led0_deylay = (1000/portTICK_PERIOD_MS);

void vApplicationTickHook(void)
{

        // increments every 1ms if configCPU_CLOCK_HZ is set correctly
        ui32_ms_cnt++;
}

#endif

void vLedTask0( void *pvParameters )
{
    unsigned int ID = (unsigned int)pvParameters;
    while(1)
    {
        ui32_vLedTask0++;
        vTaskDelay(led0_deylay);
        REG_WRITE32(SIUL2_GPDOn( 9 ), 0 << ID);
        vTaskDelay(led0_deylay);
        REG_WRITE32(SIUL2_GPDOn( 9 ), 1 << ID);
    }
}
/* main function*/
int main( void )
{
    /* Configure the NVIC, LED outputs and button inputs. */
    prvSetupHardware();

    xTaskCreate( vLedTask0, ( const char * const ) "LedTask", configMINIMAL_STACK_SIZE, (void*)LED0, tskIDLE_PRIORITY + 1, NULL );

    /* Start the scheduler. */
    vTaskStartScheduler();
    // Will only get here if there was insufficient memory to create the idle
    // task.
    for( ;; );
}

static void prvSetupHardware( void )
{
    REG_WRITE32(SIUL2_MSCRn(36), SIUL2_MSCR_MUX_MODE(0) | \
                                 SIUL2_MSCR_OBE_EN | \
                                 SIUL2_MSCR_IBE_EN | \
                                 SIUL2_MSCR_DSE_34ohm);
    REG_WRITE32(SIUL2_GPDOn(9), 1 << 24);
}


void vApplicationMallocFailedHook( void )
{
    /* Called if a call to pvPortMalloc() fails because there is insufficient
    free memory available in the FreeRTOS heap.  pvPortMalloc() is called
    internally by FreeRTOS API functions that create tasks, queues, software
    timers, and semaphores.  The size of the FreeRTOS heap is set by the
    configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
    IdleHook_Tick++;

}


/*-----------------------------------------------------------*/

/* The Blinky build configuration does not include run time stats gathering,
however, the Full and Blinky build configurations share a FreeRTOSConfig.h
file.  Therefore, dummy run time stats functions need to be defined to keep the
linker happy. */
void vMainConfigureTimerForRunTimeStats( void ) {}
unsigned long ulMainGetRunTimeCounterValue( void ) { return 0UL; }
