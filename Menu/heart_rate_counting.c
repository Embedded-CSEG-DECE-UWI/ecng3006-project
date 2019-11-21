/*This file contains functions that would be used in the Heart Rate Counting and*/
/*Heart Rate Variability*/
#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>
#include <string.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

int heartBeatCounter = 0;
char heartRateOutput [3];
int heartRate = 0;
int startTimer = 0;
int startHRV = 0;

void high_isr (void);
void low_isr (void);
void heartRateCal();

//void DelayFor18TCY (void)
//{
     //Nop();     Nop();      Nop();      Nop();      Nop();      Nop(); 
     //Nop();     Nop();      Nop();      Nop();      Nop();      Nop(); 
    // Nop();     Nop();      Nop();      Nop();
//}

//void DelayXLCD (void)
//{
    //Delay1KTCYx(5);
//}

//void DelayPORXLCD (void)
//{
    //Delay1KTCYx(15);   
//}

void heartRateCal(){
    heartRate = (60*heartBeatCounter)/10;
    itoa(heartRate, heartRateOutput);

    //WriteCmdXLCD(0b00000001);
    //while(BusyXLCD());
    //SetDDRamAddr(0x00);
    //putrsXLCD("P_Rate:");
    //while(BusyXLCD());
    //SetDDRamAddr(0x0A);
    //while(BusyXLCD());
    //putsXLCD(heartRateOutput);
    //while(BusyXLCD());
    //SetDDRamAddr(0x0D);
    //while(BusyXLCD());
    //putrsXLCD("bpm");

    heartRate = 0;
    heartBeatCounter = 0;
    memset(heartRateOutput, 0, sizeof(heartRateOutput));    //Clears char[]
    WriteTimer0(0x676A);     
}

//void lcdSetup (void)
//{ 
    //OpenXLCD(FOUR_BIT & LINES_5X7);
    //while(BusyXLCD());
    //SetDDRamAddr(0x00); 
    //while(BusyXLCD()); 
    //WriteCmdXLCD(BLINK_ON);
    //while(BusyXLCD());
    //WriteCmdXLCD(SHIFT_DISP_LEFT);
    //while(BusyXLCD());
    //putrsXLCD("Press A");
//}

//void keypadSetup(){
    //INTCON3bits.INT1IE = 1;     //enable the INT1 external interrupt 
    //INTCON3bits.INT1IP = 0;     //INT1 External Interrupt Priority bit LOW for Low priority
    //INTCON3bits.INT1IF = 0;     //Clear INT1 flag bit
	//INTCON2bits.INTEDG1= 1;     //set interrupt INT1 on rising edge    
    
    //Input pins for the keypad
    //TRISDbits.RD7 = 1;          //A
    //TRISDbits.RD6 = 1;          //B
    //TRISDbits.RD5 = 1;          //C
    //TRISDbits.RD4 = 1;          //D
//
 
void irPulseSetup(){
    INTCON3bits.INT2IE = 1;     //Enable INT2 interrupt
    INTCON3bits.INT2IF = 0;     //Clear INT2 interrupt flag
    INTCON3bits.INT2IP = 0;     //Set INT2 priority to low
    INTCON2bits.INTEDG2 = 1;    //Set to interrupt on rising edge
    
    TRISBbits.RB2 = 1;          //Configure RB2 as an input for output from IR module
}

void timer0Setup(){
    //Timer 0 Setup 
    OpenTimer0(TIMER_INT_ON &
        T0_16BIT & T0_SOURCE_INT &
        T0_EDGE_RISE & T0_PS_1_256);
    INTCONbits.T0IE = 1;        //Enable TMR0 overflow interrupt bit 
    INTCON2bits.T0IP = 1;       //Set TMR0 Interrupt as high priority
    INTCONbits.T0IF = 0;        //Clearing TMR0 Interrupt Flag
}

void pulseCounting(){
    heartBeatCounter = heartBeatCounter++;
}

/*------------------------HIGH INTERRUPT SERVICE ROUTINE----------------------*/
#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
    _asm GOTO high_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr (void)
{    
    if(INTCONbits.TMR0IF == 1 && startTimer == 1){
        heartRateCal();
        INTCONbits.TMR0IF = 0;
    }
}

/*------------------------LOW INTERRUPT SERVICE ROUTINE-----------------------*/
#pragma code low_vector = 0x18
void interrupt_at_low_vector(void)
{
    _asm GOTO low_isr _endasm
}
#pragma code

#pragma interrupt low_isr
void low_isr (void)
{
    
    if(INTCON3bits.INT2IF){
        pulseCounting();
    }
    //if(INTCON3bits.INT1IF){
        //if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4)
        //{
            //startTimer = 1;
            //timer0Setup();
            //WriteCmdXLCD(0b00000001);
            //WriteTimer0(0xF0BD); 
        //}
        //if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4)
        //{
            //CloseTimer0();          
        //}
    //}
    INTCON3bits.INT2IF = 0;
    //INTCON3bits.INT1IF = 0;
}

void main()
{
    ////SETUP 
    //lcdSetup();
    //keypadSetup();
    irPulseSetup();   
    //INTCONbits.GIEH = 1;        //Global Interrupt Enable bit
    //RCONbits.IPEN = 1;          //Enable Interrupt Priority 
    //INTCONbits.PEIE =1;         //Enable Peripheral Interrupt Enable bit
    while(1);
}
//
