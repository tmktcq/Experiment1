/*
 * main.c
 *
 * Created: 8/24/2023 5:26:61 PM
 * Author : tony tim ben
 */ 

#include <avr/io.h>
#include "board.h"
#include "LED.h"
#include "switch.h"

// main uses a polling method to listen to all 4 switches, where each LED lights up depending
// on the respective switch pressed.
int main(void)
{
	LED_Flash_Init();
	switch_Init();
	while (1)
	{
		//poll switches
		if (!switch_Read(SW0_port, SW0_pin))
		{
			LEDS_On(LED0_port, LED0_pin);
			_delay_ms(100);
			LEDS_Off(LED0_port, LED0_pin);
			_delay_ms(400);
		}
		if (!switch_Read(SW1_port, SW1_pin))
		{
			LEDS_On(LED1_port, LED1_pin);
			_delay_ms(100);
			LEDS_Off(LED1_port, LED1_pin);
			_delay_ms(400);
		}
		if (!switch_Read(SW2_port, SW2_pin))
		{
			LEDS_On(LED2_port, LED2_pin);
			_delay_ms(100);
			LEDS_Off(LED2_port, LED2_pin);
			_delay_ms(400);
		}
		if (!switch_Read(SW3_port, SW3_pin))
		{
			LEDS_On(LED3_port, LED3_pin);
			_delay_ms(100);
			LEDS_Off(LED3_port, LED3_pin);
			_delay_ms(400);
		}
	}
	return 0;
}
