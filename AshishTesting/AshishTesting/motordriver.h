
#define flplus PA0
#define flminus PA1
#define frplus PA2
#define frminus PA3
#define blplus PA4
#define blminus PA5
#define brplus PA6
#define brminus PA7


void forward()
{  
	PORTA=(1<<flplus)|(0<< flminus)|(1<<frplus)|(0<<frminus)|(1<<blplus)|(0<< blminus)|(1<< brplus)|(0<<brminus);
	
}
void stop()
{
	PORTA=(0<<flplus)|(0<< flminus)|(0<<frplus)|(0<<frminus)|(0<<blplus)|(0<< blminus)|(0<< brplus)|(0<<brminus);
	
}
void backward()

{
	PORTA=(0<<flplus)|(1<< flminus)|(0<<frplus)|(1<<frminus)|(0<<blplus)|(1<< blminus)|(0<< brplus)|(1<<brminus);

}

void left()
{
	PORTA=(0<<flplus)|(1<< flminus)|(1<<frplus)|(0<<frminus)|(0<<blplus)|(1<< blminus)|(1<< brplus)|(0<<blminus);
}
void right()
{
	PORTA=(1<<flplus)|(0<< flminus)|(0<<frplus)|(1<<frminus)|(1<<blplus)|(0<< blminus)|(0<< brplus)|(1<<brminus);

}