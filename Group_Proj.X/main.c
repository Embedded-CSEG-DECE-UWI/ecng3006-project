/* 
 * File:   main.c
 * Author: aasif
 *
 * Created on November 12, 2018, 4:33 PM
 */

#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>
#include <portb.h>
#include <delays.h>
#include <string.h>
#include <pwm.h>
#include "mylcd.h"
#include "MyHeader.h"


#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

# define _XTAL_FREQ 4000000

#define LCD_line_0 ((const unsigned char *) 0x00)
#define LCD_line_1 ((const unsigned char *) 0x40)
#define LCD_line_2 ((const unsigned char *) 0x14)
#define LCD_line_3 ((const unsigned char *) 0x54)

//------------------------------------------------------------------------------
/* Function Prototypes */
//------------------------------------------------------------------------------
void high_isr (void);
void low_isr (void);

//------------------------------------------------------------------------------
/* Global variables */
//------------------------------------------------------------------------------
int flash_array[40] = {0};
unsigned int array_addr;
unsigned int temp_addr;

int tsk;
int wait;

char keyval[1];

int pulseTimerCounter;
int pulseCount;
char bpm[20];

char pNN[20];
int pnnCount;

unsigned int interval1;
unsigned int interval2;
unsigned int time1;
unsigned int time2;
unsigned int time3;

float temperature;

int storeInterval;
int measureCount;

int glucose;

int whole = 0;
int decimal = 0;
char array[20];
//------------------------------------------------------------------------------
/* Interrupt Vectors */
//------------------------------------------------------------------------------
#pragma code high_vector=0x08
void high_interrupt (void){
    _asm GOTO high_isr _endasm
}
#pragma code

#pragma code low_vector=0x18
void low_interrupt (void){
    _asm GOTO low_isr _endasm
}
#pragma code

//------------------------------------------------------------------------------
/* High Priority Interrupt Service Routine */
//------------------------------------------------------------------------------
#pragma interrupt high_isr
void high_isr (void){
    //External Interrupt 1 ISR: for keypad presses and state change
    if(INTCON3bits.INT1IF){
        
        INTCON3bits.INT1IF = 0; //clears the external interrupt flag
        
        keypad_read();
        
        if (keyval[0] == 'F'){
            if(tsk == 2){
                CloseTimer1();
                CloseRB2INT();
                CloseCapture2();
            }
            tsk = 1;
            wait = 0;
            
        }
        else if(tsk ==1){
            wait = 0;
            if(keyval[0] == 'A'){
                tsk =2;
            }
            else if(keyval[0] == 'B'){
                tsk = 3;
            }
            else if(keyval[0] == 'C'){
                tsk = 4;
            }
            else{ wait = 1; }
        }
        
        else if(tsk == 2){
            if(keyval[0] == 'A'){ wait = 0; }
            else { wait = 1; }
                        
        }
        
        else if(tsk == 3){
            wait = 0;
            if(keyval[0] == 'A'){ storeInterval = 1; measureCount  = 1; }
            else if(keyval[0] == 'B'){ storeInterval = 5; measureCount = 5; }
            else if(keyval[0] == 'C'){ storeInterval = 10; measureCount = 10; }
            else { wait = 1; }
        }
        
        else if(tsk == 4){
            
            if(keyval[0] == 'A' && temp_addr > 0){wait = 0; temp_addr = temp_addr - 4;}
            if(keyval[0] == 'B' && temp_addr < 40){wait = 0; temp_addr = temp_addr + 4;} 
            else{wait = 1;}
            
        }
        
        
    }    
    
    //Timer 1 ISR
    if(PIR1bits.TMR1IF){                //Check for timer1 flag
        PIR1bits.TMR1IF = 0;            //clear timer1 flag
        WriteTimer1(3030);              //restart timer1
        
        pulseTimerCounter++;            //increment counter
        if(pulseTimerCounter == 20){    //turn off timer after 10seconds
            CloseTimer1();
            CloseRB2INT();
            CloseCapture2();
            //Display HR and HRV
            sprintf(bpm, "Pulse: %dbpm    ", pulseCount*6);
            while( BusyXLCD() );
            SetDDRamAddr( LCD_line_0 );
            while( BusyXLCD() );    // Check if LCD is busy
            putsXLCD( bpm );
            
            sprintf(pNN, "pNN50: %d%    ", (pnnCount*100)/pulseCount);
            while( BusyXLCD() );
            SetDDRamAddr( LCD_line_2 );
            while( BusyXLCD() );    // Check if LCD is busy
            putsXLCD( pNN );
            
            
            
            PORTBbits.RB4 = 0;
            PORTAbits.RA5 = 0;
            
        }
    }
    
    //CCP2 Capture ISR
    if(PIR2bits.CCP2IF == 1){
        PIR2bits.CCP2IF = 0;
                PIR2bits.CCP2IF = 0;
        
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
                if(interval1 - interval2 > 1000){ pnnCount++; }
            }
            else if(interval2 > interval1){
                if(interval2 - interval1 > 1000){ pnnCount++; }
                
            }
            
            time1 = 0;
            time2 = 0;
            time3 = 0;
//        if(time1 == 0 && time2 == 0 && time3 == 0){
//            time1 = ReadCapture2();
//            time1 = time1 * pulseTimerCounter;
//        }
//        
//        else if(time1 != 0 && time2 == 0 && time3 == 0){
//            time2 = ReadCapture2();
//            time2 = time2 * pulseTimerCounter;
//            interval1 = time2 - time1;
//        }
//        
//        else if(time1 != 0 && time2 != 0 && time3 == 0){
//            time3 = ReadCapture2();
//            time3 = time3 * pulseTimerCounter;
//            interval2 = time3 - time2;
//            if(interval2 < interval1 ){
//                if(interval1 - interval2 > 50000){ pnnCount++; }
//            }
//            else if(interval2 > interval1){
//                if(interval2 - interval1 > 50000){ pnnCount++; }
//                
//            }
//            
//            interval1 = interval2;
//            time2 = time3;
//            time3 = 0;
//
        }
        
    }
    
    //External Interrupt 2 ISR
    if(INTCON3bits.INT2IF){
        INTCON3bits.INT2IF = 0;
        pulseCount++;
    }
}

