/*
 * main.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Bassant Yasser
 */
#include "ECUAL/Button/Button.h"
#include "MCAL/DIO/DIO.h"

int main()
{
	uint8_t flag = 0;

	DIO_ConfigType config = {PORT_A, P0, OUTPUT};
	DIO_Init(&config);

	config.port = PORT_C;
	config.dir = INPUT;
	DIO_Init(&config);

	DIO_Clear(PORT_A, P0);

	while(1)
	{
		if(Button_Read(PORT_C, P0) == 1)
				{

					if(flag == 0)
					{
						DIO_Toggle(PORT_A, P0); // Toggle value of pin 0 in PORTA (LED Toggle)
						//set the button flag value to 1 to not enter here again until the button is released.
						flag = 1;
					}

				}
				else
				{
					// button is released reset the button flag to value 0 again.
					flag = 0;
				}

	}
}
