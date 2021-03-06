/*
 * DIO.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Bassant Yasser
 */


#include "DIO.h"

void DIO_Init (const DIO_ConfigType *Config_Ptr)
{
	switch(Config_Ptr->port)
	{
	case PORT_A:
		PORTA_DIR = (PORTA_DIR & (1<<Config_Ptr->pin_number)) | (Config_Ptr->dir<<Config_Ptr->pin_number);
		break;
	case PORT_B:
		PORTB_DIR = (PORTB_DIR & (1<<Config_Ptr->pin_number)) | (Config_Ptr->dir<<Config_Ptr->pin_number);
		break;
	case PORT_C:
		PORTC_DIR = (PORTC_DIR & (1<<Config_Ptr->pin_number)) | (Config_Ptr->dir<<Config_Ptr->pin_number);
		break;
	case PORT_D:
		PORTD_DIR = (PORTD_DIR & (1<<Config_Ptr->pin_number)) | (Config_Ptr->dir<<Config_Ptr->pin_number);
		break;
	}
}

void DIO_Set ( Port port_number, uint8_t pin_number)
{
	switch(port_number)
	{
	case PORT_A:
		PORTA_OUT |= (1<<pin_number);
		break;
	case PORT_B:
		PORTB_OUT |= (1<<pin_number);
		break;
	case PORT_C:
		PORTC_OUT |= (1<<pin_number);
		break;
	case PORT_D:
		PORTD_OUT |= (1<<pin_number);
		break;
	}
}

void DIO_Clear ( Port port_number, uint8_t pin_number)
{
	switch(port_number)
	{
	case PORT_A:
		PORTA_OUT &= ~(1<<pin_number);
		break;
	case PORT_B:
		PORTB_OUT &= ~(1<<pin_number);
		break;
	case PORT_C:
		PORTC_OUT &= ~(1<<pin_number);
		break;
	case PORT_D:
		PORTD_OUT &= ~(1<<pin_number);
		break;
	}
}

void DIO_Toggle ( Port port_number, uint8_t pin_number)
{
	switch(port_number)
	{
	case PORT_A:
		PORTA_OUT ^= (1<<pin_number);
		break;
	case PORT_B:
		PORTB_OUT ^= (1<<pin_number);
		break;
	case PORT_C:
		PORTC_OUT ^= (1<<pin_number);
		break;
	case PORT_D:
		PORTD_OUT ^= (1<<pin_number);
		break;
	}
}

uint8_t DIO_Read ( Port port_number, uint8_t pin_number)
{
	switch(port_number)
	{
	case PORT_A:
		return PORTA_IN & (1<<pin_number);
		break;
	case PORT_B:
		return PORTB_IN & (1<<pin_number);
		break;
	case PORT_C:
		return PORTC_IN & (1<<pin_number);
		break;
	case PORT_D:
		return PORTD_IN & (1<<pin_number);
		break;
	default:
		return -1;
	}
}
