/* Set configuration bits for use with PICKit3 */
#include <p18f452.h> 
#include <stdlib.h>
#include <stdio.h>
#include <delays.h>
#include <timers.h>
//#include "xlcd.h"

 /*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system should allow a user to start storing a pre-de?ned set of measurements to external ?ash RAM, and to interrupt the ongoing storage of a set of measurements.

/*
 Hardware related definition
 */
//#define _XTAL_FREQ 20000000 //Crystal Frequency, used in delay
#define DATA_595 PORTAbits.RA0
#define CLK_595 PORTAbits.RA1
#define LED PORTBbits.RA3

/*
 Other Specific definition
 */
void system_init(void);

/*
 *This function will enable the Clock.
 */
void clock(void){
    CLK_595 = 1;
    Delay100TCYx(1);
    CLK_595 = 0;
    Delay100TCYx(1);
}

/*
 * This function will send the data to shift register
 */
void data_submit(unsigned int data)
{
    int i;
    for (i=0 ; i<16 ; i++)
    {
        DATA_595 = (data >> i) & 0x01;
        clock();
    }
    //strobe(); // Data finally submitted 
}

void main(void) {
  
    system_init(); // System getting ready    
    while(1)
    {
        // unsigned int i = 0;
        // while(i<=65535)
        // {
        //   data_submit(i);
        //   Delay10KTCYx(1);
        //   i++;
        // }   
        
        data_submit(0xFFFF);      
        Delay10KTCYx(100);
     }
    return;
    }
    
/*
 This Function is for system initialisations.
 */

void system_init(void)
{
  TRISA = 0x00;   
}