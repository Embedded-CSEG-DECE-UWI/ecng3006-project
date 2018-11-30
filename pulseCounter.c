#include <timers.h>
#include <stdio.h>
#include <p18f452.h>
#include <portb.h>
#include <delays.h>
#include <capture.h>
#include "GblVar.h"



//Must configure GIE and PEIE bits outside of this function
//Function configures External Interrupt 2, Timer 1 and CCP2(capture)
//All interrupts must be added, included below
void pulseCounter_cfg(void){
//    INTCONbits.GIEL = 1;
    
    TRISBbits.RB4 = 0;              //pin to control IR led
    PORTBbits.RB4 = 1;              //IR led on    
    TRISCbits.RC1 = 1;              //set RC1 as input for CCP2
    
//    IPR1bits.TMR1IP = 0;            //set timer1 interrupt low priority
//    IPR2bits.CCP2IP = 0;            //set ccp capture interrupt to low priority
//    INTCON3bits.INT2IP = 0;         //set ext int 2 interrupt to low priority
    
    pulseTimerCounter = 0;          //clear variable for timer1 count
    pulseCount = 0;                 //clear pulse count 
    pnnCount = 0;                   //clear pNN count
    time1 = 0;                      //time1 for capture
    time2 = 0;                      //time2 for capture
    time3 = 0;                      //time3 for capture
    interval1 = 0;                  //interval1 for pNN
    interval2 = 0;                  //interval2 for pNN    
    
    OpenTimer1( TIMER_INT_ON    &       //timer1 int on
                T1_16BIT_RW     &       //16 bit operation
                T1_SOURCE_INT   &       //internal clock source
                T1_PS_1_8       &       //1:8 prescaler
                T1_OSC1EN_OFF   &       //timer1 oscillator off
                T1_SOURCE_CCP   );      //timer1 as ccp source
    
    WriteTimer1(3030);                  //set timer1 for 0.5second overflow
    
    OpenCapture2(   CAPTURE_INT_ON  &   //CCP2 capture, interrupt on
                C2_EVERY_RISE_EDGE  );  //capture on rising edge
    
    OpenRB2INT( PORTB_CHANGE_INT_ON &   //external interrupt 2 on
                RISING_EDGE_INT     &   //interrupt on rising edge
                PORTB_PULLUPS_OFF   );  //PORTB pullups off
    
    return;
}

//Function to be included in ISR for External interrupt 2
//Must check for and clear interrupt flags outside of function 
void pulseCounter_ext2Int(void){ 
    pulseCount++;
    return;
}

//Function to be included in ISR for timer 1 
//Must check for and clear interrupt flags outside of function 
void pulseCounter_tmrInt (void){
            
        PIR1bits.TMR1IF = 0;            //clear timer1 flag
        WriteTimer1(3030);              //restart timer1
        
        pulseTimerCounter++;            //increment counter
        if(pulseTimerCounter == 20){    //turn off timer after 10seconds
            CloseTimer1();
            CloseRB2INT();
            CloseCapture2();
            sprintf(bpm, "Pulse: %dbpm", pulseCount*6);
            while( BusyXLCD() );
            SetDDRamAddr( LCD_line_0 );
            while( BusyXLCD() );    // Check if LCD is busy
            putsXLCD( bpm );
            
            sprintf(pNN, "pNN50: %d%", (pnnCount*100)/pulseCount);
            while( BusyXLCD() );
            SetDDRamAddr( LCD_line_1 );
            while( BusyXLCD() );    // Check if LCD is busy
            putsXLCD( pNN );
            PORTBbits.RB4 = 0;
            PORTAbits.RA5 = 0; 
        }
    return;
}
/*
            
 */

//Function to be included in ISR for CCP2 interrupt
//Must check and clear flags outside of function
void pulseCounter_ccpInt (void){
    
        if(time1 == 0 && time2 == 0 && time3 == 0){
            time1 = ReadCapture2();
            time1 = time1 * pulseTimerCounter;
        }
        
        else if(time1 != 0 && time2 == 0 && time3 == 0){
            time2 = ReadCapture2();
            time2 = time2 * pulseTimerCounter;
            interval1 = time2 - time1;
        }
        
        else if(time1 != 0 && time2 != 0 && time3 == 0){
            time3 = ReadCapture2();
            time3 = time3 * pulseTimerCounter;
            interval2 = time3 - time2;
            if(interval2 < interval1 ){
                if(interval1 - interval2 > 50000){ pnnCount++; }
            }
            else if(interval2 > interval1){
                if(interval2 - interval1 > 50000){ pnnCount++; }
                
            }
            
            interval1 = interval2;
            time2 = time3;
            time3 = 0;

        }
}