

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//define the PB0 as the input and connect the output of the IR sensor in to it's
//count is for counting the number of the pulses came in the Sensor
int n=0;
int distance;
int count1=0;
unsigned char sensor_value=0;



int countDist(int count)

{   DDRA=0x00;
	sensor_value= (PINA & 0x01);
	
	if(sensor_value==0)
	{
		count++;
		count1=count/5.5;
	}
	distance=(int)3.14*11*count1;
	return distance;
	
	
}