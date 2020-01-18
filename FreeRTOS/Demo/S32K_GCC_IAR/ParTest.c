/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

/*-----------------------------------------------------------
 * Simple GPIO (parallel port) IO routines.
 *-----------------------------------------------------------*/

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Standard demo include. */
#include "partest.h"

/* Freescale includes. */
#include "common.h"

/* Only the LEDs on one of the two seven segment displays are used. */
#define partstMAX_LEDS		4

/* The bits used to control the LEDs on the S32K144HT. */
const unsigned long ulLEDs[ partstMAX_LEDS ] = { ( 1UL << 7UL ), ( 1UL << 8UL ), ( 1UL << 5UL ), ( 1UL << 5UL ) };

/*-----------------------------------------------------------*/

void vParTestInitialise( void )
{
	/* Set PTE7, PTE8, PTB5, and PTD5 (connected to LED's) for GPIO
	functionality. */
	PORTE->PCR[7] = ( 0 | PORT_PCR_MUX( 1 ) );
	PORTE->PCR[8] = ( 0 | PORT_PCR_MUX( 1 ) );
	PORTB->PCR[5] = ( 0 | PORT_PCR_MUX( 1 ) );
	PORTD->PCR[5] = ( 0 | PORT_PCR_MUX( 1 ) );

	/* Change PTE7, PTE8, PTB5, and PTD5 to outputs. */
	PTE->PDDR = GPIO_PDDR_PDD( ulLEDs[ 0 ] | ulLEDs[ 1 ] );
	PTB->PDDR = GPIO_PDDR_PDD( ulLEDs[ 2 ] );
	PTD->PDDR = GPIO_PDDR_PDD( ulLEDs[ 3 ] );

	/* Start with LEDs off. */
	PTE->PTOR = ~0U;
	PTB->PTOR = ~0U;
	PTD->PTOR = ~0U;
}
/*-----------------------------------------------------------*/

void vParTestSetLED( unsigned long ulLED, signed portBASE_TYPE xValue )
{
	if( ulLED < partstMAX_LEDS )
	{
		if( xValue == pdTRUE )
		{
			if ( ulLED == 0 || ulLED == 1 )
				PTE->PCOR = ulLEDs[ ulLED ];
			else if ( ulLED == 2)
				PTB->PCOR = ulLEDs[ ulLED ];
			else
				PTD->PCOR = ulLEDs[ ulLED ];
		}
		else
		{
			if ( ulLED == 0 || ulLED == 1 )
				PTE->PSOR = ulLEDs[ ulLED ];
			else if ( ulLED == 2)
				PTB->PSOR = ulLEDs[ ulLED ];
			else
				PTD->PSOR = ulLEDs[ ulLED ];
		}
	}
}
/*-----------------------------------------------------------*/

void vParTestToggleLED( unsigned long ulLED )
{
	if( ulLED < partstMAX_LEDS )
	{
		if ( ulLED == 0 || ulLED == 1 )
			PTE->PTOR = ulLEDs[ ulLED ];
		else if ( ulLED == 2)
			PTB->PTOR = ulLEDs[ ulLED ];
		else
			PTD->PTOR = ulLEDs[ ulLED ];
	}
}
/*-----------------------------------------------------------*/

long lParTestGetLEDState( unsigned long ulLED )
{
long lReturn = pdFALSE;

	if( ulLED < partstMAX_LEDS )
	{
		if ( ulLED == 0 || ulLED == 1 )
			lReturn = PTE->PDOR & ulLEDs[ ulLED ];
		else if ( ulLED == 2)
			lReturn = PTB->PDOR & ulLEDs[ ulLED ];
		else
			lReturn = PTD->PDOR & ulLEDs[ ulLED ];
		if( lReturn == 0 )
		{
			lReturn = pdTRUE;
		}
		else
		{
			lReturn = pdFALSE;
		}
	}

	return lReturn;
}
