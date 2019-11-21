#include <p18f452.h>
#include "xlcd.h"
#include "delays.h"
#include <timers.h>
#include <stdlib.h>
#include <string.h>

void HRV()
{
    SetDDRamAddr(0x40);
    putrsXLCD("HRV:         ");
    while(BusyXLCD());
    SetDDRamAddr(0x4C); 
    putrsXLCD("80");
    while(BusyXLCD());
    SetDDRamAddr(0x4E);
    putrsXLCD(" %");
    while(BusyXLCD());
}

void Glucose()
{
   SetDDRamAddr(0x10);
    putrsXLCD("Gluc:           ");
    while(BusyXLCD());
    SetDDRamAddr(0x17); 
    putrsXLCD("85");
    while(BusyXLCD());
    SetDDRamAddr(0x1A);
    putrsXLCD(" mg/dL");
    while(BusyXLCD());
}