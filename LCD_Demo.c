#include    <pic18f452.h>
#include    "xlcd_GpE.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

void main (void){
    initLCD();
    while(BusyXLCD());              //Wait for the LCD to become available
    SetDDRamAddr(0x00);             //Sets the address to start printing the data
    while(BusyXLCD());
    putrsXLCD("This is a demo");    //Actual data being displayed on the LCD
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("This is line 2");
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    putrsXLCD("This is line 3");
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    putrsXLCD("This is line 4");
    Sleep();
}