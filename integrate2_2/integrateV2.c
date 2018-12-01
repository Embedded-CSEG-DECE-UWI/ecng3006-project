#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>
#include <math.h> 
#include "ow.h"

#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000UL

// Keypad Defines
#define TRIS_INT2   TRISBbits.RB2
#define INT2        PORTBbits.RB2

#define TRIS_DATA0  TRISCbits.RC6
#define DATA0       PORTCbits.RC6

#define TRIS_DATA1  TRISCbits.RC5
#define DATA1       PORTCbits.RC5

#define TRIS_DATA2  TRISCbits.RC4
#define DATA2       PORTCbits.RC4

#define TRIS_DATA3  TRISDbits.RD3
#define DATA3       PORTDbits.RD3


// Temp Defines
#define OW_LAT LATCbits.LATC7
#define OW_PIN PORTCbits.RC7
#define OW_TRIS TRISCbits.TRISC7

#define OUTPUT 0
#define INPUT 1

#define l1 0x00 //addresses of the beginning of line1
#define l2 0x44 //addresses of the beginning of line2
#define l3 0x10 //addresses of the beginning of line3
#define l4 0x50 //addresses of the beginning of line4
/*************Global Variable Declarations*********************/
char display;
int data;
int heartBeats =0;
int perm1=0;
char heartBeatDisplay[20];
char tempDisplay[3];


/*********************Function Declarations*************************/
void DelayFor18TCY(void){
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}

void init_LCD(void){
     
    PORTD = 0x00;
    TRISD = 0x00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
 }

 void init_Timer0(void){
 
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
}
 void start(void){
     
    init_Timer0();
    INTCONbits.TMR0IE = 1;          //Enable Timer0 Interrupt
    INTCONbits.TMR0IF = 0;          //Clear Timer0 Interrupt Flag
    INTCON2bits.TMR0IP = 1;          //Timer0 High Priority
    WriteTimer0(0x676A);            //Timer interrupts at 10s w/256 prescaler
    TRISBbits.RB1=1;
    TRISCbits.RC3 = 0;
    PORTCbits.RC3 =1;
    perm1 = 0;

}

void stop(void){
    perm1=1;
    PORTCbits.RC3 =0;
    INTCON3bits.INT1IE = 0;
    CloseTimer0();
    
    if(perm1==1){
    while(BusyXLCD());
    SetDDRamAddr(0x40); //Set cursor to top line
    while(BusyXLCD());
    Delay1KTCYx(110); //Give time for LCD to refresh, writing to it too quickly causes flicker issues
    while(BusyXLCD());
    heartBeats = (6*heartBeats);
    sprintf(heartBeatDisplay,"HR:%d BPM",heartBeats);
    putsXLCD(heartBeatDisplay); 
    heartBeats =0;
    
    }
}

void heartBeatCount(void){

    if(perm1==0){
    heartBeats++;
    while(BusyXLCD());
    SetDDRamAddr(0x40); //Set cursor to top line
    while(BusyXLCD());
    Delay1KTCYx(110); //Give time for LCD to refresh, writing to it too quickly causes flicker issues
    while(BusyXLCD());
    sprintf(heartBeatDisplay,"HRC: %d",heartBeats);
    putsXLCD(heartBeatDisplay); 
    }    
 } 
// configures the temperature sensor
void tempConfig(void) {
 
  ow_reset(); //initialize the temp sensor
  ow_write_byte(0x0C); // master issues write to status command
  ow_write_byte(0x00); // writes to the status for continuous, one wire mode
  ow_reset(); //reset the device
  ow_write_byte(0xAC); // writes to the status for continuous, one wire mode
  ow_reset();

}

//measures the temperature value
float measureTemp(void)

{
  int loop = 0;
  float tempAvg = 0.0;
  int tempRead, tempTotal = 0;

  while (loop < 150) {
   
    ow_write_byte(0xEE); // begin temperature conversion
    ow_write_byte(0x22); //stop temperature                                                                                                                                                                                                                                                                                                                                                                     
    ow_reset(); //reset the device
    ow_write_byte(0xAA); //master issuses read temperature command
    tempRead = ow_read_byte(); // master reads temp value
    ow_reset();
    tempTotal = tempTotal + tempRead;
    loop++;

  }
  tempAvg = (float) tempTotal / 150;

  return tempAvg;
}
// reverses a string 'str' of length 'len' 
void reverse(char * str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

// Converts a given integer x to string str[].  d is the number 
// of digits required in output. If d is more than the number 
// of digits in x, then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) {
  int i = 0;
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }

  // If number of digits required is more, then 
  // add 0s at the beginning 
  while (i < d)
    str[i++] = '0';

  reverse(str, i);
  str[i] = '\0';
  return i;
}

