/* Set configuration bits for use with PICKit3 */
#include <p18f452.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <delays.h>
#include "xlcd.h"

 /*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system should allow a user to start storing a pre-de?ned set of measurements to external ?ash RAM, and to interrupt the ongoing storage of a set of measurements.

#define DATA_595 PORTAbits.RA0 
#define CLK_595 PORTAbits.RA1
#define LED     PORTBbits.RB4
#define LED2    PORTBbits.RB3
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

char lcdVariable[20]; //Variable to be printed to the LCD
int sramCurrPtr; //Variable to manage the address of SRAM
char option;
int press = 0;
int sramStorageInterval;

void systemInit(void);

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
 
void init_lcd(void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while (BusyXLCD())
        ;
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while (BusyXLCD())
        ;
    WriteCmdXLCD(FOUR_BIT & LINES_5X7);
    while (BusyXLCD())
        ;
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
//End of LCD Functions

//Keypad Stuff
void highISR (void);
void lowISR (void);
void configInterrupts (void);
int checkPressedKey (void);
void printLCD (void);

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
    
    /*Routine for external interrupt on INT1*/
    if(INTCON3bits.INT2IF == 1){
        INTCON3bits.INT2IE = 0;
        INTCON3bits.INT2IF = 0;
        
        checkPressedKey();
        press = 1;
        INTCON3bits.INT2IE = 1;
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
    
    INTCON2bits.INTEDG2 = 1;                            //sets the pin to interrupt on a low to high transition 
    
    INTCON3bits.INT2IP = 1;
    INTCON3bits.INT2IE = 1;                              //enables the INT1 interrupt source
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
//End of Keypad Stuff




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

void sramLoadData(int add, int data)
{
    sramLoadDataPins(data);
    sramLoadAddPins(add);
    sramLatch();
    return;
}

void sramBusyData()
{ 
    LED2 = 1;
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

volatile int sramRead(int add)
{
    /*
     The Read operation of the SST39SF010A/020A/040 is controlled by CE# and OE#, both have to be
     low for the system to obtain data from the outputs. CE# is used for device selection. When CE# is high,
     the chip is deselected and only standby power is consumed. OE# is the output control and is used to
     gate data from the output pins. The data bus is in high impedance state when either CE# or OE# is
     high. Refer to the Read cycle timing diagram (Figure 5) for further details.
     */
    volatile int res = 0;
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

void sramByteProgramOp(int add, int data)
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

void printMeasurementScreen(short int ptr)
{
    sprintf(lcdVariable, "Heart R. = %d", sramRead(ptr << 12));
    printMeasurement(ROW1);
    sprintf(lcdVariable, "Temp = %d", sramRead((ptr + (97)) << 12));
    printMeasurement(ROW2);
    sprintf(lcdVariable, "HRV = %d", sramRead((ptr + (64) << 12)));
    printMeasurement(ROW3);
    sprintf(lcdVariable,"Gluc. Lvl = %d", sramRead((ptr + 32) << 12));
    printMeasurement(ROW4);

    return;
}

void displayScrollMeasurement()
{
    int currPtr = 1;
    int prevcurrPtr = 0;

    char keypadInput = option; //Temporary input;
    press = 0;
    printMeasurementScreen(0);
    while (option != 'D')
    {
        
        if (keypadInput == 'A' && !(currPtr < 0))
        {
            currPtr ++;

            if (currPtr > 31)
            {
                currPtr = 31;
            }
        }
        else if (keypadInput == 'B' && !(currPtr > 31))
        {
            currPtr --;
            if (currPtr < 0)
            {
                currPtr = 0;
            }
        }

        if (prevcurrPtr != currPtr)
        {
            printMeasurementScreen(currPtr);
        }

        //Wait for new input
        
        while(!press)
        {
            keypadInput = option;
        }
        
        prevcurrPtr = currPtr;
        press = 0;
    }
    WriteCmdXLCD(0x01);
    return;
}

void setStorageInterval()
{
    /*
    This function set the storage interval for the Flash Ram by reading in inputs from the keep pad and configuring Timer 3
    to interrupt at user-defined intervals in an ISR routine that is called periodically.
    */
    char keypadInput;
    press = 0; //Reset Keypad press detection variable

    //Read input from keypad and store in the variable: 'interval'
    // A - Enter
    // B - Re-enter entire number
    // C - Cancel
    // D - Display Current Interval

    sprintf(lcdVariable, "1. Store/10s");
    printMeasurement(ROW1);
    sprintf(lcdVariable, "2. Store/20s");
    printMeasurement(ROW2);
    sprintf(lcdVariable, "3. Store/40s");
    printMeasurement(ROW3);
    sprintf(lcdVariable,"4. [C]ancel");
    printMeasurement(ROW4);

  
    
    while (keypadInput != 'C')
    {
                //Update keypress
        while (!press)
        {
            keypadInput = option;
        }
        
        if (keypadInput == '1')
        {
           sramStorageInterval = 1;  
           break;      
        }
        else if (keypadInput == '2')
        {
            //config timer 3 using interval 2;
            sramStorageInterval = 2;
            break;
        }
        else if (keypadInput ==  '3')
        {
            sramStorageInterval = 3;
            break;
        }
        
        press = 0;
    }
    WriteCmdXLCD(0x01);
    return;
}

void initSecErase()
{
    /*
    initial sector erase for the entire Flash Ram
    */
   
   short long i, count;
   for(i = 4096, count = 0; i<=520192; i+=4096, count++)
   {
       sramSecErase(i);
       if (count%2)sramByteProgramOp(i,count);
       else sramByteProgramOp(i,count);
   }
   sprintf(lcdVariable, "SRAM Initialized");
   print();
   return;
}

void main(void) 
{
    systemInit(); // System getting ready 

    //sprintf(lcdVariable, "SRam Data: %d", sramRead(520192));
    //print();
    
     while(1)
     {
          
   
          if (press == 1)
          {
              LED = 1;
              if(option == '1')
              {
               displayScrollMeasurement();
              }
              if (option == '2')
              {
                 setStorageInterval();
                 
              }
            
         }   
         LED = 0; 
         press = 0;
     }
    
    Sleep();
}
    
/*
 This Function is for system initiation.
 */

void systemInit(void)
{
    configInterrupts();
    ADCON1bits.PCFG = 0b0111;
    TRISA = 0x00;
    PORTA = 0x00;
    TRISBbits.RB4 = 0;
    TRISBbits.RB3 = 0;
    //   //Set Output Enable and Write Enable pins as Outputs
    WEtris = 0;
    OEtris = 0;
    WE = 1;
    OE = 1;
    sramSetDataPinTris(0);
    //   //Initialize LCD
    init_lcd();
    LED = 0;
    LED2 = 0;
    //initSecErase();
    return;
}