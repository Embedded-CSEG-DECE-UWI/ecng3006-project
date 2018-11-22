#include"xlcd.h"
#include<delays.h>

/* Write LCD delay functions */
void DelayFor18TCY(void)
{
    Nop();Nop();Nop();Nop();
    Nop();Nop();Nop();Nop();
    Nop();Nop();Nop();Nop();
    Nop();Nop();
    return;
}

void DelayPORXLCD(void)
{  
    Delay1KTCYx(15); /* Create a delay of 15 ms  */
}

void DelayXLCD(void)
{
    Delay1KTCYx(5); /* Create a delay of 5 ms  */
}

void InitLCD (void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
}