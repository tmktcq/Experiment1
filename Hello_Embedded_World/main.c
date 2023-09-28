/*
 * main.c
 *
 * Created: 8/28/2023 5:26:61 PM
 * Author : tony tim ben
 */ 

//#include <avr/io.h>
#include "board.h"
#include <util/delay.h>
#include "LED.h"
//#include "switch.h"
#include "UART.h"


int main(void)
{
	// uint32_t BAUD_RATE = 9600; 
	UART_init(UART0, BAUD_RATE);
	UART_init(UART1, BAUD_RATE);
	UART_init(UART2, BAUD_RATE);
	
	while (1)
	{
		//exp2 - transmits
		UART_transmit(UART0, 0x55);
        UART_transmit(UART1, 0x48); //H
        UART_transmit(UART1, 0x65); //e
        UART_transmit(UART1, 0x6C); //l
        UART_transmit(UART1, 0x6C); //l
        UART_transmit(UART1, 0x6F); //o
        UART_transmit(UART1, 0x20); //space
        UART_transmit(UART2, 0x55);
        _delay_ms(1000);
	}
	return 0;
}
