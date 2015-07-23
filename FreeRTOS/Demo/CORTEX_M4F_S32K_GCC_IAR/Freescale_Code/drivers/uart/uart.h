/*
 * File:		uart.h
 * Purpose:		Provide common ColdFire UART routines for polled serial IO
 *
 * Notes:
 */

#ifndef __UART_H__
#define __UART_H__

/********************************************************************/

void uart_init (LPUART_MemMapPtr, int, int);
char uart_getchar (LPUART_MemMapPtr);
void uart_putchar (LPUART_MemMapPtr, char);
int uart_getchar_present (LPUART_MemMapPtr);

/********************************************************************/

#endif /* __UART_H__ */
