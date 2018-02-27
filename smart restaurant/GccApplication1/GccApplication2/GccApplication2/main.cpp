
#define F_CPU 16000000UL //16MHz EXTERNAL CLOCK

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
void USART_Init(void);
unsigned char USART_RXC(void);
//volatile unsigned char value;  //FOR STORING RECIEVE DATA
int main(void){
	MCUCSR=(1<<JTD);
	MCUCSR=(1<<JTD);
	
   USART_Init();  // Initialise USART
   _delay_ms(100);
  // sei();         // enable all interrupts
   DDRA |= (1<<PA6)|(1<<PA7);
   PORTA|=(0<<PA6);
   for(;;){
	  // while(!(UCSRA & (1<<RXC)));    // Repeat indefinitely
         char value = USART_RXC();
		 if(value=='a') // may be other characters 
		
		{PORTA |= 1<<PA6; // Put LED in pin B7
		_delay_ms(2000);
		PORTA |= (0<<PA6);
		}
		
	}
	
	
		
		// if(value = '2'){ // may be other characters
			// PORTA |= 1<<7; // Put LED in pin B7
			 //delay_ms(2000);
			// PORTA |= 0<<7;
	//}
             	         
   }
	/*MCUCSR=(1<<JTD);
	MCUCSR=(1<<JTD);
	DDRB=0xFF;
	PORTB = 0x00;
	while(1)
	{
		PORTB=0x01;
		_delay_ms(100);
		PORTB=0x00;
		_delay_ms(50);
	}*/

void USART_Init(void){
	UBRRH = 0;
	UBRRL = 6;
	UCSRB = ((1<<TXEN)|(1<<RXEN)|(1<<RXCIE));
	UCSRC = ((1<<URSEL)|(3<<UCSZ0));
}
/* Interrupt Service Routine for Receive Complete*/
//ISR(USART_RXC_vect){
	
	//value = UDR;             //read UART register into value
	//}

unsigned char USART_RXC(void)
{
	while (!(UCSRA &(1<<RXC)));
	return(UDR);
		
	
}
