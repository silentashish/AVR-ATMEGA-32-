/*
 * AshishTesting.c
 *
 * Created: 26-Jan-18 11:01:11 PM
 * Author : Toshiba
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "motordriver.h"
#include "lcd.h"


int main(void)
{
	DDRA=0xFF;
	PORTA=0x00;
	DDRB=0x00;
	unsigned char sensor_value=0;
	lcd_init();
	lcd_puts("Running LCD");
	_delay_ms(1000);
	lcd_clear();
	int count=0;
	int n=0;
	int count1=0;
	
    /* Replace with your application code */
    while (1) 
    {
		sensor_value=PINB & 0x01;
		
		if(sensor_value==0)
		{
			PORTA=0x01;
			lcd_goto(0);
			lcd_puts("Sensing    ");
			/*String display in 2nd row of LCD*/
			count++;
			count1=(int)count/5.5;
			lcd_unum(count);
			
			
		}
		lcd_goto(64);
		lcd_unum(count1);
		n++;

    }
	
	PORTA=0x00;
	return 0;
	
}

