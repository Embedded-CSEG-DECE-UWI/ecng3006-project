#include <p18f452.h>
#include <delays.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "xlcd.h"

// ------------ scroll display --------------
int HR[8]={60,72,90,55,77,88,79,91};
int scroller = 0;
char value[16];
// ------------------------------------------

void inc_scroller(void)
{
    if(scroller == 5)
    {
        scroller = 0;
    }
    else
    {
       scroller = scroller + 1; 
    }
    return;
}

void display_scroll(void)
{
    while(BusyXLCD());
    SetDDRamAddr(0x00); // line 1
    putrsXLCD("                ");
    SetDDRamAddr(0x40); // line 2
    putrsXLCD("                ");
    SetDDRamAddr(0x10); // line 3
    putrsXLCD("                ");

    while(BusyXLCD());

        SetDDRamAddr(0x00); // line 1
        itoa(HR[scroller],value);
        putsXLCD(value);
        putrsXLCD(" BMP");
        
        SetDDRamAddr(0x40); // line 2
        itoa(HR[scroller+1],value);
        putsXLCD(value);
        putrsXLCD(" BMP");
        
        SetDDRamAddr(0x10); // line 3
        itoa(HR[scroller+2],value);
        putsXLCD(value);
        putrsXLCD(" BMP");
        

        
    while(BusyXLCD());
        
        return;
}