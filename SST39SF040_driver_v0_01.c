/* 
 * File:   floaties_main.c
 * Author: Luther Jn. Baptiste
 *
 * Created on October 15, 2018, 12:47 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include <p18cxxx.h>
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000
#define DATAPIN_OUT PORTEbits.RE1
#define DATAPIN_OUT_TRIS TRISEbits.RE1
#define DATAPIN_IN PORTCbits.RC3
#define DATAPIN_IN_TRIS TRISCbits.RC3
#define DATAOE_TRIS TRISEbits.RE2
#define DATAOE PORTEbits.RE2
#define DATA_CLOCK PORTDbits.RD0
#define DATA_CLOCK_TRIS TRISDbits.RD0
#define ADDRESS_CLOCK PORTDbits.RD1
#define ADDRESS_CLOCK_TRIS TRISDbits.RD1

#define ADDRESSPIN_TRIS TRISEbits.RE0
#define ADDRESSPIN_OUT PORTEbits.RE0

#define S01 PORTAbits.RA4
#define S01_TRIS TRISAbits.RA4

#define OE_TRIS TRISDbits.RD3
#define OE PORTDbits.RD3
#define WE_TRIS TRISDbits.RD2
#define WE PORTDbits.RD2

void clockDataOUT(void);
void clockAddressOUT(void);
void dataOUT_init(void);
void dataIN_init(void);
void addressOUT_init(void);   
void ram_init(void);
void strobeWE(void);
void clearOE(void);
void clearAddress(void);
void dataOUT(void);
void pushAddress(char, char *, int);
void pullData(void);
void pushData(char *);



/*
 * 
 */









volatile union uFloat HRV;
volatile union uFloat glucose;
volatile union uFloat HR;
volatile union uFloat Temp;


volatile union uFloat HRV_disp;
volatile union uFloat glucose_disp;
volatile union uFloat HR_disp;
volatile union uFloat Temp_disp;


float a = 1.5;
char byte1 = 0x00;
char byte2= 0x00;
char byte3= 0x00;
char byte4= 0x00;
int v = 0;
int clearAddressCount;
rom char softIDadd[6] = {0x55,0x55,0x2A,0xAA,0x55,0x55};
rom char softIDdat[3] = {0xAA,0x55,0x90};
rom char SectorEraseADD[12] ={0x55,0x55,0x2A,0xAA,0x55,0x55,0x55,0x55,0x2A,0xAA,0x01,0x00};
rom char SectorEraseDAT[6] = {0xAA, 0x55, 0x80, 0xAA,0x55, 0x30};
//char writeADD1[8] = {0x55,0x55,0x2A,0xAA,0x55,0x55,0x01,0x02};
//char writeADD2[8] = {0x55,0x55,0x2A,0xAA,0x55,0x55,0x01,0x03};
rom unsigned int writeADD = {0x5555,0x2AAA,0x5555}
rom char writeDAT = {0xAA,0x55,0xA0}
//char writeDAT[5] = {0xAA,0x55,0xA0,0x99,0x66};


void clockDataOUT(void)
{
    DATA_CLOCK = 0;
    Nop();
    DATA_CLOCK = 1;
}

void clockAddressOUT(void)
{
    ADDRESS_CLOCK = 0;
    Nop();
    ADDRESS_CLOCK = 1;
}



void dataOUT_init()
{
   DATAOE_TRIS = 0; //inhibit output
   DATAOE = 1;
   S01_TRIS = 0;// configure for right shift
   S01 = 0;
   DATAPIN_OUT_TRIS = 0;// configure output pin
   DATA_CLOCK_TRIS = 0; // configure data clock pin
       
}



void addressOUT_init()
{
   ADDRESSPIN_TRIS = 0;// configure output pin
   ADDRESS_CLOCK_TRIS = 0; // configure data clock pin
       
}
void ram_init()
{
    OE_TRIS = 0;
    WE_TRIS = 0;
    WE = 1;
    OE = 1;   
}

void strobeWE()
{
    TRISDbits.RD2 = 0;
    _asm 
    BSF PORTD , 2, 0
    NOP
    BCF PORTD , 2, 0
    NOP
    BSF PORTD , 2, 0
    _endasm
}

void clearOE()
{
    OE = 0;
}
void setOE()
{
    OE = 1;
}

