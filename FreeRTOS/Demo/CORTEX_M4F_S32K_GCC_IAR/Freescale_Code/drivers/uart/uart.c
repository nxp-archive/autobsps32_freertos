/*
 * File:        uart.c
 * Purpose:     Provide common UART routines for serial IO
 *
 * Notes:
 *
 */

#include "common.h"
#include "uart.h"

/********************************************************************/
/*
 * Initialize the UART for 8N1 operation, interrupts disabled, and
 * no hardware flow-control
 *
 * NOTE: Since the UARTs are pinned out in multiple locations on most
 *       Kinetis devices, this driver does not enable UART pin functions.
 *       The desired pins should be enabled before calling this init function.
 *
 * Parameters:
 *  uartch      UART channel to initialize
 *  sysclk      UART module Clock in kHz(used to calculate baud)
 *  baud        UART baud rate
 */
void uart_init (LPUART_MemMapPtr uartch, int sysclk, int baud)
{
	register uint16 sbr, sbrTemp;
	uint16 i;
	uint32 osr, tempDiff, calculatedBaud, baudDiff, sourceClockInHz;

	/* Enable the clock to the selected UART */
	if(uartch == LPUART0_BASE_PTR)
		PCC_LPUART0 |= PCC_LPUART0_CGC_MASK;
	else
		if (uartch == LPUART1_BASE_PTR)
			PCC_LPUART1 |= PCC_LPUART1_CGC_MASK;
		else
			if (uartch == LPUART2_BASE_PTR)
				PCC_LPUART2 |= PCC_LPUART2_CGC_MASK;
			else
				PCC_LPUART3 |= PCC_LPUART3_CGC_MASK;

	/* Make sure that the transmitter and receiver are disabled while we
	 * change settings.
	 */
	LPUART_CTRL_REG(uartch) &= ~( LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK );

	/* Configure the UART for 8-bit mode, no parity */
	LPUART_CTRL_REG(uartch) = 0;	/* We need all default settings, so entire register is cleared */

	sourceClockInHz = sysclk * 1000;

	/* This lpuart instantiation uses a slightly different baud rate calculation
	 * The idea is to use the best OSR (over-sampling rate) possible
	 * Note, osr is typically hard-set to 16 in other lpuart instantiations
	 * First calculate the baud rate using the minimum OSR possible (4) */
	osr = 4;
	sbr = (sourceClockInHz/(baud * osr));
	calculatedBaud = (sourceClockInHz / (osr * sbr));

	if (calculatedBaud > baud)
	{
		baudDiff = calculatedBaud - baud;
	}
	else
	{
		baudDiff = baud - calculatedBaud;
	}

	/* Loop to find the best osr value possible, one that generates minimum baudDiff
	 * Iterate through the rest of the supported values of osr */
	for (i = 5; i <= 32; i++)
	{
		/* Calculate the temporary sbr value   */
		sbrTemp = (sourceClockInHz/(baud * i));
		/* Calculate the baud rate on the temporary osr and sbr values */
		calculatedBaud = (sourceClockInHz / (i * sbrTemp));

		if (calculatedBaud > baud)
		{
			tempDiff = calculatedBaud - baud;
		}
		else
		{
			tempDiff = baud - calculatedBaud;
		}

		if (tempDiff <= baudDiff)
		{
			baudDiff = tempDiff;
			osr = i;  /* Update and store the best osr value calculated */
			sbr = sbrTemp;  /* Update store the best sbr value calculated */
		}
	}

	/* Check to see if actual baud rate is within 3% of desired baud rate
	 * on the best calculate osr value */
	if (baudDiff < ((baud / 100) * 3))
	{
		/* Acceptable baud rate, check if osr is between 4x and 7x oversampling.
		 * If so, then "BOTHEDGE" sampling must be turned on */
		if ((osr > 3) && (osr < 8))
		{
			LPUART_BWR_BAUD_BOTHEDGE(uartch, 1);
		}

		/* Program the osr value (bit value is one less than actual value) */
		LPUART_BWR_BAUD_OSR(uartch, (osr-1));

		/* Write the sbr value to the BAUD registers */
		LPUART_BWR_BAUD_SBR(uartch, sbr);
	}

	/* Enable receiver and transmitter */
	LPUART_CTRL_REG(uartch) |= ( LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK );
}
/********************************************************************/
/*
 * Wait for a character to be received on the specified UART
 *
 * Parameters:
 *  uartch      UART channel to read from
 *
 * Return Values:
 *  the received character
 */
char uart_getchar (LPUART_MemMapPtr uartch)
{
	/* Wait until character has been received */
	while (!(LPUART_STAT_REG(uartch) & LPUART_STAT_RDRF_MASK));

	/* Return the 8-bit data from the receiver */
	return LPUART_DATA_REG(uartch);
}
/********************************************************************/
/*
 * Wait for space in the UART Tx FIFO and then send a character
 *
 * Parameters:
 *  uartch       UART channel to send to
 *  ch           character to send
 */
void uart_putchar (LPUART_MemMapPtr uartch, char ch)
{
	/* Wait until space is available in the FIFO */
	while(!(LPUART_STAT_REG(uartch) & LPUART_STAT_TDRE_MASK));

	/* Send the character */
	LPUART_WR_DATA(uartch, (uint8)ch);
}
/********************************************************************/
/*
 * Check to see if a character has been received
 *
 * Parameters:
 *  uartch      UART channel to check for a character
 *
 * Return values:
 *  0       No character received
 *  1       Character has been received
 */
int uart_getchar_present (LPUART_MemMapPtr uartch)
{
	return (LPUART_STAT_REG(uartch) & LPUART_STAT_RDRF_MASK);
}
/********************************************************************/
