// THIS CODE WAS ADAPTED FROM MYRON MAHARAJ 
// THE CODE WAS ALTERED TO SUIT THE NEEDS OF OUR PROJECT

//---------------------------------------------------------------------------------------------------------------------------------------
//                              HEADER FILES
//---------------------------------------------------------------------------------------------------------------------------------------

#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <timers.h>
#include <delays.h>
#include <string.h>
#include "xlcd.h"


//---------------------------------------------------------------------------------------------------------------------------------------
//                              CONFIGURATIONS
//---------------------------------------------------------------------------------------------------------------------------------------

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define DATA_AVAILABLE  1
#define NO_NEW_DATA 0

void high_isr(void);           // Interrupt declaration
int read = 0;
int Key_Pressed;

//----------------------------------------------------------------------------------------------------------------------------------------
//                              HIGH INTERRUPT VECTOR CODE
//----------------------------------------------------------------------------------------------------------------------------------------

#pragma code high_vector=0x08
void interrupt_at_high_vector(void){
_asm GOTO high_isr _endasm
} 
#pragma code

#pragma interrupt high_isr
void high_isr (void){
    int Timer0_temp= 0;                    //Creating temporary variables to hold values for global variables
    int HRP_Temp = 0;
    int HRV_Temp = 0;
    int Time_Temp = 0;
    int i=0;                               //Variable to hold place in array

    
    Timer0_temp = Assign_Timer0_GV();
    if(INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;          //Reseting timer0 flag
        WriteTimer0(61630);
        if(Timer0_temp == 0){           //Checking if 15 seconds have passed (i.e 1s has passed 15 times)
            HRP_Temp = Assign_HRP_GV();
            Set_BPM(HRP_Temp*6);    // 15s * 4 = 60 seconds (i.e 1 minuite)
            Turn_Off_HRM();
            Set_BPM_Check();
        }
        else{
            INTCONbits.TMR0IF = 0;
            Dec_Timer0_GV();           //Decrementing 15s counter when 1 sec has passed
            WriteTimer0(61630);
          
        }
    }
    
    if(INTCONbits.INT0F == 1){
        //HRM Code
        INTCONbits.INT0F = 0;
        Inc_HRP_GV();
        
        //Heart Rate Variability Code
        
        HRV_Temp = Assign_HRV_GV();
        if(HRV_Temp > 0 ){
            i = 11 - HRV_Temp;                                            // variable for place in array
            Time_Temp = ReadTimer0() - 61630 + (14 - Timer0_temp )*(3906);
            Set_pulse_time(i , Time_Temp);                                                                      
        }
        Dec_HRV_GV();
    }
    
    if(INTCON3bits.INT1F==1)              //RB0 changed states.
    {
        read=DATA_AVAILABLE;
        
        INTCON3bits.INT1F=0;
    }
    
    

}

//---------------------------------------------------------------------------------------------------------------------------------------
//                            MAIN
//---------------------------------------------------------------------------------------------------------------------------------------
void main(){
    
    int i;
    int Temp_HRV;
    int Temp_BPM_Check;
    int Temp_BPM;
    char BPM_String[3];
    char HRV_String[3];
       

// LCD Display when the system is turned on
    //Write to first line on LCD 
    Start_Screen();
    
    
    while(1){
     
         if(read==1)
         {
             keypress();
             read=NO_NEW_DATA;
         }
     
        Temp_BPM_Check = Assign_BPM_Check();
        if (Temp_BPM_Check == 1){
            Init_BPM_Check();
            Temp_BPM = Assign_BPM();
            Temp_HRV = HRV_Calc();
            itoa(Temp_BPM , BPM_String);
            itoa(Temp_HRV , HRV_String);
            Config_LCD();
            //Insert Code to print to LCD here.
            SetDDRamAddr( 0x00 );
    
             //Writing to LCD
            while( BusyXLCD() );
            putrsXLCD( "Heart Rate=" );
            while( BusyXLCD() );
            putsXLCD(BPM_String);
            while( BusyXLCD() );
            putrsXLCD("bpm");        
            
            while( BusyXLCD() );
            SetDDRamAddr( 0x040 );
            putrsXLCD( "HRV= " );
            while( BusyXLCD() );
            putsXLCD(HRV_String);
            while( BusyXLCD() );
            putrsXLCD("%");  
            
            Temperature();

            Temp_BPM_Check = 0;
            
            while( BusyXLCD() );
            SetDDRamAddr( 0x50 );
 
     
            //Writing to LCD
            while( BusyXLCD() );
            putrsXLCD( "Glucose =0mg/dL" );   
            
            if(Temp_BPM > 140 || Temp_BPM < 40 || Temp_HRV == 0){
                for(i=0; i<3; i++){
                Init_Speaker();
                Delay10KTCYx(300);
                Speaker_Off();
                Delay10KTCYx(100);
                }
            }

        
        
    }
}
}

//---------------------------------------------------------------------------------------------------------------------------------------
//                                  END
