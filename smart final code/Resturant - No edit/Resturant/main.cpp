/*
 * Resturant.cpp
 *
 * Created: 1/30/2018 4:48:21 PM
 * Author : silentashish
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "motordriver.h"
#include "uart.h"
//#include "pwm.h"
#include "ultrasonic[312].h"


//unsigned char ultra[]= {0,0,0,0,0,0,0};
int main(void)
{ 
	DDRA=(1<<PORTA7)|(1<<PORTA6)|(1<<PORTA5)|(1<<PORTA4)|(1<<PORTA3)|(0<<PINA2)|(0<<PINA1)|(0<<PINA0);
	PORTA=(0<<PORTA7)|(0<<PORTA6)|(0<<PORTA5)|(0<<PORTA4)|(0<<PORTA3);
	DDRB=(1<<PORTB0)|(1<<PORTB6)|(1<<PORTB7)|(1<<PORTB3);
	PORTB=(0<<PORTB1)|(0<<PORTB2)|(0<<PORTB3)|(0<<PORTB7);
	DDRD=(1<<PORTD5);
	
	PORTD = (1<<PORTD4);
	DDRD &= ~(1<<PIND4);
	//pwm_init();
	uart_init();
	ultrainit();
	init_QMC5883L();
	int dist=0;
	int stopdist=0;
	int angle;
	MCUCSR=(1<<JTD);
	MCUCSR=(1<<JTD);
	unsigned char status=0;
while(1)
 {
   unsigned char  c= uart_receive();
	switch(c)
	{
	 case '1':
			status= PIND & (1 << PIND4);
	 		print_char(status);
			print_string("Inside the loop ");
			break;	
	case '2':
		forward(150);
		rotate(-90);
		forward(75);
		rotate(180);
		forward(50);
		rotate(90);
		forward(150);
		break;
	case '3':
		rotate(-90);
		rotate(-180);
		break;
	case '4':
		forward(150);
		rotate(-90);
		forward(50);
		rotate(180);
		forward(50);
		rotate(90);
		forward(150);
		break;
	}
stop();
}
//Ultrasound array not working
/*
while(1)
{
	unsigned char c= uart_receive();
	switch(c)
	{
		case '1':
		/*
			int errorsum=0;
			for(int i=0; i++; i<7)
			{
				ultra[i]= ultra_dist();
				print_char(ultra[i]);
				print_char('\n');
				_delay_ms(10);
			}
			for(int j=0; j++; j<7)
			{
				int diff= abs((int)ultra[0]-(int)ultra[j]);
				errorsum += diff;
			}
			if(errorsum<17)
			{
				print_string("i am stoped ");
				print_char('\t');
				print_num(errorsum);
				print_char('\n');
				_delay_ms(200);
			}
			else
			{
				print_string(" I walk free into the blues");
				print_char('\n');
			}
			break;
	}
}
*/
}