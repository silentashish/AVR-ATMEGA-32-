#include<avr/io.h>
#include<util/interrupt.h>
#include<util/delay.h>

#define DataPort PORTC
#define DataDDR DDRC

ISR(INT0_vect)
{
	count ++;

}

