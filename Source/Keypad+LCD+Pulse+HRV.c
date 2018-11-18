#include <p18f452.h>
#include <delays.h>
#include <timers.h>
#include <capture.h>
#include <stdlib.h>
#include <stdio.h>
#include "LCD stuff/xlcd.h"

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

#define k0 PORTCbits.RC4
#define k1 PORTCbits.RC5
#define k2 PORTCbits.RC6
#define k3 PORTCbits.RC7 

/*Defining a new data type with two states called boolean with additional key-words*/
typedef int bool;               
#define TRUE 1
#define FALSE 0

bool COUNTING = FALSE;                                //state that defines whether the program is currently counting pulses or not
bool CAPTURING = FALSE;
bool MEASUREMENT_COMPLETE = FALSE;
bool KEY_PRESSED = FALSE;

/*Keypad Variables*/
char option = 0;

/*Heart Rate Variables*/
volatile int int1Events = 0;                           //stores the event/pulse count received by INT1
unsigned int int1TotalPulse = 0;                       //stores the adjusted pulse count that gives the number of pulses in 1 min

/*Heart Rate Variability Variables*/
volatile int timer1_overflow_count = 0;
unsigned int CCP1_value = 0;
float nn = 0;
float nn50 = 0;
float pnn50 = 0;

unsigned int HRV_pulse_count = 0;
float HRV = 0;
unsigned int HRV_integer = 0;

unsigned int new_value = 0;
unsigned int previous_value = 0;
unsigned int interval = 0;
float temp_interval = 0;

/*LCD Variables*/
char lcdVariable[20];
char hrVariable[20];                                   //array that will contain the pulse count to display on the LCD
char hrvVariable[20];

/*Delays for 18 instruction cycles*/
void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
}
 
/*Delays for 5ms*/
void DelayXLCD(void){                                   //1000us = 1ms
    Delay1KTCYx(5);  
 }
 
/*Delays for 15ms*/
void DelayPORXLCD(void){
    Delay1KTCYx(15);
 }
 
/*Initializes LCD screen for use*/
void initLCD(void){
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
     WriteCmdXLCD(DON & BLINK_OFF);
     while(BusyXLCD());
}

/*Function Prototypes*/
void highISR (void);
void lowISR (void);
int checkPressedKey (void);

void configDebugLED (void);
void configTimers (void);
void configCCP (void);
void configInterrupts (void);
void startPulseInterval (void);
void stopPulseInterval (void);
void printPulse (void);

void readCurrentCount (void);
void nn50IntervalMeasurement (void);
void printHRV (void);
void resetVariables (void);
void startTimer1 (void);
void resetTimer1 (void);
void HRVMeasurement(void);


#pragma code HIGH_INTERRUPT_VECTOR = 0x08               //tells the compiler that the high interrupt vector is located at 0x08
void high_interrupt_vector(void){                   
    _asm                                                //allows asm code to be used into a C source file
    goto highISR                                        //goes to interrupt routine
    _endasm                                             //ends asm code insertion
}
#pragma code

