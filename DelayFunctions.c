#include <p18f452.h>
#include <delays.h>
#include "xlcd_GpE.h"


void DelayFor18TCY( void )
{
    Nop();  Nop();  Nop();  Nop();  Nop();  Nop();  Nop();  Nop();  
    Nop();  Nop();  Nop();  Nop();  Nop();  Nop();  Nop();  Nop();
    Nop();  Nop();  
  
}

void DelayPORXLCD (void)
{
  /* Create a delay of 15 ms  */ 
    Delay1KTCYx(15);
}

void DelayXLCD (void)
{
  /* Create a delay of 5 ms  */  
    Delay1KTCYx(5);
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
