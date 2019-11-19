// Adapted from Amar Pustam 2018
#include <p18f452.h> 
#include "delays.h"
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr(void);
void keypress(void);
int keyvalue;

#pragma code low_vector=0x18 

void interrupt_at_low_vector(void) 
{
    _asm 
    GOTO low_isr 
    _endasm 
} 

#pragma code 

#pragma interruptlow low_isr
void low_isr(void)
{
    WriteCmdXLCD(0b00000001);
    keypress();                                             //Calls the key press function inside the ISR 
    INTCON3bits.INT1IF = 0;                 //clears the external interrupt flag
}


void keypress(void)
{
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
     keyvalue = 1;
     return keyvalue;
     //while(BusyXLCD());
     //SetDDRamAddr(0x00);
     //putrsXLCD("1");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    keyvalue = 2;
    return keyvalue;
    //while(BusyXLCD());
    //SetDDRamAddr(0x00);
    //putrsXLCD("2");
    } 
  if (!PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4)
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("3");
    } 
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4)
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("4");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("5");
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("6");
    }
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("7");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("8");
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("9");
    }
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("0");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("A");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("B");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("C");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("D");
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("E");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("F");
    }
}
void DelayFor18TCY(void){
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}
void LcdSetup(void)                                             //Setup for the LCD
{ 
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00); 
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
}
void InterruptSetup(void){

    INTCON3bits.INT1IE = 1;                 //enable the INT1 external interrupt 
    INTCON3bits.INT1IF = 0;                 //clear external interrupt INT1 flag
    INTCON2bits.INTEDG1= 1;                //set interrupt INT1 on rising edge
    RCONbits.IPEN = 1;                              // Enable Interrupt Priority 
    INTCONbits.PEIE =1;                         //Enable Peripheral Interrupt Enable bit
    INTCONbits.GIEH = 1;                        //Enable all high priority interrupts/ global interrupt bit
    INTCON3bits.INT1IP = 0;                 //Set INT1 Priority bit to high priority
}

void KeypadSetup(void)                          //Setup for keypad
{
    TRISCbits.RC7 = 1; //A                      //Defining ports for each input
    TRISCbits.RC6 = 1; //B
    TRISCbits.RC5 = 1; //C
    TRISCbits.RC4 = 1; //D
}
void main(void){
    InterruptSetup();
    KeypadSetup();
    LcdSetup();
    while(BusyXLCD());
    putrsXLCD("Integration test3");
    while(BusyXLCD());
    while(1);
}