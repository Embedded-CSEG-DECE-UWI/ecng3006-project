#include <p18f452.h>
#include <delays.h>
#include <timers.h>
#include <capture.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwm.h>
#include <adc.h> 
#include "ow.h"
#include "xlcd.h"

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system should allow a user to start storing a pre-de?ned set of measurements to external ?ash RAM, and to interrupt the ongoing storage of a set of measurements.

#define DATA_595 PORTBbits.RB3 
#define CLK_595 PORTAbits.RA1
#define LED     PORTBbits.RB4
#define OE      PORTCbits.RC3
#define WE      PORTDbits.RD3
#define D0      PORTAbits.RA2
#define D1      PORTAbits.RA3
#define D2      PORTAbits.RA4
#define D3      PORTAbits.RA5
#define D4      PORTEbits.RE0
#define D5      PORTEbits.RE1
#define D6      PORTEbits.RE2
#define D7      PORTCbits.RC0
#define k0      PORTCbits.RC4
#define k1      PORTCbits.RC5
#define k2      PORTCbits.RC6
#define k3      PORTCbits.RC7 
#define OEtris  TRISCbits.RC3
#define WEtris  TRISDbits.RD3
#define D0tris  TRISAbits.RA2
#define D1tris  TRISAbits.RA3
#define D2tris  TRISAbits.RA4
#define D3tris  TRISAbits.RA5
#define D4tris  TRISEbits.RE0
#define D5tris  TRISEbits.RE1
#define D6tris  TRISEbits.RE2
#define D7tris  TRISCbits.RC0
#define ROW1    0x00
#define ROW2    0x40
#define ROW3    0x10
#define ROW4    0x50

/*Defining a new data type with two states called boolean with additional key-words*/
typedef int bool;               
#define TRUE 1
#define FALSE 0

bool COUNTING = FALSE;                                //state that defines whether the program is currently counting pulses or not
bool CAPTURING = FALSE;
bool MEASUREMENT_COMPLETE = FALSE;
bool KEY_PRESSED = FALSE;
bool BROWN_OUT = FALSE;
bool ALARM = FALSE;

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

/*Temperature Variables*/
unsigned char temp_read_LSB;// = 10;
unsigned char temp_read_MSB;// = 65000;
unsigned char temp_degree = 0xDF;

unsigned int temp_LSB = 0;
unsigned int temp_MSB = 0;
unsigned int temp_integer = 0;
unsigned int temp_fraction = 0;
unsigned int temp_sign = 0;

unsigned int temp_hundreds = 0;
unsigned int temp_tens = 0;
unsigned int temp_ones = 0;

int counter = 0;

float temp_float = 0.0;

int average_integer = 0;
int average_fraction = 0;
int sum_integer = 0;
int sum_fraction = 0;
int running_average_integer = 0;
int running_average_fraction = 0;

int temp_sum_fraction = 0;
float decimal_division_initial_value = 0.0;
float integer_division_initial_value = 0.0;

float decimal_division_final_value = 0.0;
int decimal_division_final_value_integer = 0;

int integer_variable_extraction = 0;
float integer_division_value_to_add = 0.0;

float average_fraction_float = 0;

int counter2 = 5;
int test = 0;
int approx_value = 0;

int glucoseMeasurement = 0;


/*FLASHRAM*/
short long sramCurrPtr = 0; //Variable to manage the address of SRAM
short long sramSecPtr = 0; //Ptr to sector addresses
int press = 0;
int sramStorageInterval = 0;
int sramMeasurementCount = 0;
short long sramStorageIntCount = 0; //To help keep track of storage intervals for the sram
int sramStorageIntCount2 = 0; //To help keep track of the storage interval;
short long sramNumOfStorage = 0; //Helps keep track user defined number of measurements to be taken.


/*LCD Variables*/
char lcdVariable[20];
char hrVariable[20];                                   //array that will contain the pulse count to display on the LCD
char hrvVariable[20];
char tempVariable[20];
char glucoseVariable[20];

