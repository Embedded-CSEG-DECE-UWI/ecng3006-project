#include <p18f452.h>
#include <delays.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "1wire.h"
#include "xlcd.h"

// -------------- Variables ----------------------

unsigned char Scratchpad_MSB;
unsigned char Scratchpad_LSB;

unsigned int MSB_val = 0;
unsigned int LSB_val =0;

unsigned int Temperature_Int = 0;
int Fraction_Int =0;
float Fraction = 0.0000;

unsigned char degree = 0xDF;
int sign = 0;
int x;

char Temperature_Display[20];

// ------------ Temperature function -----------------
void Temperature_Task(void)
{
 
    ow_reset();                     //reset 1822P
        
    ow_write_byte(0xCC);            // Skip ROM Check
    ow_write_byte(0x44);            // Convert temperature
    
    for(x = 1 ; x<=8 ; x++)       // Wait for conversion time (800ms)
    {
        Delay1KTCYx(100);
    }

    ow_reset();                     //reset device
    ow_write_byte(0xCC);            //skip ROM check
    ow_write_byte(0xBE);            //Read scratchpad

    Scratchpad_LSB = ow_read_byte();   // Read temperature LSB
    Scratchpad_MSB = ow_read_byte();   //Read temperature MSB
        
    // Convert temperature value
    LSB_val = Scratchpad_LSB >> 4; 
    MSB_val = Scratchpad_MSB << 4;
    Temperature_Int = MSB_val | LSB_val;
        
    // Convert temperature fraction
    if(Scratchpad_LSB & 0x01){Fraction += 0.0625;}
    if(Scratchpad_LSB & 0x02){Fraction += 0.125;}
    if(Scratchpad_LSB & 0x04){Fraction += 0.25;}
    if(Scratchpad_LSB & 0x08){Fraction += 0.5;}
    Fraction_Int = Fraction*10000;

    // Sign
    sign = ((Scratchpad_MSB >> 3 )& 0x3F);
    if(sign == 0)
    {
        sprintf(Temperature_Display,"+%d.%03d%cC",Temperature_Int,Fraction_Int,degree);
    }
    else
    {
        sprintf(Temperature_Display,"-%d.%03d%cC",Temperature_Int,Fraction_Int,degree);
    }
     
    // Display
    while(BusyXLCD());
    SetDDRamAddr(0x00);             // Write to line 1
    putsXLCD(Temperature_Display);
    
}
