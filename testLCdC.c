#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>



#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

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
}
void DelayXLCD(void){
    Delay1KTCYx(5); //cycles = ((timedelay * FOSC)/4)/1000
                    //cycles = ((5ms * 4MHz)/4)/1000
                    //cycles = (5000)/1000
                    //cycles = 5
}

void DelayPORXLCD(void){
    Delay1KTCYx(15); //cycles = ((timedelay * FOSC)/4)/1000
                    //cycles = ((15ms * 4MHz)/4)/1000
                    //cycles = (15000)/1000
                    //cycles = 15
}
void main (void){
   
    //configure external LCD
    OpenXLCD( FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());

    putrsXLCD( "Hello World" );
    while(BusyXLCD());
    Sleep();
    
}
