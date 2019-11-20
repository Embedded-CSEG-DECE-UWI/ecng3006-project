/*Lab 1 first file  - ID number 816002585 Group G */
#include <p18f452.h>   
#include <delays.h>
 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

 int i = 0b0001;
 void main (void)
{
     PORTB = 0;
     TRISB = 0;  //Set PORTB pins as output
     while (i <= 0b1111)
     {
         PORTB=i;
         i++;
         Delay1KTCYx(5000);

     }
     
}
 /*simple comment  */
