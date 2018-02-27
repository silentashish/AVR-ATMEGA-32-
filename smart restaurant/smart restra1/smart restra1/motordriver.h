
#define flplus PB0
#define flminus PB1
#define frplus PB2
#define frminus PB3
#define blplus PB4
#define blminus PB5
#define brplus PB6
#define brminus PB7
#define motor PORTB



void forward()
{  
	motor=(1<<flplus)|(0<< flminus)|(1<<frplus)|(0<<frminus)|(1<<blplus)|(0<< blminus)|(1<< brplus)|(0<<brminus);
	
}
void stop()
{
	motor=(0<<flplus)|(0<< flminus)|(0<<frplus)|(0<<frminus)|(0<<blplus)|(0<< blminus)|(0<< brplus)|(0<<brminus);
	
}
void backward()

{
	motor=(0<<flplus)|(1<< flminus)|(0<<frplus)|(1<<frminus)|(0<<blplus)|(1<< blminus)|(0<< brplus)|(1<<brminus);

}

void left()
{
	motor=(0<<flplus)|(1<< flminus)|(1<<frplus)|(0<<frminus)|(0<<blplus)|(1<< blminus)|(1<< brplus)|(0<<blminus);
}
void right()
{
	motor=(1<<flplus)|(0<< flminus)|(0<<frplus)|(1<<frminus)|(1<<blplus)|(0<< blminus)|(0<< brplus)|(1<<brminus);

}