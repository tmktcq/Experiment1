#include "LED.h"
#include "gpio_output.h"

LEDS_Init(volatile GPIO_port_t * Port_addr, uint8_t LED_pin)
{
  GPIO_Output_Init(Port_addr,LED_pin); // Also set an initial state
}

LEDS_Off(volatile GPIO_port_t * Port_addr, uint8_t LED_pin)
{
  GPIO_Output_Set(Port_addr,LED_pin); //func calls func to execute
}

LEDS_On(volatile GPIO_port_t * Port_addr, uint8_t LED_pin)
{
  GPIO_Output_Clear(Port_addr,LED_pin);
}
// With inline function, func called to execute