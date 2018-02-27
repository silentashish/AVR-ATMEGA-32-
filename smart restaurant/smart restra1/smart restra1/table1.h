#define F_CPU 16000000UL

#include <avr/io.h>
#include "lcd.h"
#include "motordriver.h"
#include "ultrasonic[312].h"
#include "TWI.h"
#include "compass.h"


int dist=0;
int stopdist=0;
int angle;
unsigned char sensor_value=0;
int count;

void Table1(void)
{	
	while(dist!=300)
		{    
			sensor_value=PINA & 0x01;
			stopdist= (int)ultra_dist();
			if(stopdist<50)
			{
				stop();
				//space left for buzzercall
			}
			else
			{
				lcd_goto(70);
				lcd_unum(dist);
				forward();
				dist=countDist(count);
			}
		}
		count=0;
		read_Compass();
		angle=calculateAngle();
		int angle1=angle +90;	
		while(angle<=angle1)
		{
			left();
			read_Compass();
			angle=calculateAngle();
		}
}