/*
 * main.c
 *
 * Created: 8/24/2023 5:26:61 PM
 * Author : tony tim ben
 */ 

#include <avr/io.h>
#include "delay_function.h"
#include <util/delay.h> 
#include "LED.h"
#include "gpio_output.h"


#define LED_bit (7)
unsigned char LED_State_g;

void LED_Flash_Init(void);
void LED_Flash_Change_State(void);



int main(void)
{
	LED_Flash_Init();
    while (1) 
    {
		_delay_ms(DELAY);
		LED_Flash_Change_State();
		_delay_ms(DELAY);
	}
}

void LED_Flash_Init(void)
{
	GPIO_Output_Init(LED0_port, LED0_pin);
	GPIO_Output_Init(LED0_port, LED0_pin); //FIXME
	GPIO_Output_Init(LED0_port, LED0_pin); //FIXME

	DDRC |=(1<<LED_bit);
	PORTC &=~(1<<LED_bit);
	LED_State_g=0;
}

void LED_Flash_Change_State(void)
{
	if(LED_State_g==0)
	{
		PORTC |=1<<LED_bit;
		LED_State_g=1;
	}
	else
	{
		PORTC &=~1<<LED_bit;
		LED_State_g=0;
	}
}




