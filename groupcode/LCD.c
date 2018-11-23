#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void DelayFor18TCY(void) //delay
{
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     return;
}

void DelayXLCD(void) //delay
{
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void) //delay
{
    Delay1KTCYx(15);
    return;
}
void LCDinit(void)                  //function to initialize the LCD
{ 
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00); 
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
}


void main(void)         //main function
{
    LCDinit();              //call lcd setup function
    while(BusyXLCD());      //command to stall when the lcd is busy
    putrsXLCD("LCD DISPLAY TEST");    //writes to the screen
    Delay10KTCYx(200);      //Delay to stop flickering on the screen
    while(1);                        
}
