#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "table1.h"

int distances;
int count1=0;



int countDist(int count)
{
	if(sensor_value==0)
	{
		count++;
		count1=count/5.5;
	}
	distances=(int)3.14*11*count1;
	return (distances);
}

int main(void)
{   
	sei();
	DDRC=0x00;
	DDRB=0xFF;
	PINC=0xAA;
	DDRA|=(0<<PA0);
	
	MCUCSR=(1<<JTD);
	MCUCSR=(1<<JTD);
	ultrainit();  //initializing  ultrasonic 
	uart_init(); //initializing bluetooth
	init_HMC5883L();
	char order=uart_receive(); // read the bluetooth data 
	while(1)
	{
		switch(order)
		{
			case(1):
				Table1();
				break;
			
			default:
				break;
		}
	}		
}