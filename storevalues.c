
#include    <timers.h>
#include    <p18f452.h>
#include    <p18cxxx.h>
#include    "xlcd.h" 
#include    <stdlib.h>
#include    <adc.h>
#include    <delays.h>
#include    <capture.h>
#include    <portb.h>


extern int i;


void scroll (void)
{
    
    if (i>=3){i=0;}
    OpenXLCD( FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "Hello World" );//array temp[i]
    
    
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "Hello World" );//array glucose[i]
    
    
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "Hello World" );//array heartrate [i]
    
   
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putsXLCD( hrv2[i] );//array hrv[i]
    i++;
    
    }


