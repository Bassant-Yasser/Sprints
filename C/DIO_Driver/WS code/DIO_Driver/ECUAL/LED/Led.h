/*
 * Led.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Yasser
 */

#ifndef ECUAL_LED_LED_H_
#define ECUAL_LED_LED_H_

#include "../../std_types.h"

void Led_On(Port port_number, uint8_t pin_number);
void Led_Off(Port port_number, uint8_t pin_number);
void Led_Toggle(Port port_number, uint8_t pin_number);

#endif /* ECUAL_LED_LED_H_ */