#pragma interrupt highISR
void highISR (void){                                    //interrupt service routine for the high priority vector
    INTCONbits.GIE = 0;
    
    /*Routine for Timer0 interrupt on overflow*/
    if(INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IE = 0;
        INTCONbits.TMR0IF = 0;
        
        PORTBbits.RB0 = !PORTBbits.RB0;                 //toggles a debugging LED that indicates when TIMER 0 overflows
        
        COUNTING = FALSE;
        MEASUREMENT_COMPLETE = TRUE;
                    
        int1TotalPulse = (int1Events*6);                //calculation to obtain number of pulses in 1 min (10s*6)
        int1Events = 0;                                 //resets the pulse count
        HRVMeasurement();
        
        stopPulseInterval();
        startPulseInterval();                  
        
        INTCONbits.TMR0IE = 1;
    }  
    
    /*Routine for Timer1 interrupt on overflow*/
    if(PIR1bits.TMR1IF == 1){
        PIE1bits.TMR1IE = 0;
        PIR1bits.TMR1IF = 0;
        
        timer1_overflow_count += 1;
        
        PIE1bits.TMR1IE = 1;
    }   
    
    /*Routine for external interrupt on INT1*/
    if(INTCON3bits.INT1IF == 1){
        INTCON3bits.INT1IE = 0;
        INTCON3bits.INT1IF = 0;
        
        PORTBbits.RB3 = !PORTBbits.RB3;                 //toggles a debugging LED that indicates when an external interrupt has occurred
        
        COUNTING = TRUE; 
        int1Events++;                                   //increments the event counter
        
        INTCON3bits.INT1IE = 1;
    }
    
    /*Routine for external interrupt on INT2*/
    if(INTCON3bits.INT2IF == 1){
        INTCON3bits.INT2IE = 0;
        INTCON3bits.INT2IF = 0;
        
        KEY_PRESSED = TRUE;
        
        INTCON3bits.INT2IE = 1;
    }   
        
    /*Routine for CCP1 interrupt*/
    if(PIR1bits.CCP1IF == 1){
        PIE1bits.CCP1IE = 0;
        PIR1bits.CCP1IF = 0;
        
        PORTBbits.RB4 = !PORTBbits.RB4;
        
        CAPTURING = TRUE;
        HRV_pulse_count += 1;
        
        readCurrentCount();
        resetTimer1();
        
        PIE1bits.CCP1IE = 1;
    }
    
    INTCONbits.GIE = 1;
}

#pragma code LOW_INTERRUPT_VECTOR = 0x18               //tells the compiler that the high interrupt vector is located at 0x08
void low_interrupt_vector(void){                   
    _asm                                                //allows asm code to be used into a C source file
    goto lowISR                                        //goes to interrupt routine
    _endasm                                             //ends asm code insertion
}
#pragma code

#pragma interrupt lowISR
void lowISR (void){                                    //interrupt service routine for the high priority vector
    INTCONbits.GIE = 0;
    
    INTCONbits.GIE = 1;
}

void configInterrupts(void){
    RCONbits.IPEN = 1;                                  //allows the priority level interrupts to be used
    INTCONbits.GIE = 1;                                 //enables global interrupt sources
    
    INTCONbits.TMR0IE = 1;                              //enables the TMR0 interrupt source  

    INTCON2bits.INTEDG1 = 0;                            //sets the pin to interrupt on a low to high transition 
    INTCON2bits.TMR0IP = 1;                             //sets the TIMER 0 interrupt as priority
    INTCON3bits.INT1IP = 0;
    INTCON3bits.INT1E = 1;                              //enables the INT1 interrupt source

    PIE1bits.TMR1IE = 1;                                //enables the Timer 1 interrupt
    PIE1bits.CCP1IE = 1;                                //enables the capture interrupt
    
    IPR1bits.TMR1IP = 1;                                //sets TIMER 1 interrupt as the priority 
    
    INTCON2bits.INTEDG2 = 1;                            //sets the pin to interrupt on a low to high transition 
    
    INTCON3bits.INT2IP = 1;
    INTCON3bits.INT2IE = 1;                              //enables the INT1 interrupt source
}

void configDebugLED (void){
    //This LED determines whether TIMER0 is interrupting every 15s
    TRISBbits.RB0 = 0; 
    PORTBbits.RB0 = 0;
    //This LED determines whether the external interrupt is being serviced
    TRISBbits.RB3 = 0; 
    PORTBbits.RB3 = 0;
    //This LED determines whether the CCP1 interrupt is being serviced
    TRISBbits.RB4 = 0; 
    PORTBbits.RB4 = 0;
}

void configTimers (void){
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
    T0CONbits.TMR0ON = 0;
    OpenTimer1(TIMER_INT_ON & T1_16BIT_RW & T1_SOURCE_INT & T1_PS_1_1 & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF & T1_SOURCE_CCP);
    T1CONbits.TMR1ON = 0; 
}

void configCCP (void){
    TRISCbits.RC2 = 1;                                  //configures RC2 (pin 17) as an input for use in capture mode   
    OpenCapture1(CAPTURE_INT_ON & C1_EVERY_RISE_EDGE);
}

void startPulseInterval (void){
    WriteTimer0(0x6769);                                  //0x6769 is the value obtained that is need to be written to TIMER 0 with a ps of 256 to obtain a 10s interval
    T0CONbits.TMR0ON = 1;
}

void stopPulseInterval (void){
    T0CONbits.TMR0ON = 0;
}