//------------------------------------------------------------------------------
/* Low Priority Interrupt Service Routine */
//------------------------------------------------------------------------------
#pragma interruptlow low_isr
void low_isr (void){

    return;
}

//------------------------------------------------------------------------------
/* Main function */
//------------------------------------------------------------------------------

void main(void) {
    
    TRISAbits.RA5 = 0;
    PORTAbits.RA5 = 0;
    
    
    RCONbits.IPEN = 0;          // Enable Interrupt Priority 
    INTCONbits.PEIE = 1;        //Enable Peripheral Interrupt Enable bit
	INTCONbits.GIEH = 1;        //Enable all high priority interrupts/ global interrupt bit    
    
    array_addr = 0;
    temp_addr = 0;
    
    keypad_cfg();
    
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );    // Check if LCD is busy
    WriteCmdXLCD( BLINK_OFF );
    while( BusyXLCD() );    // Check if LCD is busy
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
    //Intro screen
    clrScreen();
    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_0 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "Group D: Daemon" );
    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_1 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "ECNG 3006 Project" );
    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_2 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "Heart Rate Monitor" );
    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_3 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "Press F to continue" );
    
    //initialize state and wait 
    tsk = 0;
    wait = 1;
    
    while(wait);            //wait for keypress
    
    while(1){
        wait = 1;
        switch (tsk)
        {
            case 1 :                    //menu
                PORTAbits.RA5 = 1;
                clrScreen();
                menu();
                
                while(wait);
                PORTAbits.RA5 = 0;
                break;
             
            case 2 :                    //Measurement
                
                
                clrScreen();
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_0 );
                while( BusyXLCD() );    // Check if LCD is busy
                putrsXLCD( "Put finger in sensor" );
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_1 );
                while( BusyXLCD() );    // Check if LCD is busy
                putrsXLCD( "A begins, F cancels" );
                
                
                while(wait);
                clrScreen();
                wait = 1;
                    
                do{    
                    pulseCounter_cfg(); //configure and start HR and HRV measurement
                    tempSense_cfg();    //configure temperature measurement
                    tempSense_measure();//measure temperature

                        //Display Temperature
                    whole = temperature;                            //whole part
                    decimal =(temperature*100 - whole*100);             //decimal part
                    sprintf(array, "Temp: %2d.%02dC  ", whole, decimal);     //Convert to string
                    while( BusyXLCD() );
                    SetDDRamAddr( LCD_line_1 );
                    while( BusyXLCD() );    // Check if LCD is busy
                    putsXLCD( array );
                    
                    glucose_measure();
                    sprintf(array, "Glucose: %dmg/dl  ", glucose);     //Convert to string
                    while( BusyXLCD() );
                    SetDDRamAddr( LCD_line_3 );
                    while( BusyXLCD() );    // Check if LCD is busy
                    putsXLCD( array );
                    
                    
                    
                    while(PIE1bits.TMR1IE == 1);
                                                          
                    if(pulseCount*6 < 40 || pulseCount*6 > 160){speaker_on();}
                    
                    measureCount--;
                    if(measureCount == 0){ 
                        measureCount = storeInterval;
                        flash_array[array_addr] = pulseCount;
                        array_addr++;
                        flash_array[array_addr] = pnnCount;
                        array_addr++;
                        flash_array[array_addr] = temperature;
                        array_addr++;
                        flash_array[array_addr] = glucose;
                        array_addr++;
                        
                        if(array_addr == 39){
                            array_addr = 0;
                        }
                    }//code for flash ram storage
                }while(wait);
                break;
                
            case 3 :                    //Set storage interval to flash ram
                //wait = 1;
                clrScreen();
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_0 );
                while( BusyXLCD() );    // Check if LCD is busy
                putrsXLCD( "Storage interval:" );

                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_1 );
                while( BusyXLCD() );    // Check if LCD is busy
                putrsXLCD( "A: 1 measurement" );

                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_2 );
                while( BusyXLCD() );    // Check if LCD is busy
                putrsXLCD( "B: 5 measurements" );

                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_3 );
                while( BusyXLCD() );    // Check if LCD is busy
                putrsXLCD( "C: 10 measurements" );
                
                while(wait){}
                
                break;
                
            case 4 :                        //View data stored on flash ram
                
                
                clrScreen();
                
                pulseCount = flash_array[temp_addr];
                sprintf(bpm, "Pulse: %dbpm    %d", pulseCount*6, temp_addr);
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_0 );
                while( BusyXLCD() );    // Check if LCD is busy
                putsXLCD( bpm );
                temp_addr++;
                
                pnnCount = flash_array[temp_addr];
                sprintf(pNN, "pNN50: %d%    ", (pnnCount*100)/pulseCount);
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_2 );
                while( BusyXLCD() );    // Check if LCD is busy
                putsXLCD( pNN );
                temp_addr++;
                
                temperature = flash_array[temp_addr];
                whole = temperature;                            //whole part
                decimal =(temperature*100 - whole*100);             //decimal part
                sprintf(array, "Temp: %2d.%02dC  ", whole, decimal);     //Convert to string
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_1 );
                while( BusyXLCD() );    // Check if LCD is busy
                putsXLCD( array );
                temp_addr++;
                
                glucose = flash_array[temp_addr];
                sprintf(array, "Glucose: %d    ", glucose);     //Convert to string
                while( BusyXLCD() );
                SetDDRamAddr( LCD_line_3 );
                while( BusyXLCD() );    // Check if LCD is busy
                putsXLCD( array );
                temp_addr++;
                    
                while(wait);
                break;
                
            default: 
                tsk = 1;
                break;
        }
    }
    
    while(1);
    return;
}

void menu(void){
    
    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_0 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "Select option:" );

    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_1 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "A: Measure" );

    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_2 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "B: Storage interval" );

    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_3 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "C: View" );

    return;
}

void clrScreen (void){
    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_0 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "                    " );

    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_1 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "                    " );

    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_2 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "                    " );

    while( BusyXLCD() );
    SetDDRamAddr( LCD_line_3 );
    while( BusyXLCD() );    // Check if LCD is busy
    putrsXLCD( "                    " );
    
    return;
}
