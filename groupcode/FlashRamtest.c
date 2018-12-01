/* Set configuration bits for use with PICKit3 */
#include <p18f452.h> 
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include "xlcd.h"

 /*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system should allow a user to start storing a pre-de?ned set of measurements to external ?ash RAM, and to interrupt the ongoing storage of a set of measurements.

#define DATA_595 PORTAbits.RA0 
#define CLK_595 PORTAbits.RA1
//#define LED     PORTBbits.RB4
//#define LED2    PORTBbits.RB3
#define OE      PORTBbits.RB3
#define WE      PORTBbits.RB5
#define D0      PORTDbits.RD0
#define D1      PORTDbits.RD1
#define D2      PORTDbits.RD2
#define D3      PORTDbits.RD3
#define D4      PORTDbits.RD4
#define D5      PORTDbits.RD5
#define D6      PORTDbits.RD6
#define D7      PORTDbits.RD7
#define OEtris  TRISBbits.RB3
#define WEtris  TRISBbits.RB5
#define D0tris  TRISDbits.RD0
#define D1tris  TRISDbits.RD1
#define D2tris  TRISDbits.RD2
#define D3tris  TRISDbits.RD3
#define D4tris  TRISDbits.RD4
#define D5tris  TRISDbits.RD5
#define D6tris  TRISDbits.RD6
#define D7tris  TRISDbits.RD7

char lcdVariable[20]; //Variable to be printed to the LCD

void systemInit(void);
void sramLatch(void);
void sramByteProgramOp(short long,int);
void sramSecErase(short long);
void sramLoadSeq(void);
void DelayPORXLCD(void);
void DelayFor18TCY(void);
void DelayPORXLCD(void);
void init_lcd(void);
void print (void);
void clock(void);
void sramSetDataPinTris(int x);
void sramLoadAddPins(short long);
void sramLoadDataPins(int);
int sramReadDataPins(void);
void sramBusyData(void);
short long sramRead(short long);
void sramLoadDataPins(int);



void main(void) 
{
    systemInit(); // System getting ready 

    while(1)
     {
    // D7 = 1;
    // D6 = 0;
    // D5 = 1;
    // D4 = 0;
    // D3 = 1;
    // D2 = 0;
    // D1 = 1;
    // D0 = 1;

    //sramLoadDataPins(0xAA);
   sramSecErase(0);
   sramByteProgramOp(12, 15);
   sprintf(lcdVariable, "SRam Data: %d", sramRead(12));
   print();
    Delay10KTCYx(100);
    }

    //sramLoadAddPins(0x00FFFF); //Testing Address loading function
    PORTAbits.RA0 =1;
    Sleep();
}
 
//LCD FUnctions
void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
}
 
void DelayXLCD(void)
{                               //1000us = 1ms
    Delay1KTCYx(5);  
}
 
void DelayPORXLCD(void)
{
    Delay1KTCYx(15);
}
 
void init_lcd(void){ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
     WriteCmdXLCD(FOUR_BIT & LINES_5X7);
}

void print ()
{
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putsXLCD(lcdVariable);
    while(BusyXLCD());
    return;
}
//End of LCD Functions


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
void sramSetDataPinTris(int x)
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
    
   // sprintf(lcdVariable, "data = %ld" << )
    
    for (i=0 ; i<19 ; i++)
    {
        DATA_595 = ((data << i) & 0x40000) && 0x40000;//
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
    
    //sprintf (lcdVariable, "SRAM = %d%d%d%d%d%d%d%d", D7,D6,D5,D4,D3,D2,D1,D0);
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
        //LED = 0;
    }
    //LED = 1;

    // WE = 1;
    // OE = 0;
    D7tris = 0;
    return;
}

short long sramRead(short long add)
{
    /*
     The Read operation of the SST39SF010A/020A/040 is controlled by CE# and OE#, both have to be
     low for the system to obtain data from the outputs. CE# is used for device selection. When CE# is high,
     the chip is deselected and only standby power is consumed. OE# is the output control and is used to
     gate data from the output pins. The data bus is in high impedance state when either CE# or OE# is
     high. Refer to the Read cycle timing diagram (Figure 5) for further details.
     */
    short long res = 0;
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

void sramSecErase(short long add)
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
    //Wait on read/write operations before exiting routine.
        //method 1: Poll Data#
            //Nothing
        //method 2: Poll Toggle Bit
            //Nothing
        //method 3: Lazy man wait: Tbp = 20us (Byte-Program Time)
    Delay10TCYx(2);
    return;
}

/*
 This Function is for system initiation.
 */

void systemInit(void)
{
    ADCON1bits.PCFG = 0b0111;
    //TRISD = 0x00;
    TRISAbits.RA1 = 0;
    TRISAbits.RA0 = 0;
    //PORTA = 0x00;
    //TRISBbits.RB4 = 0;
    //TRISBbits.RB3 = 0;
    //   //Set Output Enable and Write Enable pins as Outputs
    WEtris = 0;
    OEtris = 0;
    WE = 1;
    OE = 1;
    sramSetDataPinTris(0);
    //   //Initialize LCD
    init_lcd();
    //LED = 1;
    //LED2 = 0;

    return;
}
