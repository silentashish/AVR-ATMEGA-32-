#ifndef 
#define F_CPU 16000000
#define BAUD 9600
#define BAUDPRESCALE ((F_CPU/(16UL*BAUD))-1)
void uart_init(void)
{
	UBRRH=(8>>BAUDPRESCALE);
	UBRRL= (BAUDPRESCALE);
	UCSRB= (1<<RXEN);
	UCSRC=(1<<URSEL)|(3<<UCSZ0);
}
unsigned char uart_receive()
{
	while(!(UCSRA & (1<<RXC)));
	return(UDR);
}
void uart_transmit(char data)
{
	while(!(UCSRA &(1<<UDRE)));
	UDR = data;
}
#endif