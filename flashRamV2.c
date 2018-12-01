#include <delays.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <p18f452.h> 
//#include "xlcd_A.h"


/* Write the appropriate code to set configuration bits: * - set HS oscillator * - disable watchdog timer * - disable low voltage programming */
#pragma config OSC = HS
#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000

//CHANGE THE PINS LATER!!!!!!!!!!!

#define Clock      LATAbits.LATA2
#define Clock_Tris TRISAbits.TRISA2

#define Latch      LATAbits.LATA1
#define Latch_Tris TRISAbits.TRISA1

#define Data        LATAbits.LATA0
#define Data_Tris   TRISAbits.TRISA0

#define CE         PORTBbits.RB5
#define CE_Tris    TRISBbits.TRISB5

#define OE         PORTBbits.RB3
#define OE_Tris    TRISBbits.TRISB3

#define WE         PORTBbits.RB0 
#define WE_Tris    TRISBbits.TRISB0

#define Heartbeat  PORTBbits.RB4 
#define Heartbeat_Tris    TRISBbits.TRISB4

// Seriously change these pins!!

#define D0         PORTAbits.RA3
#define D0_Tris    TRISAbits.TRISA3

#define D1         PORTAbits.RA4
#define D1_Tris    TRISAbits.TRISA4

#define D2         PORTAbits.RA5 
#define D2_Tris    TRISAbits.TRISA5

#define D3         PORTAbits.RA6
#define D3_Tris   TRISAbits.TRISA6

#define D4         PORTEbits.RE0
#define D4_Tris    TRISEbits.TRISE0

#define D5        PORTEbits.RE1
#define D5_Tris    TRISEbits.TRISE1

#define D6         PORTEbits.RE2
#define D6_Tris   TRISEbits.TRISE2

#define D7         PORTCbits.RC0
#define D7_Tris    TRISCbits.TRISC0



#define OUTPUT 0
#define INPUT 1

#define l1 0x00 //addresses of the beginning of line1
#define l2 0x44 //addresses of the beginning of line2
#define l3 0x10 //addresses of the beginning of line3
#define l4 0x50 //addresses of the beginning of line4




void ramPinConfig(void){
   // ADCON1 = (0b00000111);
    ADCON1bits.PCFG = 0b0111;
    TRISEbits.PSPMODE =0;
    Clock_Tris = 0;
    Latch_Tris = 0;
    Data_Tris = 0;
    CE_Tris   = OUTPUT;
    OE_Tris   = OUTPUT;
    WE_Tris = OUTPUT;
    Heartbeat_Tris =0;
    
}

void dataPinConfig( short int a){
    D7_Tris =a;
    D6_Tris =a;
    D5_Tris =a;
    D4_Tris =a;
    D3_Tris =a;
    D2_Tris =a;
    D1_Tris =a;
    D0_Tris =a;

}


void clearAddress(void){
   int i = 0;
   //ramPinConfig();
    Latch=0;
    
    Nop();
    Nop();
    Nop();
    Clock=0;
    while ( i <19)
    {
      Data =0;
        Nop();
        Nop();
        Clock = 1;
        //Delay1KTCYx(20);
        //Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
        Clock =0;
       // Delay1KTCYx(20);
       // Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
       i++;
    }
    
        Latch = 1;
    // Delay1KTCYx(20);
   // Delay10KTCYx(100);  
    Nop();
    Nop();
    Nop();
    
    Latch =0;
    
 
    
    
    

}



  
void setAddress(long x){
    
 int i=0;
 //int mulTwo;
 // ramPinConfig();
  clearAddress();
// Clear all address pins
     //   mulTwo =1;
    Latch=0;
    Clock=0;
  
    // Delay10KTCYx(100);
     while (i<19)
     {
       Data = (x >>i) & 0x01;
        Nop();
        Nop();
        Clock = 1;
        //Delay1KTCYx(20);
         //Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
        Clock =0;
       // Delay1KTCYx(20);
    // Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
        i++;
        //mulTwo = mulTwo*2;
    
        Latch = 1;
    // Delay1KTCYx(20);
    // Delay10KTCYx(100);  
    Nop();
    Nop();
    Nop();
    
    Latch =0;
    
    //Delay10KTCYx(100);
     }
  


}

void sectorDelete(long address){
    
    dataPinConfig(0);
    CE=0; //set Chip enable low
    OE=1; 
    WE = 1;
    
    //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    
    setAddress(0X5555);
    
 
    
    WE =0;
    Nop();
    WE=1;
    Nop();
    
    //set data to 55H
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);
    
   
    
    WE =0;
    Nop();
    WE =1;
    
     //set data to 80H
    D7 =1;
    D6 =0;
    D5 =0;
    D4 =0;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(0X5555);
    
    //set data to 80H
    
    
    WE =0;
    Nop();
    WE =1;
    
    
    
    
    //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    setAddress(0X5555);
    
  
   
    
    WE =0;
    Nop();
    WE =1;
    
    
    
    //set data to 55H
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);
    
    
    WE =0;
    Nop();
    WE =1;
    
    
    //set data to 30H
    D7 =0;
    D6 =0;
    D5 =1;
    D4 =1;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(address);
    
   
    
    WE =0;
    Nop();
    WE =1;
    
    Delay1KTCYx(25); //wait for 25 ms for sector delete to complete
    
   // CE=1;
    
    

}

int readFromRam (long readAddress ){
 
   int dataRead =0;
   
   CE =0;
   WE=1;
   OE=1;
   
   dataPinConfig(1);
   
   setAddress(readAddress);
   
   OE=0;
   
   Nop();
   
   dataRead = (D0*1)+(D1*2)+(D2*4)+(D3*8)+(D4*16)+(D5*32)+(D6*64)+(D7*128);
   
   
   return dataRead;

}


void wirteToRam(long writeAddress, int writeData){

    dataPinConfig(0);
    
    sectorDelete(writeAddress);
    
    WE=1;
    OE=1;
    CE =0;
    
      //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    setAddress(0X5555);
    
  
    
    WE =0;
    Nop();
    WE =1;
    
    
    
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);
    //set data to 55H
    
    
    WE =0;
    Nop();
    WE =1;
    
    //Set data to A0H
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(0X5555);
    
    
    WE =0;
    Nop();
    WE =1;
    
    
   
     //Set data to the data to be written
    D7 = (writeData & 128) && 128;
    D6 = (writeData & 64) && 64;
    D5 = (writeData & 32) && 32;
    D4 = (writeData & 16) && 16;
    D3 = (writeData & 8) && 8;
    D2 = (writeData & 4) && 4;
    D1 = (writeData & 2)&& 2;
    D0 = writeData & 1;
    setAddress(writeAddress);
    
   
    
    WE =0;
    Nop();
    WE =1;
    
   Delay10KTCYx(20);  


}


void main(void) {
    
    int dataWrite =100;
    int dataRead =0;
    ramPinConfig();
    wirteToRam(1,dataWrite);
    dataRead = readFromRam(1);
   //void ramPinConfig();
    Heartbeat_Tris =0;
    Heartbeat =0;
    
    if (dataWrite == dataRead)
    { 
     Heartbeat =1;
    }//;
    
   // setAddress(1023);
        //Sleep();
   // clock();
   //clearAddress();
     
   //Latch =0;
    //while(1);
}