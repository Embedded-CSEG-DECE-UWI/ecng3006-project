#include <p18f452.h> 
#include "delays.h"
#include "xlcd.h"

//Function Prototypes
void LcdSetup(void);

void DelayFor18TCY(void){
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

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}
void LcdSetup(void)                                                 //Setup for the LCD
{ 
    while( BusyXLCD());
    OpenXLCD(FOUR_BIT & LINES_5X7); 
    while( BusyXLCD());
    WriteCmdXLCD( FOUR_BIT & LINES_5X7);
    while( BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT);
    while (BusyXLCD());
}

void MenuMain(void)
{
        SetDDRamAddr(0x00); 
        putrsXLCD("~~~~~~MENU~~~~~~");
        while(BusyXLCD());
        SetDDRamAddr(0x40);
        putrsXLCD("Live Readings  A");
        while(BusyXLCD());
        SetDDRamAddr(0x10);
        putrsXLCD("Set Intervals  B");
        while(BusyXLCD());
        SetDDRamAddr(0x50);
        putrsXLCD("Records        C");
        while(BusyXLCD());
}
