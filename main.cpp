/*
 * podzol.cpp
 *
 * Created: 15.03.2016 13:06:25
 * Author : Matthew Poletin
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Set the Data Direction Register to output
	DDRB |= (1<<5);

	while (true)
	{
		//Set the signal to high
		PORTB = 0b11111111;
		//wait 0.5 sec
		_delay_ms(500);
		//Set the signal to low
		PORTB = 0b000000000;
		//wait 0.5 sec
		_delay_ms(500);
	}

	return 0;
}