// Converts a floating point number to string. 
void ftoa(float n, char * res, int afterpoint) {
  // Extract integer part 
  int ipart = (int) n;

  // Extract floating part 
  float fpart = n - (float) ipart;

  // convert integer part to string 
  int i = intToStr(ipart, res, 0);

  // check for display option after point 
  if (afterpoint != 0) {
    res[i] = '.'; // add dot 

    // Get the value of fraction part upto given no. 
    // of points after dot. The third parameter is needed 
    // to handle cases like 233.007 
    fpart = fpart * pow(10, afterpoint);

    intToStr((int) fpart, res + i + 1, afterpoint);
  }
}

float tempRecord;
void tempdisplay(void){  
        DelayPORXLCD();
    while (BusyXLCD());
    putsXLCD( );
    while (BusyXLCD());
    SetDDRamAddr(0x50);
}
void keypad(void){
        data =(DATA0*1+ DATA1*2 + DATA2*4 +DATA3*8);
        
        
        
        switch (data)
        {
            case (0): //case0
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='1';
                break;
            
            case(1): //case1
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='2';
                break;
                
            case(2)://case2
                while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='3';
                break;
                
            
            case (3): //case3
                
                //TRISBbits.RB1 = 1;

                start();
                break;
            
            case (4): //case4
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='4';
                break;
                
            case(5): //case5
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='5';
                break;       
       
            
            case(6)://case6
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='6';
                break;
                
            case(7)://case7
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='B';
                break;
                 
            case(8)://case8
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='7';
                break;
                
            case(9)://case9
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='8';
                break; 
              
              
            case(10)://case10
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='9';
                break;
                
            case(11)://case11
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='C';
                break;    
            
            case(12)://case12
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='*';
                break;
                
            case(13)://case13
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='0';
                break;
      
            
            case(14)://case14
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='#';
                break;
                
            case(15):
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='D';       
                break;
                
            default:
                  while(BusyXLCD());
               WriteCmdXLCD(0x01);
                display ='?';
                break;
        }
        
    DelayPORXLCD();
    //while(BusyXLCD());
    //SetDDRamAddr(0x50);
    while (BusyXLCD());
    putcXLCD(display);
    //WriteCmdXLCD(DOFF);
    while (BusyXLCD());
    SetDDRamAddr(0x00);
}

/******************INTERRUPT THINGS******************/
void high_ISR(void);
 
#pragma code high_vector = 0x08
 void high_interrupt_vector(void){
     _asm 
     GOTO high_ISR
     _endasm
 }
#pragma code 
 
#pragma interrupt high_ISR
void high_ISR(void){
    INTCONbits.GIE = 0;
    
    if(INTCON3bits.INT2IF==1){
        INTCON3bits.INT2IE = 0;
        keypad();
        INTCON3bits.INT2IF = 0;
        INTCON3bits.INT2IE = 1;      
    }
        
    if(INTCON3bits.INT1IF==1){
        INTCON3bits.INT1IE = 0;
        heartBeatCount();
        INTCON3bits.INT1IF = 0;
        INTCON3bits.INT1IE = 1;
    }
    
    if(INTCONbits.TMR0IF==1){
        INTCONbits.TMR0IE= 0;
        stop();
        INTCONbits.TMR0IF==0;
    }
    INTCONbits.GIE = 1;
    return;
}


/******************MAIN CODE******************/
 
 void main(void){
     
    init_LCD();


     INTCON2bits.TMR0IP = 1;
     INTCON2bits.INTEDG2 = 1;     
     INTCON2bits.INTEDG1 = 0;
     
     INTCON3bits.INT2IE  =1; 
     INTCON3bits.INT2IP= 1;  //RB2 Interrupt Priority Level - High
     
     INTCON3bits.INT1IP = 1;    //RB1 Interrupt Priority Level - High
     INTCON3bits.INT1IE = 1;    //RB1 Interrupt on Falling Edge 
     
     RCONbits.IPEN = 1;              //Enable Priority Levels
     INTCONbits.GIE = 1;
  
     TRIS_INT2 =1;
     TRIS_DATA0 =1;
     TRIS_DATA1 =1;
     TRIS_DATA2 =1;
     TRIS_DATA3 =1;
     tempConfig();
     while(1){tempRecord = measureTemp();

    ftoa(tempRecord, tempDisplay, 1);// converts the floating point temperature value to a string/character array
    tempdisplay();
  
     
 }
 }