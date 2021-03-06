/*
 * Led.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Yasser
 */

#include "Led.h"
#include "../../MCAL/DIO/DIO.h"

void Led_On(Port port_number, uint8_t pin_number)
{
	DIO_Set(port_number, pin_number);
}
void Led_Off(Port port_number, uint8_t pin_number)
{
	DIO_Clear(port_number, pin_number);
}

void Led_Toggle(Port port_number, uint8_t pin_number)
{
	DIO_Toggle(port_number, pin_number);
}
