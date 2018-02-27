/*
 * ultrasonic.h
 *
 * Created: 1/30/2018 1:12:02 PM
 *  Author: sagar
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

char string[10];
long count;
double distance;
int TimerOverflow = 0;

//#define  Trigger_pin   PORTB0;	/* Trigger pin */


ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

void ultrainit(void)
{
	DDRB = 0xFF;		/* Make trigger pin as output */
	PORTD = (1<<PORTD6);		/* Turn on Pull-up */
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;		/* Set all bit to zero Normal operation */
}

int ultra_dist()
{
	/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	PORTB |= (1 << PORTB0);
	_delay_us(10);
	PORTB &= (~(1 << PORTB0));
	
	TCNT1 = 0;	/* Clear Timer counter */
	TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
	TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

	/*Calculate width of Echo by Input Capture (ICP) */
	
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	TCNT1 = 0;	/* Clear Timer counter */
	TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
	TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	TimerOverflow = 0;/* Clear Timer overflow count */
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	count = ICR1 + (65535 * TimerOverflow);	/* Take count */
	/* 16MHz Timer freq, sound speed =340 m/s */
	distance = (double)count / 941.17 ;
	return ((int)distance);
}

#endif /* ULTRASONIC_H_ */