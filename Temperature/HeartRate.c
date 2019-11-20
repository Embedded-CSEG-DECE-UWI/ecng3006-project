#include <p18f452.h>
#include "xlcd.h"
#include "delays.h"
#include <timers.h>
#include <stdlib.h>
#include <string.h>

int heartBeatCounter = 0;
char heartRateOutput [3];
int heartRate = 0;
int startHRV = 0;
extern int startTimer;


void low_isr (void);
void heartRateCal();

void heartRateCal(){
    heartRate = (60*heartBeatCounter)/10;
    itoa(heartRate, heartRateOutput);
    
    SetDDRamAddr(0x00);
    putrsXLCD("P_Rate:         ");
    while(BusyXLCD());
    SetDDRamAddr(0x09); 
    putsXLCD(heartRateOutput);
    while(BusyXLCD());
    SetDDRamAddr(0x0C);
    putrsXLCD(" bpm");
    while(BusyXLCD());
    
    if(heartRate > 110){
        speaker(3);
    }
    
    heartRate = 0;
    heartBeatCounter = 0;
    memset(heartRateOutput, 0, sizeof(heartRateOutput));    //Clears char[]
    WriteTimer0(0x676A);   
  
}

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

void TimerStart(){
    if(startTimer == 1){
        WriteTimer0(0xF0BD);
        startTimer = 0;
    }
}





    
    
 