void clearAddress()
{
    ADDRESSPIN_OUT = 0;
    for(clearAddressCount = 0; clearAddressCount < 20; clearAddressCount++)
    {
        clockAddressOUT();
    }
    
}

void dataOUT()
{
    DATAOE = 0;// enable output
}


void pushAddress(char sector, char *addr, int offSet)
{
    
    addressOUT_init();
    clearAddress();
    TXbitsADDR.CHARBITS = sector;
    ADDRESSPIN_OUT = TXbitsADDR.B2;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B1;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B0;
    clockAddressOUT();
    
    TXbitsADDR.CHARBITS = *(addr + offSet);
    ADDRESSPIN_OUT = TXbitsADDR.B7;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B6;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B5;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B4;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B3;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B2;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B1;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B0;
    clockAddressOUT();
    
    TXbitsADDR.CHARBITS = *(addr + offSet + 1);
    ADDRESSPIN_OUT = TXbitsADDR.B7;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B6;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B5;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B4;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B3;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B2;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B1;
    clockAddressOUT();
    ADDRESSPIN_OUT = TXbitsADDR.B0;
    clockAddressOUT();    
}

pushAddress2(char sector, unsigned int ADDRESS)
{
  union uADDRESS addr;
  addr = ADDRESS;

  addressOUT_init();
  clearAddress();
  TXbitsADDR.CHARBITS = sector;
  ADDRESSPIN_OUT = TXbitsADDR.B2;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B1;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B0;
  clockAddressOUT();
  
  TXbitsADDR.CHARBITS = addr.adCHAR[0];
  ADDRESSPIN_OUT = TXbitsADDR.B7;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B6;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B5;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B4;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B3;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B2;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B1;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B0;
  clockAddressOUT();
  
  TXbitsADDR.CHARBITS = addr.adCHAR[1];
  ADDRESSPIN_OUT = TXbitsADDR.B7;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B6;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B5;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B4;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B3;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B2;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B1;
  clockAddressOUT();
  ADDRESSPIN_OUT = TXbitsADDR.B0;
  clockAddressOUT();    
}

void dataIN_init()
{
    DATAOE = 1; //inhibit output
    DATAOE_TRIS = 0; //inhibit output
    DATAPIN_IN_TRIS = 1;
    S01 = 1;
    clockDataOUT(); // parallel load
    S01 = 0;
}

void pullData()
{ 
    dataIN_init();
    RXbits.B7 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B6 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B5 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B4 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B3 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B2 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B1 = DATAPIN_IN;
    clockDataOUT();
    RXbits.B0 = DATAPIN_IN;
    /*undo dataIN_init here?*/
}

void pushData(char *data)
{
    dataOUT_init();
    TXbitsDATA.CHARBITS = *data;
    DATAPIN_OUT = TXbitsDATA.B7;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B6;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B5;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B4;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B3;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B2;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B1;
    clockDataOUT();
    DATAPIN_OUT = TXbitsDATA.B0;
    clockDataOUT(); 
    dataOUT();
}

void writeDATA(char sector, unsigned int ADDRESS, char *data)
{
  pushAddress2(SECTOR0,writeADD[0]);
  pushData(&writeDAT[0]);
  strobeWE();
  pushAddress2(SECTOR0,writeADD[1]);
  pushData(&writeDAT[0]);
  strobeWE();
  pushAddress2(SECTOR0,writeADD[2]);
  pushData(&writeDAT[0]);
  strobeWE();
  pushAddress2(sector, ADDRESS);
  pushData(data);
  strobeWE();
}

void readDATA(char sector unsiged int ADDRESS)
{
  pushAddress2(sector, ADDRESS);
  pullData();
}

    
volatile union uFloat HRV;
volatile union uFloat glucose;
volatile union uFloat HR;
volatile union uFloat Temp;


volatile union uFloat HRV_disp;
volatile union uFloat glucose_disp;
volatile union uFloat HR_disp;
volatile union uFloat Temp_disp;

char fives = 0x55;
char tens = 0xAA;


