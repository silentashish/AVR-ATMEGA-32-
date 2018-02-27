#ifndef
#define flplus PB0
#define flminus PB1
#define frplus PB2
#define frminus PB3
#define blplus PB4
#define blminus PB5
#define brplus PB6
#define brminus PB7
#define MOTOR_PINS PORTB
DDRB=0xFF;
void forward()
{   
	PORTB|=(1<<flplus)|(0<< flminus)|(1<<frplus)|(0<<frminus);
	_delay_ms(2000);
	PORTB|=(1<<blplus)|(0<< blminus)|(1<< brplus)|(0<<brminus);
	_delay_ms(2000);
}
void backward()

{
	PORTB|=(0<<flplus)|(1<< flminus)|(0<<frplus)|(1<<frminus);
	_delay_ms(2000);
	PORTB|=(0<<blplus)|(1<< blminus)|(0<< brplus)|(1<<brminus);
	_delay_ms(2000);
}

void left()
{
	PORTB|=(0<<flplus)|(1<< flminus)|(1<<frplus)|(0<<frminus);
	_delay_ms(2000);
	PORTB|=(0<<blplus)|(1<< blminus)|(1<< brplus)|(0<<blminus);
	_delay_ms(2000);
}
void right()
{
	PORTB|=(1<<flplus)|(0<< flminus)|(0<<frplus)|(1<<frminus);
	_delay_ms(2000);
	PORTB|=(1<<blplus)|(0<< blminus)|(0<< brplus)|(1<<brminus);
	_delay_ms(2000);
}
#endif