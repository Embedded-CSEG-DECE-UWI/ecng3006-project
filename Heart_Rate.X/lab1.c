/* Lab 1 first file - ID number 81601481 Group G  */
#include <p18f452.h>   

 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF


 void main (void)
{
    int count = 0b0001;
	TRISB = 0;
	while (count <= 0b1111)
	{
		PORTB = count;
		count++; 	
        //Delay1KTCYx(3500);
	}
    
    //Sleep();
}
 
 /*Simplier comment that can be commited*/