sectorErase(char SECTOR)
{
     pushAddress(SECTOR,SectorEraseADD,0);
   pushData(&SectorEraseDAT[0]);
//   Delay10KTCYx(50);
    strobeWE();
  
    
   pushAddress(SECTOR,SectorEraseADD,2);
   pushData(&SectorEraseDAT[1]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(SECTOR,SectorEraseADD,4);
   pushData(&SectorEraseDAT[2]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(SECTOR,SectorEraseADD,6);
   pushData(&SectorEraseDAT[3]);
//   Delay10KTCYx(50);
    strobeWE();
    
       pushAddress(SECTOR,SectorEraseADD,8);
   pushData(&SectorEraseDAT[4]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(SECTOR,SectorEraseADD,10);
   pushData(&SectorEraseDAT[5]);
//   Delay10KTCYx(50);
    strobeWE();
}







void main(void) {
    TRISB = 0x00;
    /*pushfloat(&a);
    //RXbits.RXchar = 0xAA;
    HRV.floatCHAR[0] = 0x00;
    HRV.floatCHAR[1] = 0x00;
    HRV.floatCHAR[2] = 0xC0;
    HRV.floatCHAR[3] = 0x38;
    tst = HRV.floatVal;
    TXbits.CHARBITS = HRV.floatCHAR[3];
    TRISB = 0x00;
    PORTBbits.RB0 = TXbits.B0;
    PORTBbits.RB1 = TXbits.B1;
    PORTBbits.RB2 = TXbits.B2;
    PORTBbits.RB3 = TXbits.B3;
    PORTBbits.RB4 = TXbits.B4;
    PORTBbits.RB5 = TXbits.B5;
    PORTBbits.RB6 = TXbits.B6;
    PORTBbits.RB7 = TXbits.B7;*/
   
    ram_init();
    PORTB= 0xAB;
   Delay10KTCYx(50);
   pullData();
   PORTB = RXbits.CHARBITS;
   Delay10KTCYx(50);
   
//    pushAddress(softIDadd,0);
//    pushData(&softIDdat[0]);
// //   Delay10KTCYx(50);
//    strobeWE();
////
//    pushAddress(softIDadd,2);
//    pushData(&softIDdat[1]);
// //   Delay10KTCYx(50);
//    strobeWE();
////    
//    pushAddress(softIDadd,4);
//    pushData(&softIDdat[2]);
// //   Delay10KTCYx(50);
//    strobeWE();

   pushAddress(SectorEraseADD,0);
   pushData(&SectorEraseDAT[0]);
//   Delay10KTCYx(50);
    strobeWE();
  
    
   pushAddress(SectorEraseADD,2);
   pushData(&SectorEraseDAT[1]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(SectorEraseADD,4);
   pushData(&SectorEraseDAT[2]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(SectorEraseADD,6);
   pushData(&SectorEraseDAT[3]);
//   Delay10KTCYx(50);
    strobeWE();
    
       pushAddress(SectorEraseADD,8);
   pushData(&SectorEraseDAT[4]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(SectorEraseADD,10);
   pushData(&SectorEraseDAT[5]);
//   Delay10KTCYx(50);
    strobeWE();
    
    Delay10KTCYx(50);
    
    
    // write
    
       pushAddress(writeADD1,0);
   pushData(&writeDAT[0]);
//   Delay10KTCYx(50);
    strobeWE();
  
    
   pushAddress(writeADD1,2);
   pushData(&writeDAT[1]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(writeADD1,4);
   pushData(&writeDAT[2]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
   pushAddress(writeADD1,6);
   pushData(&writeDAT[3]);
   strobeWE();
   
 
   Delay10KTCYx(50);
 
       // write again
    
       pushAddress(writeADD1,0);
   pushData(&writeDAT[0]);

    strobeWE();
  
    
   pushAddress(writeADD1,2);
   pushData(&writeDAT[1]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
       pushAddress(writeADD1,4);
   pushData(&writeDAT[2]);
//   Delay10KTCYx(50);
    strobeWE();
    
    
   pushAddress(writeADD2,6);
   pushData(&writeDAT[4]);
   strobeWE();
   
   
   
   while (1){
   Delay10KTCYx(50);
   pushAddress(writeADD1,6);
    DATAOE = 1;
    clearOE();
    //WEvv = 1;
    //Delay10KTCYx(50);
    //E = 1;
   pullData();
   PORTB = RXbits.CHARBITS;
   setOE();
   Delay10KTCYx(50);
    pushAddress(writeADD2,6);
    DATAOE = 1;
    clearOE();
    //WEvv = 1;
    //Delay10KTCYx(50);
    //E = 1;
   pullData();
   PORTB = RXbits.CHARBITS;
   }
   

    
}

