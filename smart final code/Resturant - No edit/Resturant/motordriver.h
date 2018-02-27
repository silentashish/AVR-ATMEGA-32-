#include "uart.h"
#include "compass.h"
#include "TWI.h"
#include "ultrasonic[312].h"
#include "math.h"

#define flplus PORTA3
#define flminus PORTA4
#define frplus PORTA5
#define frminus PORTA6
#define blplus PORTA7
#define blminus PORTB1
#define brplus PORTB6
#define brminus PORTB7
#define motor1 PORTA
#define motor2 PORTB



unsigned char sensor_value=0;
long int distances=0;
int count1=0;
int counte=0;
int angle=0;
int angle1=0;
//int ultra[]= {};
void stop(void);

void forward(int meter)
{ 
	
	 print_string("started");
	 print_char('\n');
	 counte=0;
	 distances=0;
	 int errorsum=0;
	 while(distances<=meter)
	 
	 {
		 /*
		 for(int i=0; i++; i<7)
		 {
			int stopdist=ultra_dist();
			ultra[i]= stopdist; 
		 }
		 for(int j=0; j++; j<7)
		 {
			int diff= abs(ultra[0]-ultra[j]);
			errorsum += diff;
		 }
*/
		 //print_ulong(stopdist);
		 //print_char('\n');
		 /*
		 if (stopdist>5 && stopdist<30)
		 {
			 stop();
			 _delay_ms(1000);	 
			 
		 }
		*/ 
		
			sensor_value= PINA0 & 0x01;
			if(sensor_value==0)
			{
				counte++;
				count1=counte/1130;
			}
		
			distances=(int)3.14*11*count1;
		
			//forward code
			motor1=(1<<flplus)|(0<< flminus)|(1<<frplus)|(0<<frminus)|(1<<blplus);
			motor2=(0<< blminus)|(1<< brplus)|(0<<brminus);
		
			print_ulong(distances);
			print_char('\n');
	 }
	 
	 print_string("completed");
	 print_num(meter);
	 print_string(" m");
	 print_char('\n');
	 stop();   
}

void backward()
{
	motor1=(0<<flplus)|(1<< flminus)|(0<<frplus)|(1<<frminus)|(0<<blplus);
	motor2=(0<< blminus)|(0<< brplus)|(1<<brminus);
}
void stop()
{ 
	motor1=(0<<flplus)|(0<< flminus)|(0<<frplus)|(0<<frminus)|(0<<blplus);
	motor2=(0<< blminus)|(0<< brplus)|(0<<brminus);
}

void rightdirection()
{	
	motor1=(1<<flplus)|(0<< flminus)|(0<<frplus)|(1<<frminus)|(1<<blplus);
	motor2=(0<< blminus)|(0<< brplus)|(1<<brminus);
}



void leftdirection()
{
 motor1=(0<<flplus)|(1<< flminus)|(1<<frplus)|(0<<frminus)|(0<<blplus);
 motor2=(1<< blminus)|(1<< brplus)|(0<<brminus);	
}

void rotate(int ang)
{
	if(ang > 0)
	{
	      read_Compass();
	      angle=calculateAngle();
	      print_string("initial angle");
	      print_num(angle);
	      print_char('\n');
	      angle1=angle +ang;
	      if(angle1>360)
	      {
		      angle1-=360;
		      while(angle!=angle1)
		      {
			      rightdirection();
			      read_Compass();
			      angle=calculateAngle();
		      }
	      }
	      
	      while(angle<=angle1)
	      {
		      rightdirection();
		      read_Compass();
		      angle=calculateAngle();
	      }
	      if(angle==angle1)
	      {
		      print_string("final angle");
		      print_num(angle);
		      print_char('\n');
	      }
	      angle1=0;
	}
	else
	{
			read_Compass();
			angle=calculateAngle();
			print_string("initial left angle");
			print_num(angle);
			print_char('\n');
			angle1=angle +ang;
			if(angle1<0)
			{
				angle1+=360;
				while(angle!=angle1)
				{
					leftdirection();
					read_Compass();
					angle=calculateAngle();
				}
			}
			
			while(angle>=angle1)
			{
				leftdirection();
				read_Compass();
				angle=calculateAngle();
			}
			if(angle==angle1)
			{
				print_string("final angle");
				print_num(angle);
				print_char('\n');
			}
			angle1=0;
	}
}