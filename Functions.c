#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <timers.h>
#include <delays.h>
#include <string.h>
#include "xlcd.h"

//--------------------------------------------------------------------------------------------------------------------------------------
//                                  GLOBAL VARIABLES
//--------------------------------------------------------------------------------------------------------------------------------------

unsigned static int Timer0_GV;
unsigned static int HRP_GV;
unsigned static int BPM_GV;
static int BPM_Check_GV;
static int HRV_GV;
unsigned static int pulse_time[11];

//Timer0 Functions--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Init_Timer0_GV(){
    Timer0_GV = 9; 
}

void Dec_Timer0_GV(){
    Timer0_GV--;
}

int Assign_Timer0_GV(){
    return Timer0_GV;
}

//Heart Rate Pulse Functions--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Init_HRP_GV(){
    HRP_GV = 0;
}

void Inc_HRP_GV(){
    HRP_GV++;
    
}
int Init_BPM(){
    BPM_GV = 999;
}
int Assign_HRP_GV(){
    return HRP_GV;
}

//BPM Functions---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Set_BPM(int value){
    BPM_GV = value;
    
}

int Assign_BPM(){
    return BPM_GV;
}

void Init_BPM_Check(){
    BPM_Check_GV = 0;
}

void Set_BPM_Check(){
    BPM_Check_GV = 1;
}

int Assign_BPM_Check(){  
    return BPM_Check_GV; 
}

//HRV functions--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Init_HRV_GV(){
    HRV_GV = 11;
}

void Dec_HRV_GV(){
    HRV_GV--;
}

int Assign_HRV_GV(){    
    return HRV_GV;
}

void pulse_time_Init(){
    int i;
    for(i = 0; i< 10; i++){
        pulse_time[i]=0;
    }
}

void Set_pulse_time(int i, int time){
    pulse_time[i]= time;
}

int Assign_pulse_time(int i){ 
    return pulse_time[i];
}

// HRM (Heart Rate Monitor) Initialisation code----------------------------------------------------------------------------

int HRM_Init(){
    Init_BPM();                
    Init_BPM_Check();  
    Init_HRP_GV();
    RCONbits.IPEN = 1;          //Allows for both high and low priority interrupts to occur
    
    // 1) Initial interrupts for RB0
    INTCONbits.INT0E = 1;       //Turn on interrupt
    INTCON2bits.RBIP = 1;       // High priority
    INTCON2bits.INTEDG0 = 0;    //Interrupts on falling edge
    
    
    // 2) Set timer0 to interrupt approximately every 1 second
    INTCONbits.T0IE = 1;        
    INTCON2bits.T0IP = 1;       
    T0CONbits.PSA = 0;           
    T0CONbits.T0CS = 0;
    T0CONbits.T08BIT = 0;       
    T0CONbits.T0PS0 = 1;       
    T0CONbits.T0PS1 = 1;        
    T0CONbits.T0PS2 = 1;        
    WriteTimer0(61630);          
    Init_Timer0_GV();           
    
    // 3) Enable global interrupt
    INTCONbits.GIEL = 1;
    INTCONbits.GIEH = 1;        
    T0CONbits.TMR0ON = 1;      
    return 1;
}


int Turn_Off_HRM(){
    INTCONbits.INT0E = 0;       //Disables interrupts on INT0
    INTCONbits.T0IE = 0;        //Disables timer0 interrupts
    T0CONbits.TMR0ON = 1;       //Turns off timer0
    return 1;
} 

// Heart Rate Variability Initialisation -------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


int HRV_Init(){
    pulse_time_Init();
    Init_HRV_GV();
    return 1;        
}

int HRV_Calc(){
    int i = 0;
    int NN50_count = 0;
    int R_R_time_diff = 0;
    int pNN50 = 0;
    for(i; i<9 ; i++){ 
        R_R_time_diff =( Assign_pulse_time(i+2) - Assign_pulse_time(i+1)) - (Assign_pulse_time(i+1) - Assign_pulse_time(i));
        if((R_R_time_diff > 195) || ((R_R_time_diff < -195))){
            NN50_count++;
        }
       
    }
    pNN50 = NN50_count*10; 
    if (pNN50 < 50)
    {
        pNN50 = pNN50 + 40;
    }
    return pNN50;
}

//-------------------------------------------------------------------------------------------------------------------
void System_Init(void) 
{
     // This function is used to start the process of calculating  
    HRM_Init();
    HRV_Init();
    
}

void Start_Screen(void)
{
    // This function creates the menu 
    Config_LCD();       // Clear LCD
    
    while( BusyXLCD() );
    SetDDRamAddr( 0x00 );         
   
    while( BusyXLCD() );
    putrsXLCD( "PLACE FINGER" );
    
    //Write to second line on LCD 
    while( BusyXLCD() );
    SetDDRamAddr( 0x40 );
    
    while( BusyXLCD() );
    putrsXLCD( "BETWEEN SENSOR" );
    
    //Write to fourth line on LCD 
    while( BusyXLCD() );
    SetDDRamAddr( 0x50 );
    
    while( BusyXLCD() );
    putrsXLCD( "Press 1" );
    
    start_up();
}