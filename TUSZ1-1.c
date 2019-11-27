#include    <pic18f452.h>
#include    "xlcd_GpE.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

void main (void){
    initLCD();
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("Plus Ultra");
    while(BusyXLCD());
    SetDDRamAddr(0x4C);
    while(BusyXLCD());
    putrsXLCD("3358");
    while(BusyXLCD());
    SetDDRamAddr(0x12);
    while(BusyXLCD());
    putrsXLCD("!&*");
    while(BusyXLCD());
    SetDDRamAddr(0x54);
    while(BusyXLCD());
    putrsXLCD("FreeRTOS");
    Sleep();
}