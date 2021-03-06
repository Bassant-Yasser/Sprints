/*
 * DIO.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Yasser
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../std_types.h"
#include "../../registers.h"

//typedef enum
//{
//	PORT_A, PORT_B, PORT_C, PORT_D
//}Port;

typedef enum
{
	INPUT, OUTPUT
}Direction;


typedef struct
{
	Port port;
	uint8_t pin_number;
	Direction dir;
}DIO_ConfigType;

void DIO_Init (const DIO_ConfigType *Config_Ptr);
void DIO_Set ( Port port_number, uint8_t pin_number);
void DIO_Clear ( Port port_number, uint8_t pin_number);
void DIO_Toggle ( Port port_number, uint8_t pin_number);
uint8_t DIO_Read ( Port port_number, uint8_t pin_number);


#endif /* MCAL_DIO_DIO_H_ */
