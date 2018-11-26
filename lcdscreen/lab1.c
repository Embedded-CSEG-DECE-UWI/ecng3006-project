/* Lab 1 first file - ID number 816002558 Group d  */
#include <p18f452.h> 
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

/* Insert code from pre-lab Q14 to change values on PORTB */
 void main (void)
{
     int count = 0;
     
     TRISB = 0;
        for(count = 0; count <= 15; count++)
        {
        PORTB = count;  //displays count
        Nop();  
        Delay10KTCYx (100);
    }
 }