int brownOutSave = 0;

/*Glucose*/
int result = 0;
int conversionV = 0;
int conversionG = 0;

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
     WriteCmdXLCD(FOUR_BIT & LINES_5X7);
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
void printGlucose (void);
void resetVariables (void);
void startTimer1 (void);
void resetTimer1 (void);
void HRVMeasurement(void);

void configTemp (void);
void readTemp (void);
void obtainInteger (void);
void obtainFraction (void);
int approximation (int);
void obtainSign (void); 
void resetTempConversion (void);
void runningAverage (void);
void errorCalibration (void);

void configSpeaker (void);
void alarm (void);
void checkRange (void);

void sramSetDataPinTris(short int x);
void displayScrollMeasurement (void);
void setStorageInterval (void);
void setMeasurementNumber (void);
void initSecErase(void);

void configADC (void);

/*Support Circuitry*/
void configSupportCircuity (void){
    TRISBbits.RB0 = 0xFF;
    TRISBbits.RB3 = 0;
    TRISBbits.RB4 = 0x00;
    PORTBbits.RB4 = 0;
}

void checkBrownout (void){
    if(PORTBbits.RB0 == 1){
        BROWN_OUT = TRUE;
    }
    if(PORTBbits.RB0 == 0){
        BROWN_OUT = FALSE;
    }
}

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
        
        COUNTING = FALSE;
        MEASUREMENT_COMPLETE = TRUE;
        ALARM = FALSE;
                    
        int1TotalPulse = (int1Events*6);                //calculation to obtain number of pulses in 1 min (10s*6)
        HRVMeasurement();
        checkRange();
        
        int1Events = 0;                                 //resets the pulse count        
        
        stopPulseInterval();
        startPulseInterval();                  
        
        INTCONbits.TMR0IE = 1;
    }  
    
    /*Routine for Timer1 interrupt on overflow*/
    if(PIR1bits.TMR1IF == 1){
        PIE1bits.TMR1IE = 0;
        PIR1bits.TMR1IF = 0;
        
        timer1_overflow_count += 1;
        
        checkBrownout();
        
        PIE1bits.TMR1IE = 1;
    }   
    
    /*Routine for external interrupt on INT1*/
    if(INTCON3bits.INT1IF == 1){
        INTCON3bits.INT1IE = 0;
        INTCON3bits.INT1IF = 0;
        
        COUNTING = TRUE; 
        int1Events++;                                   //increments the event counter
        
        INTCON3bits.INT1IE = 1;
    }
    
    /*Routine for external interrupt on INT2*/
    if(INTCON3bits.INT2IF == 1){
        INTCON3bits.INT2IE = 0;
        INTCON3bits.INT2IF = 0;
        
        checkPressedKey();
        KEY_PRESSED = TRUE;
        press = 1;
        
        INTCON3bits.INT2IE = 1;
    }   
        
    /*Routine for CCP1 interrupt*/
    if(PIR1bits.CCP1IF == 1){
        PIE1bits.CCP1IE = 0;
        PIR1bits.CCP1IF = 0;
        
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
    INTCON3bits.INT1IP = 1;
    INTCON3bits.INT1E = 1;                              //enables the INT1 interrupt source

    PIE1bits.TMR1IE = 1;                                //enables the Timer 1 interrupt
    PIE1bits.CCP1IE = 1;                                //enables the capture interrupt
    
    IPR1bits.TMR1IP = 1;                                //sets TIMER 1 interrupt as the priority 
    
    INTCON2bits.INTEDG2 = 1;                            //sets the pin to interrupt on a low to high transition 
    
    INTCON3bits.INT2IP = 1;
    INTCON3bits.INT2IE = 1;                              //enables the INT1 interrupt source
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
    sprintf(hrVariable, "Pulse: %dbpm", int1TotalPulse);
    putsXLCD(hrVariable);
    while(BusyXLCD());
}

void printHRV (void){
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    sprintf(hrvVariable, "HRV: %d%", HRV_integer);
    putsXLCD(hrvVariable);
    while(BusyXLCD());
}

