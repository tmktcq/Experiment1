/*
 * LED.h
 *
 * Created: 9/11/2023 1:38:42 PM
 *  Author: tim tony ben
 */

#include "board.h"
#include "gpio_output.h"

#ifndef LED_H
#define LED_H

void LEDS_Init(volatile GPIO_port_t *port_addr, uint8_t LED_pin);
void LEDS_Off(volatile GPIO_port_t *port_addr, uint8_t LED_pin);
void LEDS_On(volatile GPIO_port_t *port_addr, uint8_t LED_pin); 
void LED_Flash_Init(void);
void LED_Flash_Change_State(void); 

#define LEDON (0)
#define LEDOFF (1)

#define LED0_port PC 
#define LED0_pin (1<<7) 

#define LED1_port PB 
#define LED1_pin (1<<3)

#define LED2_port PE
#define LED2_pin (1 << 4)

#define LED3_port PA
#define LED3_pin (1 << 7)

#endif