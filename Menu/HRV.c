#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>
#include <string.h>
#include <capture.h>
#include "xlcd.h"

int timer1Period = 0;
long double HRVvar1 = 0;
long double HRVvar2 = 0;
long double HRVvar3 = 0;
long double hrvInterval1 = 0;
long double hrvInterval2 = 0;
long double numNNInterval =0;
long double numNN50 = 0;
long double pNN50 = 0;

char hrv_Output[2];

void timer1Setup(){
    //Timer 1 Setup
    OpenTimer1(TIMER_INT_ON & 
        T1_16BIT_RW & T1_SOURCE_INT &
        T1_PS_1_8 & T1_SOURCE_CCP);
    IPR1bits.TMR1IP = 0;        //Set TMR1 interrupt LOW priority 
    PIE1bits.TMR1IE = 1;        //Enable TMR1 interrupt
    PIR2bits.CCP2IF = 0;        //Set the capture to 0
    IPR2bits.CCP2IP = 1;        //Set capture to high priority
    WriteTimer1(0x0BDC);        //Write TMR1 to start for 0.5s
}

void captureSetup(){
    //Timer 1 Setup for counting time between NN intervals and CCP2
    TRISCbits.CCP2 = 1;         //Set CCP2 as an input
    OpenCapture2(               //Configure to Capture every rising edge
        CAPTURE_INT_ON & 
        C2_EVERY_RISE_EDGE);     
}

void HRVcal()
{
        
        if(HRVvar1 == 0 && HRVvar2 == 0 && HRVvar3 ==0){
            HRVvar1 = ReadCapture2(); 
            HRVvar1 = HRVvar1*timer1Period;
        }
        else if(HRVvar1 != 0 && HRVvar2 == 0 && HRVvar3 == 0){
            HRVvar2 = ReadCapture2();
            HRVvar2 = HRVvar2 *timer1Period;
            if(HRVvar2 < HRVvar1){
                hrvInterval1 = HRVvar1 - HRVvar2;
            }
            if(HRVvar1 < HRVvar2){
                hrvInterval1 = HRVvar2 - HRVvar1; 
            }            
            numNNInterval = numNNInterval + 1.0;           
        }
        else if(HRVvar1 != 0 && HRVvar2 != 0 && HRVvar3 == 0){
            HRVvar3 = ReadCapture2();
            HRVvar3 = HRVvar3*timer1Period;
            if(HRVvar3 < HRVvar2){
                hrvInterval2 = HRVvar2 - HRVvar3;
            }
            if(HRVvar2 < HRVvar3){
                hrvInterval2 = HRVvar3 - HRVvar2; 
            }
            numNNInterval = (long) numNNInterval+ 1.0;            
           if(hrvInterval2 < hrvInterval1 ){
                if(hrvInterval1 - hrvInterval2 > 50000){ numNN50++; }
            }
            else if(hrvInterval2 > hrvInterval1){
                if(hrvInterval2 - hrvInterval1 > 50000){ numNN50++; }
                
            }

            HRVvar3 = 0;
            HRVvar2 = 0;
            HRVvar1 = 0;
            hrvInterval1 = 0;
            hrvInterval2 = 0;
        }                                
    
}           


void HRVprint()
{
        if(timer1Period%19 == 0 && numNN50>0){
            pNN50 = (numNN50/numNNInterval)*100.0;;
            //itoa(pNN50, hrv_Output);       
            //SetDDRamAddr(0x40);
            //while(BusyXLCD());
            //putrsXLCD("HRV:         ");
            //while(BusyXLCD());
            //SetDDRamAddr(0x4B); 
            //putsXLCD(hrv_Output);
            //while(BusyXLCD());
            //SetDDRamAddr(0x4E);
            //putrsXLCD(" %");
            //while(BusyXLCD());
        }
        timer1Period = timer1Period++;
        WriteTimer1(0x0BDC);
}