void printTemp (void){
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    putsXLCD(tempVariable);
    while(BusyXLCD());
}

void printGlucose (void){
    SetDDRamAddr((0x50));
    while(BusyXLCD());
    sprintf(glucoseVariable, "Glucose: %dmg/dL", glucoseMeasurement);
    putsXLCD(glucoseVariable);
}

void configTemp (void){
    ow_reset();                                             //resets the D1822 thermometer
    
    ow_write_byte(0xCC);                                    //Skip ROM check command
    ow_write_byte(0x4E);
    ow_write_byte(0x00);
    ow_write_byte(0x00);
    ow_write_byte(0x5F);
}

void readTemp (void){
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0x44);                                    //Begin temperature read and conversion
    Delay10KTCYx(40);                                       //The required time needed for the temp conversion process is 750ms. 800ms was implemented to give
                                                            //a sizeable error window
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0xBE);
    temp_read_LSB = ow_read_byte();
    temp_read_MSB = ow_read_byte();   
}

void obtainInteger (void){
    temp_LSB = temp_read_LSB >> 4;
    temp_MSB = temp_read_MSB << 4;
    temp_integer = temp_MSB | temp_LSB;  
}

void obtainFraction (void){
    /*Assortment of checks to determine the fraction*/
    if(temp_read_LSB & 0x01){
        temp_float += 0.0625;
    }
    if(temp_read_LSB & 0x02){
        temp_float += 0.125;
    }
    if(temp_read_LSB & 0x04){
        temp_float += 0.25;
    }
    if(temp_read_LSB & 0x08){
        temp_float += 0.5;
    }
    
    temp_fraction = temp_float*1000;
}

int approximation (int a){
    temp_hundreds = a/100;
    temp_tens = a - (temp_hundreds*100);
    
    temp_tens = temp_tens/10;
    temp_ones = a - (temp_hundreds*100) - (temp_tens*10);
    
    if (temp_ones >= 5){
        temp_tens += 1;
    }
    
    if (temp_tens >= 5){
        temp_hundreds +=1;
    }
    
    approx_value = temp_hundreds;
    
    return approx_value;
}

void obtainSign (void){
    temp_sign = (temp_read_MSB & 0xF8);
    
    if(temp_sign == 0){
        sprintf(tempVariable, "Temp: +%d.%d%cC", running_average_integer, running_average_fraction, temp_degree);
    }
    else{
        sprintf(tempVariable, "Temp: -%d.%d%cC", running_average_integer, running_average_fraction, temp_degree);
    }
}

void resetTempConversion (void){
    temp_float = 0.0;
    temp_integer = 0;
    temp_fraction = 0;
    temp_sign = 0;
}

void errorCalibration (void){
    counter = 0;
    
    configTemp();
    
    while (counter != 5){
        readTemp();
        obtainInteger();
        obtainFraction();
        temp_fraction = approximation(temp_fraction);
        
        sum_integer += temp_integer;
        temp_sum_fraction += temp_fraction;
        
        //Added code to accurately calculate the sum of temperature readings
        if(temp_sum_fraction > 9){
            sum_integer += 1;
            sum_fraction = temp_sum_fraction - 10;
        }
        else{
            sum_fraction = temp_sum_fraction;
        }
        //End of section----------------------------------------------------
        
        resetTempConversion();
        
        WriteCmdXLCD(0x01);
        while(BusyXLCD());
        sprintf(lcdVariable, "Time: %d", counter);
        putsXLCD(lcdVariable);
        while(BusyXLCD());
       
        counter++;
    }
    
    //AVERAGE
    //Section that divides the decimal portion of the reading
    decimal_division_initial_value = (float)sum_fraction/(float)(counter*10);
    integer_division_initial_value = sum_integer/counter;
    
    integer_variable_extraction = integer_division_initial_value;
    
    integer_division_value_to_add = integer_division_initial_value - (float)integer_variable_extraction;
    decimal_division_final_value = decimal_division_initial_value + integer_division_value_to_add; 
    decimal_division_final_value_integer = decimal_division_final_value*1000;
    
    
    average_integer = integer_variable_extraction;
    average_fraction = decimal_division_final_value_integer;
    
    average_fraction = approximation(average_fraction);
}

