#include"xlcd_GpE.h"
#include<delays.h>

/* Write LCD delay functions */
void DelayFor18TCY(void)
{
    Delay10TCYx(2);
    return;
}

void DelayPORXLCD(void)
{  
    Delay1KTCYx(15); /* Create a delay of 15 ms  */
    return;
}

void DelayXLCD(void)
{
    Delay1KTCYx(5); /* Create a delay of 5 ms  */
    return;
}

void InitLCD (void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
}
