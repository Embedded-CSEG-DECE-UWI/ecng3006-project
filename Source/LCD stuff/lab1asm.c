/* Lab 1 first file - ID number 816000924 Group F  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"

 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

unsigned int MapIndex = 0;
extern char getMapChar(void);
extern void MapNamee(void);
extern char MapName;
char groupName[7];

int cool;

void DelayFor18TCY(void)
 {
         Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
         Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
         Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
 }
 
void DelayXLCD(void){                  //1000us = 1ms
     Delay1KTCYx(5);
     
 }
 
void DelayPORXLCD(void){
     Delay1KTCYx(15);
 }
 
void init_lcd(void)
{ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     //WriteCmdXLCD(FOUR_BIT & LINES_5X7);
     //while(BusyXLCD());
     //WriteCmdXLCD( BLINK_ON );
     //while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
}

void main (void)
{
    MapNamee();
    
    for (MapIndex = 0; MapIndex <= 6; MapIndex++){
        groupName[MapIndex] = getMapChar();
    } 
    
    init_lcd();
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putsXLCD(groupName);
    while(BusyXLCD());
    while (1)
    {}
}
