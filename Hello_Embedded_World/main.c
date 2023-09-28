/*
 * main.c
 *
 * Created: 8/24/2023 5:26:61 PM
 * Author : tony tim ben
 */ 

//#include <avr/io.h>
#include "board.h"
#include <util/delay.h>
#include "LED.h"
//#include "switch.h"
#include "UART.h"
#include <stdio.h>
#include <avr/pgmspace.h>
#include <string.h>
#include "print_memory.h"

const char string_name[15] PROGMEM = {"Hello World!\n\r\0"};
const char group_members[]  = "Ben Brooks\n\r Tony Lessmeister\n\r Tim Kellermann\n\r"; 
/*-----------------------------------------------------------------------------------

Refer to the print memory source code for an example of declaring a string in
Flash memory. In the initialization area, use the copy_string_to_buffer() function
to copy this string to the print buffer and then transmit it using the
UART_transmit_string() function.

------------------------------------------------------------------------------------*/

// main uses a polling method to listen to all 4 switches, where each LED lights up depending
// on the respective switch pressed.
int main(void)
{
	UART_init(UART0, BAUD_RATE);
	UART_init(UART1, BAUD_RATE);
	UART_init(UART2, BAUD_RATE);
	
	char* print_buffer = export_print_buffer();
			
	while (1)
	{
		
		uint8_t val = UART_receive(UART1);
		UART_transmit(UART1, val);
		UART_transmit(UART1, '\n');
		UART_transmit(UART1, '\r');
		
		/* This uses the string in flash mem to cpy  */ 
		copy_string_to_buffer(string_name, print_buffer, 15); 
		UART_transmit_string(UART1,print_buffer, 15); 
		
		/* this clears the buffer */ 
		memset(print_buffer, 0, sizeof(uint8_t) * 80);
		
		/* This uses sprintf */
		sprintf(print_buffer, "PRINT_BUFFER\n\r");
		UART_transmit_string(UART1, print_buffer, 80);
		
		/* this takes the length of the array and divides it by the size of 1 char 
			why? 
				im too lazy to count them... 
		*/
		print_memory((uint8_t*)group_members, (uint16_t)(sizeof(group_members) / sizeof(uint8_t)) );
		memset(print_buffer, 0, sizeof(uint8_t) * 80);

	}
	return 0;
}