void runningAverage (void){
    counter2 += 1;
    
    sum_integer += temp_integer;
    temp_sum_fraction += temp_fraction;
        
    //Added code to accurately calculate the sum of temperature readings
    if(temp_sum_fraction > 9){
        sum_integer += 1;
        sum_fraction = temp_sum_fraction - 10;
    }
    else{
        sum_fraction = temp_sum_fraction;
    }
        
    decimal_division_initial_value = (float)sum_fraction/(float)(counter2*10);
    integer_division_initial_value = sum_integer/counter2;
    
    integer_variable_extraction = integer_division_initial_value;
    
    integer_division_value_to_add = integer_division_initial_value - (float)integer_variable_extraction;
    decimal_division_final_value = decimal_division_initial_value + integer_division_value_to_add; 
    decimal_division_final_value_integer = decimal_division_final_value*1000;
    
    running_average_integer = integer_variable_extraction;
    running_average_fraction = decimal_division_final_value_integer;
    
    running_average_fraction = approximation(running_average_fraction);
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

/*Speaker*/
void configSpeaker (void){
    TRISCbits.RC1 = 0;
    SetDCPWM2(30);
    
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
}

void alarm (void){
    OpenPWM2(0x65);
}

void checkRange (void){
    if((int1TotalPulse > 140) || (HRV_integer > 50)){
        ALARM = TRUE;
    }
}

void homeScreen (void){
    WriteCmdXLCD(0x01);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("Please choose: ");
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("1.Measure");
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    putrsXLCD("2.Store");
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    putrsXLCD("3.Retrieve");
    while(BusyXLCD());
}

void systemInit(void)
{
    configInterrupts();
    ADCON1bits.PCFG = 0b0111;
    TRISA = 0x00;
    PORTA = 0x00;
    TRISBbits.RB3 = 0;
    //   //Set Output Enable and Write Enable pins as Outputs
    WEtris = 0;
    OEtris = 0;
    WE = 1;
    OE = 1;
    sramSetDataPinTris(0);
    //   //Initialize LCD
    initLCD();
    //initSecErase();
    return;
}

void print ()
{
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putsXLCD(lcdVariable);
    while(BusyXLCD());
    return;
}

void printMeasurement (int lcdAdd)
{
    SetDDRamAddr(lcdAdd);
    while(BusyXLCD());
    putsXLCD(lcdVariable);
    while(BusyXLCD());
    return;
}

/*
 *This function will enable the Clock.
 */
void clock(void)
{
    CLK_595 = 1;
    Delay100TCYx(1);
    CLK_595 = 0;
    Delay100TCYx(1);
    return;
}

/*
 * This function will send the data to shift register
 */
void sramSetDataPinTris(short int x)
{
    D0tris = x;
    D1tris = x;
    D2tris = x;
    D3tris = x;
    D4tris = x;
    D5tris = x;
    D6tris = x;
    D7tris = x;
    return;
}

void sramLoadAddPins(short long data)
{
    short long i;
    for (i=0 ; i<19 ; i++)
    {
        DATA_595 = (data >> i) & 0x01;
        clock();
    }
    return;
}

int sramReadDataPins()
{
    int res = 0;
    int idx = 0;
    int i;
    int data[8] = {D0,D1,D2,D3,D4,D5,D6,D7};
        
    for (i = 1; i<=128; i*=2)
    {
        res += data[idx]*i;
        idx++;
    }

    return res;
}

void sramLoadDataPins(int data)
{
              
    D7 = (data & 128) && 128;
    D6 = (data & 64)  && 64;
    D5 = (data & 32)  && 32;
    D4 = (data & 16)  && 16;
    D3 = (data & 8)   && 8;
    D2 = (data & 4)   && 4;
    D1 = (data & 2)   && 2;
    D0 = (data & 1);
    
   
    //sprintf(lcdVariable, "data = %d", data);
    //print();

    return;
}

void sramLatch()
{
    WE = 0;         //The address bus is latched on the falling edge of WE# or CE#
    Delay1TCY();    //Twp wait for 40 ns
    WE = 1;         //The data bus is latched on the rising edge of WE# or CE#
    return;
}

void sramLoadData(short long add, int data)
{
    sramLoadDataPins(data);
    sramLoadAddPins(add);
    sramLatch();
    return;
}

void sramBusyData()
{ 
    //LED2 = 1;
    D7tris = 1;
    WE = 1;
    OE = 1;

    while (D7 == 0)
    {
        LED = 0;
    }
    LED = 1;

    // WE = 1;
    // OE = 0;
    D7tris = 0;
    return;
}

 int sramRead(short long add)
{
    /*
     The Read operation of the SST39SF010A/020A/040 is controlled by CE# and OE#, both have to be
     low for the system to obtain data from the outputs. CE# is used for device selection. When CE# is high,
     the chip is deselected and only standby power is consumed. OE# is the output control and is used to
     gate data from the output pins. The data bus is in high impedance state when either CE# or OE# is
     high. Refer to the Read cycle timing diagram (Figure 5) for further details.
     */
    int res = 0;
    //CE = 0
    WE = 1;
    OE = 1;
    
    sramSetDataPinTris(1);//Config Receiving GPIO pins on pic as inputs
    sramLoadAddPins(add);//Choose address to read from;

    OE = 0;

    //Wait for Toe = ()
    Delay1TCY();
    res = sramReadDataPins();
    
    return res;
}


void sramLoadSeq()
{

    //Seq 1
        //Load data: AAH = 1010 1010b
    // D7 = 1;
    // D6 = 0;
    // D5 = 1;
    // D4 = 0;
    // D3 = 1;
    // D2 = 0;
    // D1 = 1;
    // D0 = 0;
    sramLoadDataPins(0xAA);
    sramLoadAddPins(0x5555);//Address: 5555H 
    sramLatch();
    
    //Seq 2
        //Load data: 55H =101 0101
    // D7 = 0;
    // D6 = 1;
    // D5 = 0;
    // D4 = 1;
    // D3 = 0;
    // D2 = 1;
    // D1 = 0;
    // D0 = 1;
    sramLoadDataPins(0x55);
    sramLoadAddPins(0x2AAA);//Address: 2AAAAH
    sramLatch();
      
    //Seq 3
        //Load data: A0H = 1010 0000
    // D7 = 1;
    // D6 = 0;
    // D5 = 1;
    // D4 = 0;
    // D3 = 0;
    // D2 = 0;
    // D1 = 0;
    // D0 = 0;
    sramLoadDataPins(0xA0);
    sramLoadAddPins(0x5555);//Address: 5555H
    sramLatch();
    return;
}


void sramSecErase(int add)
{
    /*
        The Sector-Erase operation allows the system to erase the device on a sector-by-sector basis. The
        sector architecture is based on uniform sector size of 4 KByte. The Sector-Erase operation is initiated
        by executing a six-byte command load sequence for Software Data Protection with Sector-Erase command
        (30H) and sector address (SA) in the last bus cycle. The sector address is latched on the falling
        edge of the sixth WE# pulse, while the command (30H) is latched on the rising edge of the sixth WE#
        pulse. The internal Erase operation begins after the sixth WE# pulse. The End-of-Erase can be determined
        using either Data# Polling or Toggle Bit methods. See Figure 10 for timing waveforms. Any commands
        written during the Sector-Erase operation will be ignored.
     */
    sramSetDataPinTris(0);//Set GPIO pins connected to the sram data pins to outputs
    WE = 1;
    OE = 1;
    
    //1st Bus Write Cycle
    sramLoadDataPins(0xAA);
    sramLoadAddPins(0x5555);
    sramLatch();

    //2nd Bus Write Cycle
    sramLoadDataPins(0x55);
    sramLoadAddPins(0x2AAA);
    sramLatch();
    
    //3rd Bus Write Cycle 
    sramLoadDataPins(0x80); 
    sramLoadAddPins(0x5555);
    sramLatch();

    //4th Bus Write Cycle
    sramLoadDataPins(0xAA);
    sramLoadAddPins(0x5555);
    sramLatch();

    //5th Bus Write Cycle
    sramLoadDataPins(0x55);
    sramLoadAddPins(0x2AAA);
    sramLatch();

    //6th Bus Write Cycle
    sramLoadDataPins(0x30);
    sramLoadAddPins(add); //A18 - A12. For example: {111 111}1 1111 1111 1111
    sramLatch();

    //Delay for Tse = 25ms;
    Delay10KTCYx(2);
    Delay1KTCYx(1);
    Delay1KTCYx(1);
    Delay1KTCYx(1);
    Delay1KTCYx(1);
    Delay1KTCYx(1);
    Delay1KTCYx(1);

    //Wait for Data# (DQ6)
    //sramBusyData();
   // sprintf(lcdVariable,"Erase Completed!");
   // print();

    return;
}


void sramByteProgramOp(short long add, int data)
{
    /*
     * The SST39SF010A/020A/040 are programmed on a byte-by-byte basis. Before programming, the sector
        where the byte exists must be fully erased. The Program operation is accomplished in three steps.
        
     * The first step is the three-byte load sequence for Software Data Protection. 
     *
     * The second step is to load    address and byte data. During the Byte-Program operation, the addresses are latched on the falling
        edge of either CE# or WE#, whichever occurs last. The data is latched on the rising edge of either
        CE# or WE#, whichever occurs first. 
     * 
     * The third step is the internal Program operation which is initiated
       after the rising edge of the fourth WE# or CE#, whichever occurs first. The Program operation, once
       initiated, will be completed, within 20 ?s.
     */
    
    sramSetDataPinTris(0);//Set GPIO pins connect to the sram's data pins to outputs
    WE = 1;
    OE = 1;

    sramLoadSeq();          //Step 1
    sramLoadData(add, data);//Step 2
    //Step 3
    //Wait on read/write operations before exiting routine. Can choose to implement one of the three of the methods below:
        //method 1: Poll Data#
            //Nothing Implemented
        //method 2: Poll Toggle Bit
            //Nothing
        //method 3: Lazy man wait: Tbp = 20us (Byte-Program Time)
    Delay10TCYx(2);
    return;
}


/*SCROLL*/
void printMeasurementScreen(short long add)
{
    sprintf(lcdVariable, "Pulse: %dbpm", sramRead(add));
    printMeasurement(ROW1);
    sprintf(lcdVariable, "HRV: %d%", sramRead(add+1));
    printMeasurement(ROW2);
    sprintf(lcdVariable, "Temp: +%d.%d%cC", sramRead(add+2), sramRead(add+3), temp_degree);
    printMeasurement(ROW3);
    sprintf(lcdVariable,"Glucose:%dmg/dL", sramRead(add+4));
    printMeasurement(ROW4);

    return;
}

void menu (char key)
{ 
        switch(key)
        {
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
            setStorageInterval();
            setMeasurementNumber();
            break;  
        
        case '3':
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            displayScrollMeasurement();
            break;
            
        case 'D':
            homeScreen();
            stopPulseInterval();
            ALARM = FALSE;
        break;
        
        default:
            break;        
        }
}

void displayScrollMeasurement()
{
    short long upperLimit = (sramStorageIntCount-1)*5;
    short long currPtr = upperLimit;
    short long prevPtr = -1;
    char keypadInput = option; //Temporary input;
    press = 0;
    printMeasurementScreen(currPtr);
    while (option != 'D')
    {
        if ((option == 'A') && !(currPtr > upperLimit))
        {
            currPtr +=5;
            if(currPtr>upperLimit)
            {
                currPtr = upperLimit;
            }
        }
        if ((option == 'B') && !(currPtr < 0))
        {
            currPtr -=5;

            if (currPtr < 0)
            {
                currPtr = 0;
            }
        }

        if (prevPtr != currPtr)
        {
            WriteCmdXLCD(0x01);
            printMeasurementScreen(currPtr);
        }

        //Wait for new input
        
        while(!press)
        {
            keypadInput = option;
        }
        
        prevPtr = currPtr;
        press = 0;
    }
    menu(option);
 
    return;
}

void setStorageInterval()
{
    /*
    This function set the storage interval for the Flash Ram by reading in inputs from the keep pad and configuring Timer 3
    to interrupt at user-defined intervals in an ISR routine that is called periodically.
    */
    char keypadInput = 0;
    press = 0; //Reset Keypad press detection variable

    sprintf(lcdVariable, "1.Store/10s");
    printMeasurement(ROW1);
    sprintf(lcdVariable, "2.Store/20s");
    printMeasurement(ROW2);
    sprintf(lcdVariable, "3.Store/30s");
    printMeasurement(ROW3);
    sprintf(lcdVariable,"4.[C]ancel");
    printMeasurement(ROW4);

  
    
    while (option != 'C')
    {
                //Update keypress
        while (!press)
        {
            //keypadInput = option;
        }
        
        if (option == '1')
        {
           sramStorageInterval = 1;  
           break;      
        }
        if (option == '2')
        {
            sramStorageInterval = 2;
            break;
        }
        if (option ==  '3')
        {
            sramStorageInterval = 3;
            break;
        }
        
        press = 0;    
    }
    press = 0;
    sramStorageIntCount2 = 0; //Reset Storage interval counter

    return;
}

/*DANIEL GLADSTONE - Function to set the number of intervals to be stored in the FLASH RAM*/
void setMeasurementNumber(){
    char keypadInput = 0;
    press = 0;
    
    sprintf(lcdVariable, "1.Store 1 reading");
    printMeasurement(ROW1);
    sprintf(lcdVariable, "2.Store 2 readings");
    printMeasurement(ROW2);
    sprintf(lcdVariable, "3.Store 3 readings");
    printMeasurement(ROW3);
    sprintf(lcdVariable,"4.[C]ancel");
    printMeasurement(ROW4);
    
    while(option != 'C'){
         while (!press)
        {
            //keypadInput = option;
        }
        
        if(option == '1'){
            sramMeasurementCount = 1;
            break;
        }
        if(option == '2'){
            sramMeasurementCount = 2;
            break;
        }
        if(option == '3'){
            sramMeasurementCount = 3;
            break;
        }
         
        press = 0;
    } 
    press = 0;
 
    homeScreen();
    return;
}

void initSecErase()
{
    /*
    initial sector erase for the entire Flash Ram
    */
   
   short long secAdd, count;
   for(secAdd = 0, count = 0; secAdd<=520192; secAdd+=4096, count++)
   {
       sramSecErase(secAdd);
   }
   sprintf(lcdVariable, "SRAM Initialized");
   print();
   return;
}

void eraseFlashRamStartup (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("Erase Memory?");
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("A.Yes, B.No");
    while(BusyXLCD());
    
    while(!press){
        if(option == 'A'){
            initSecErase();
            press = 0;
            break;
        }
        if(option == 'B'){
            press = 0;
            break;
        }
    }
    
}

void configADC (void){
    OpenADC( ADC_FOSC_RC & ADC_RIGHT_JUST & ADC_1ANA_0REF, ADC_CH0 & ADC_INT_OFF ); // configure A/D convertor
    Delay10TCYx(1);
    while( BusyADC() ); // Wait for completion
    result = ReadADC(); // Read result
    Delay10TCYx(2);

    conversionV = 0.0056*result; //TEMPORARY VALUE FOR VOLTAGE IN V
    conversionG = 21.6*conversionV; //TEMPORARY VALUE FOR GLUCOSE IN mg/dL
    CloseADC(); // Disable A/D converter    
} 

int brownoutCount = 0;

void main (void){    
    configSupportCircuity();
    configSpeaker();
    configCCP();
    configTimers();
    
    systemInit();
    
    sramMeasurementCount = 0;
    sramStorageInterval = 0;

    sramCurrPtr = 0;
    
    /*This is for the Keypad data lines*/
    TRISCbits.RC4 = 1;
    TRISCbits.RC5 = 1;
    TRISCbits.RC6 = 1;
    TRISCbits.RC7 = 1;
    
    eraseFlashRamStartup();
    errorCalibration();   
    homeScreen();
    
    while(1){     
        if (KEY_PRESSED == TRUE){
            menu(option);
            KEY_PRESSED = FALSE;
            press = 0;
        }
        
        if(MEASUREMENT_COMPLETE == TRUE && COUNTING == FALSE){
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            resetTempConversion();
            readTemp();
            obtainInteger();
            obtainFraction();
            temp_fraction = approximation(temp_fraction);
            runningAverage();
            obtainSign();
            configADC();
            glucoseMeasurement = conversionG;
            if(int1TotalPulse == 0){
                //glucoseMeasurement = 0;
            }
            printPulse();                               //prints the result as long as the program is not currently counting
            printHRV();
            printTemp();
            printGlucose();
            //Delay10KTCYx(100);
            if(((sramStorageIntCount2%sramStorageInterval) == 0) && (sramStorageInterval != 0) && (sramMeasurementCount >= 1))
            {
                short long add1 = sramStorageIntCount*5;
                short long add2 = add1 + 1;
                short long add3 = add2 + 1;
                short long add4 = add3 + 1;
                short long add5 = add4 + 1;
                
                //LED2 = 1;
                   
                sramByteProgramOp(add1, int1TotalPulse);
                sramByteProgramOp(add2, HRV_integer);
                sramByteProgramOp(add3, running_average_integer);
                sramByteProgramOp(add4, running_average_fraction);
                sramByteProgramOp(add5, glucoseMeasurement);

                //LED2 = 0;
                sramStorageIntCount+=1;                 //count here will increment and the modulus of it will be taken with the sramStorageInterval
                sramMeasurementCount-=1;
            }
            sramStorageIntCount2+=1;
            
            MEASUREMENT_COMPLETE = FALSE;
        }
        
        if(BROWN_OUT == TRUE){
            brownOutSave+=1;
            
            if(brownOutSave == 1){
                sramByteProgramOp(4096 + brownoutCount , int1TotalPulse);
                sprintf(lcdVariable, "Saved: %dbpm", sramRead(4096 + brownoutCount));
                WriteCmdXLCD(0x01);
                printMeasurement(ROW1);
                sramByteProgramOp(4097 + brownoutCount, HRV_integer);
                sprintf(lcdVariable, "Saved: %d%", sramRead(4097 + brownoutCount));
                printMeasurement(ROW2);
                sramByteProgramOp(4098 + brownoutCount, running_average_integer);
                sramByteProgramOp(4099 + brownoutCount, running_average_fraction);
                sprintf(lcdVariable, "Saved: +%d.%d%cC", sramRead(4098 + brownoutCount), sramRead(4099 + brownoutCount), temp_degree);;
                printMeasurement(ROW3);
                sramByteProgramOp(4100 + brownoutCount, glucoseMeasurement);
                sprintf(lcdVariable, "Saved: %dmg/dL", sramRead(4100 + brownoutCount));
                printMeasurement(ROW4);
            }   
            brownoutCount += 5;
        }
        
        if(BROWN_OUT == FALSE){
            PORTBbits.RB4 = 1;
            Delay10KTCYx(5);      
            PORTBbits.RB4 = 0;
            Delay10KTCYx(5);
            brownOutSave = 0;
        }
        
        if(ALARM == TRUE){
            alarm();
        }
        
        if(ALARM == FALSE){
            ClosePWM2();
        }
    }  
    Sleep();
}