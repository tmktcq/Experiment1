#include "UART.h"

void UART_init(volatile UART_t *UART_addr, uint16_t baud_rate)
{
    // Calculate the baud rate reload value 
    //This should set UBRR_value to '103'
    uint16_t UBRR_value = (uint32_t)((((F_CPU / OSC_DIV) + (4UL * (2 - U2X_Val) * baud_rate)) / (8UL * (2 - U2X_Val) * baud_rate)) - 1);
    
    // Write the values to UBRRH, UBRRL and set or clear the U2X bit in UCSRA.
    UART_addr->UART_UBRRH = UBRR_value / 256;
	UART_addr->UART_UBRRL = UBRR_value % 256; 
    UART_addr->UART_UCSRA = (U2X_Val<<U2X); //set u2x here. currently off (0)

    // Determine the value for UCSRC using the settings for number of bits,
    // parity and number of stop bits and write this value. 
    UART_addr->UART_UCSRC = 0x00; // cleared 
	UART_addr->UART_UCSRC = (async_mode_1 | async_mode_2 | no_parity_1 | no_parity_2 | one_stop_bit | eight_bit_data);

    // Enable the transmitter and receiver with interrupts disabled by writing the
    // appropriate value to UCSRB 
	UART_addr->UART_UCSRB = 0x00; //cleared
    UART_addr->UART_UCSRB = (RXCIE_dis | TXCIE_dis | UDRIE_dis | RXEN_en | TXEN_en);
    return; 
}

void UART_transmit(volatile UART_t *UART_addr, uint8_t data)
{
	uint8_t status = 0 ;
	do 
	{
		status = (uint8_t)(UART_addr->UART_UCSRA & (1<<UDRE)); 
		
	} while (status != (1<<UDRE));
	
    UART_addr->UART_UDR = data;
    return;
}

uint8_t UART_receive_nb(volatile UART_t *UART_addr, uint8_t *rcvd_value)
{
    // Check if rxc bit is set, no while loop in order to prevent blocking
    if (UART_addr->UART_UCSRA & ( 1 << RXCn))
    {
        // Byte is available, read it and store in rcvd_value
        *rcvd_value = UART_addr->UART_UDR;
        return 1;  // 1 indicates byte was received
    }
    else
    {
        return 0;  // 0 indicates no byte available
    }
}

uint8_t UART_receive(volatile UART_t *UART_addr)
{
    //1: wait for rxc bit to be set
    while (!(UART_addr->UART_UCSRA & ( 1 << RXCn)));
    //2: return received value
    return UART_addr->UART_UDR;
}