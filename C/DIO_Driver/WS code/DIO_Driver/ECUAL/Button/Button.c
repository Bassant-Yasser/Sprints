/*
 * Button.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Bassant Yasser
 */

#include "Button.h"
#include "../../MCAL/DIO/DIO.h"

uint8_t Button_Read (Port port_number, uint8_t pin_number)
{
	return DIO_Read(port_number, pin_number);
}
