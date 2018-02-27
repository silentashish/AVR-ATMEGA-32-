#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#define BAUD_RATE		9600
#define UBBR_VALUE		((F_CPU/(16*BAUD_RATE)))-1

void uart_init(void);
void uart_transmit(char);



volatile unsigned char value;  //FOR STORING RECIEVE DATA
int main(void){
	
	uart0_init(UART_BAUD_SELECT(38400,F_CPU));  // Initialise USART
	_delay_ms(100);
	sei();         // enable all interrupts
	for(;;){
		uart0_puts("Hello\n");
		
		//uart_transmit( value);
		_delay_ms(500);
		
		
	}
}

//char receive_data()
//{
//return value;
//}
/* Interrupt Service Routine for Receive Complete*/
//ISR(USART_RXC_vect){
	
//	value = UDR;             //read UART register into value
//}
void uart_transmit(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	
	UDR= value;
	
}
void uart_init(void)
{
	UBRRH=((unsigned char)((UBBR_VALUE)>>8));
	UBRRL=(unsigned char)UBBR_VALUE;
	UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC=(1<<URSEL)|(3<<UCSZ0);
}
