/*
 * registers.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Bassant Yasser
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_


#define PORTA_DIR	*((volatile uint8_t*)(0x3A))
#define PORTB_DIR	*((volatile uint8_t*)(0x37))
#define PORTC_DIR	*((volatile uint8_t*)(0x34))
#define PORTD_DIR	*((volatile uint8_t*)(0x31))

#define PORTA_OUT	*((volatile uint8_t*)(0x3B))
#define PORTB_OUT	*((volatile uint8_t*)(0x38))
#define PORTC_OUT	*((volatile uint8_t*)(0x35))
#define PORTD_OUT	*((volatile uint8_t*)(0x32))

#define PORTA_IN	*((volatile uint8_t*)(0x39))
#define PORTB_IN	*((volatile uint8_t*)(0x36))
#define PORTC_IN	*((volatile uint8_t*)(0x33))
#define PORTD_IN	*((volatile uint8_t*)(0x30))

#define P0			0
#define P1			1
#define P2			2
#define P3			3
#define P4			4
#define P5			5
#define P6			6
#define P7			7


#endif /* REGISTERS_H_ */
