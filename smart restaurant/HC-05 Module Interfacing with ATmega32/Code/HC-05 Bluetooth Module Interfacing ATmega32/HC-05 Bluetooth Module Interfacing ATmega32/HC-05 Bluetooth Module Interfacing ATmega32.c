//**************************************************************//
//Microcontroller			:ATmega32
//System Clock				:8MHz
//Project					:HC-05 Bluetooth Module Interfacing with ATmega32
//Software					:ATmel Studio 6
//USART Baud Rate			:9600
//USART Data Bits			:8
//USART Stop Bits			:1
//USART Mode				:Asynchronous Mode
//USART Parity				:No Parity
//Author					:Arun Kumar Garg
//							:ABLab Solutions
//							:www.ablab.in
//							:info@ablab.in
//Date						:1st June 2015
//**************************************************************//

#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define	F_CPU	8000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

/*USART Function Declarations*/
void usart_init();
void usart_data_transmit(unsigned char data );
void usart_string_transmit(char *string);

/*HC-05 Bluetooth Function Declarations*/
void hc_05_bluetooth_transmit_byte(char data_byte);
void hc_05_bluetooth_transmit_string(char *transmit_string);


int main(void)
{
	_delay_ms(500);
	_delay_ms(500);
	/*Delay of 1s*/
	
	usart_init();
	/*USART initialization*/
	
	hc_05_bluetooth_transmit_string("ABLab Solutions");
	/*Transmits a string to Bluetooth Module*/

	hc_05_bluetooth_transmit_byte(0x0d);
	/*Transmits Carriage return to Bluetooth Module*/
	
	hc_05_bluetooth_transmit_byte(0x0a);
	/*Transmits New Line to Bluetooth Module for new line*/

	hc_05_bluetooth_transmit_string("www.ablab.in");
	/*Transmits a string to Bluetooth Module*/

	hc_05_bluetooth_transmit_byte(0x0d);
	/*Transmits Carriage return to Bluetooth Module*/
	
	hc_05_bluetooth_transmit_byte(0x0a);
	/*Transmits New Line to Bluetooth Module for new line*/
}
/*End of program*/


/*USART Function Definitions*/
void usart_init()
{
	UBRRH = 0;
	UBRRL =51;
	UCSRB|= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1 << URSEL)|(3<<UCSZ0);
}


void usart_data_transmit(unsigned char data )
{
	while ( !( UCSRA & (1<<UDRE)) )
	;
	UDR = data;
	_delay_ms(1);
}

void usart_string_transmit(char *string)
{
	while(*string)
	{
		usart_data_transmit(*string++);
	}
}


/*HC-05 Bluetooth Function Definitions*/
void hc_05_bluetooth_transmit_byte(char data_byte)
{
	usart_data_transmit(data_byte);
}

void hc_05_bluetooth_transmit_string(char *transmit_string)
{
	usart_string_transmit(transmit_string);
}