void startTimer1 (void){
    T1CONbits.TMR1ON = 1;
}

void resetTimer1 (void){
    T1CONbits.TMR1ON = 0;
    WriteTimer1(0x00);
    T1CONbits.TMR1ON = 1;
}

void readCurrentCount (void){    
    nn+=1;
    
    if(HRV_pulse_count == 1){
        CCP1_value = ReadCapture1();
        previous_value = (65535*timer1_overflow_count) + CCP1_value;
    }
    if(HRV_pulse_count == 2){
        CCP1_value = ReadCapture1();
        new_value = (65535*timer1_overflow_count) + CCP1_value;
    }
    if(HRV_pulse_count > 2){
        CCP1_value = ReadCapture1();
        previous_value = new_value;
        new_value = (65535*timer1_overflow_count) + CCP1_value;
    } 
    if(HRV_pulse_count >= 2){
        nn50IntervalMeasurement();
    }
}

void nn50IntervalMeasurement (void){
    interval = new_value - previous_value;
    temp_interval = interval/1000;
    
    if( temp_interval > 50){
        nn50+=1;
    }
}

void HRVMeasurement (void){
    CAPTURING = FALSE;  
    
    if(nn == 0){
        HRV_integer = 0;
    }  
    
    else{
      pnn50 = (nn50/nn);
      HRV = pnn50*100;
      HRV_integer = HRV;
    }  
    
    resetVariables();
}

void resetVariables (void){
    HRV_pulse_count = 0;
    nn = 0;
    nn50 = 0;   
    
    timer1_overflow_count = 0;
}

void printPulse (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    sprintf(hrVariable, "Heartbeat:%d", int1TotalPulse);
    putsXLCD(hrVariable);
    while(BusyXLCD());
}

void printHRV (void){
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    sprintf(hrvVariable, "HRV:%d%", HRV_integer);
    putsXLCD(hrvVariable);
    while(BusyXLCD());
}

int checkPressedKey(){
    if(k3==0 && k2==0 && k1==0 && k0==0){
        option = '1';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==0 && k0==0){
        option = '2';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==0 && k0==0){
        option = '3';
        return option;
    }
    
    if(k3==0 && k2==0 && k1==0 && k0==1){
        option = '4';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==0 && k0==1){
        option = '5';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==0 && k0==1){
        option = '6';
        return option;
    }
    
    if(k3==0 && k2==0 && k1==1 && k0==0){
        option = '7';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==1 && k0==0){
        option = '8';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==1 && k0==0){
        option = '9';
        return option;
    }
    
    if(k3==0 && k2==0 && k1==1 && k0==1){
        option = '0';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==0 && k0==0){
        option = 'A';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==0 && k0==1){
        option = 'B';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==1 && k0==0){
        option = 'C';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==1 && k0==1){
        option = 'D';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==1 && k0==1){
        option = 'E';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==1 && k0==1){
        option = 'F';
        return option;
    }
}

void homeScreen (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("Please choose: ");
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("1.Measurement");
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    putrsXLCD("2.Storage");
    while(BusyXLCD());
}

void menu (char key){        
    switch(key){
        case '1':
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            putrsXLCD("Measuring...");
            while(BusyXLCD());
            int1Events = 0;
            resetVariables();
            startTimer1();
            startPulseInterval();
            
            break;
        
        case '2':
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            putrsXLCD("Storing...");
            stopPulseInterval();
            while(BusyXLCD());
            break;  
        
        case '0':
            homeScreen();
            stopPulseInterval();
        break;
        
        default:
            break;                
    }
}

void main (void){
    initLCD();
    configDebugLED();
    configInterrupts();
    configCCP();
    configTimers();    

    /*This is for the Keypad data lines*/
    TRISC = 0xFF;
    
    homeScreen();
    
    while(1){    
        if (KEY_PRESSED == TRUE){
            checkPressedKey();
            menu(option);
            KEY_PRESSED = FALSE;
        }
        
        if(MEASUREMENT_COMPLETE == TRUE && COUNTING == FALSE){
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            printPulse();                               //prints the result as long as the program is not currently counting
            printHRV();
            MEASUREMENT_COMPLETE = FALSE;
        }
    }
    
    Sleep();
}
