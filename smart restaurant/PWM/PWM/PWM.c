/*
 * PWM.c
 *
 * Created: 3/20/2013 9:29:11 PM
 *  Author: SAM
 */ 

#define F_CPU	1000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//double dutyCycle = 0;

int main(void)
{	
	DDRD = (1 << PD6);
	PORTD=(1<<PD6);
	while(1)
	{
		_delay_ms(500);
		PORTD=(0<<PD6);
		_delay_ms(500);
		PORTD=(1<<PD6);
	}
}
/*	
	TCCR1A = (1 << COM1A1) | (1 << WGM00) | (1 << WGM01);
	TIMSK = (1 << TOIE0);
	
	OCR1A = (dutyCycle/100.0)*255.0;
	
	sei();
	
	TCCR1B = (1 << CS00) | (1 << CS02);
	
    while(1)
    {
        //TODO:: Please write your application code
		_delay_ms(100);
		
		dutyCycle += 10;
		
		if(dutyCycle > 100)
		{
			dutyCycle = 0;
		}						
    }
}

ISR(TIMER0_OVF_vect)
{
	OCR1A = (dutyCycle/100.0)*255;
}
*/