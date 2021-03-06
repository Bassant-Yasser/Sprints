/*
 * main.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Bassant Yasser
 */

#include <avr/io.h>

/* Description :
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter = 156  0 --> 255 (100ms per overflow)
 */
void timer0_init_normal_mode(void)
{
	TCNT0 = 256-100; //Set Timer initial value to 156
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
}

int main()
{
	timer0_init_normal_mode();
	uint8_t g_tick = 0;
	DDRC |= (1<<PC0);
	PORTC &= ~(1<<PC0);

	while(1)
	{
		while((TIFR & (1<<TOV0)) == 0);
		TIFR |= (1<<TOV0);
		g_tick++;
		if(g_tick == 3)
		{
			PORTC &= ~(1<<PC0);
		}
		else if(g_tick == 5)
		{
			PORTC = PORTC | (1<<PC0);
			g_tick = 0;
		}
		TCNT0 = 256-100;
	}
}
