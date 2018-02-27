#include <avr/io.h>
#include <util/delay.h>

int n=0;
int distance;
int dist=0;
int count1=0;
int count=0;
unsigned char sensor_value=0;



int countDist(int count)
{
	if(sensor_value==0)
	{
		count++;
		count1=count/5.5;
	}
	distance=(int)3.14*11*count1;
	return distance;
}
