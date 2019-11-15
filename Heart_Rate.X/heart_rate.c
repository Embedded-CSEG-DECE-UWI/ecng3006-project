#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

int heartBeatCounter = 0;
char heartRateOutput [3];
int heartRate = 0;

void high_isr (void);
void low_isr (void);

#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
    _asm GOTO high_isr _endasm
}
#pragma code

#pragma code low_vector = 0x18
void interrupt_at_low_vector(void)
{
    _asm GOTO low_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr (void)
{
    INTCONbits.GIE = 0;
    INTCONbits.TMR0IF = 0;
    
    heartRate = (60*heartBeatCounter)/10;
    itoa(heartRate, heartRateOutput);
    
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putsXLCD(heartRateOutput);
    
    WriteTimer0(0x676A);
    
    heartRate = 0;
    heartBeatCounter = 0;
    INTCONbits.GIE = 1;
}

#pragma interrupt low_isr
void low_isr (void)
{
    INTCONbits.GIEL = 0;
    INTCON3bits.INT2IF = 0;
    INTCON3bits.INT2IE = 0;
    heartBeatCounter = heartBeatCounter++;    

    INTCONbits.GIEL = 1;
    INTCON3bits.INT2IE = 1;
    
}

void DelayFor18TCY (void)
{
     Nop();     Nop();      Nop();      Nop();      Nop();      Nop(); 
     Nop();     Nop();      Nop();      Nop();      Nop();      Nop(); 
     Nop();     Nop();      Nop();      Nop();
}

void DelayXLCD (void)
{
    Delay1KTCYx(5);
}

void DelayPORXLCD (void)
{
    Delay1KTCYx(15);   
}

void lcdSetup (void)
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

void main()
{
    TRISBbits.RB2 = 1;
    
    lcdSetup();
    INTCONbits.GIE = 1;         //Global Interrupt Enable bit
    RCONbits.IPEN = 1;          //Interrupt Priority Enable bit
    INTCONbits.PEIE =1;         //Enable all low priority interrupts
    INTCON3bits.INT1IE = 1;     //Enable INT1 interrupt
    INTCON2bits.INTEDG1 = 1;    //External Interrupt 1 Edge Select bit
    INTCON3bits.INT1IP = 0;     //INT1 External Interrupt Priority bit LOW for Low priority
    INTCON3bits.INT1IF = 0;     //Clear INT1 flag bit
        
    //Input from IR Sensing circuit
    INTCON3bits.INT2IE = 1;     //Enable INT2 interrupt
    INTCON3bits.INT2IF = 0;     //Clear INT2 interrupt flag
    INTCON3bits.INT2IP = 0;     //Set INT2 priority to low
    INTCON2bits.INTEDG2 = 1;    //Set to interrupt on rising edge
    
    //Timer 0 Setup 
    INTCONbits.T0IE = 1;        //Enable TMR0 overflow interrupt bit 
    INTCONbits.T0IF = 0;        //Clearing TMR0 Interrupt Flag
    INTCON2bits.T0IP = 1;       //Set TMR0 Interrupt as high priority
    OpenTimer0(TIMER_INT_ON &
            T0_16BIT & T0_SOURCE_INT &
            T0_EDGE_RISE & T0_PS_1_256);
    
    if(PORTBbits.RB2){
        WriteTimer0(0x676A);  
    }
    
    
    
    while(1);
}