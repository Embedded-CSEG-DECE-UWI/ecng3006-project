#include <p18f452.h>
#include "xlcd.h"
#include "delays.h"
#include <timers.h>
#include <stdlib.h>
#include <string.h>
#include "Prototypes.h"

extern long double pNN50;
char hrv_Output1[2];
char heartRateOutput1 [3];
extern int heartRate1;

void HeartRt(void){   
    itoa(heartRate1, heartRateOutput1);

    SetDDRamAddr(0x00);
    putrsXLCD("P_Rate:         ");
    while(BusyXLCD());
    SetDDRamAddr(0x09); 
    putsXLCD(heartRateOutput1);
    while(BusyXLCD());
    SetDDRamAddr(0x0C);
    putrsXLCD(" bpm");
    while(BusyXLCD());
}

void HRV()
{
    itoa(pNN50, hrv_Output1);       
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("HRV:         ");
    while(BusyXLCD());
    SetDDRamAddr(0x4B); 
    putsXLCD(hrv_Output1);
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