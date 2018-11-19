/* Set configuration bits for use with PICKit3 */
#include <p18f452.h> 
#include <delays.h>

 /*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system should allow a user to start storing a pre-de?ned set of measurements to external ?ash RAM, and to interrupt the ongoing storage of a set of measurements.

#define DATA_595 PORTAbits.RA0
#define STROBE_595 PORTAbits.RA2
#define CLK_595 PORTAbits.RA1
#define LED PORTBbits.RA3
#define OE  PORTCbits.RC3
#define WE  PORTDbits.RD3
#define D0  PORTAbits.RA2
#define D1  PORTAbits.RA3
#define D2  PORTAbits.RA4
#define D3  PORTAbits.RA5
#define D4  PORTEbits.RE0
#define D5  PORTEbits.RE1
#define D6  PORTEbits.RE2
#define D7  PORTCbits.RC0


void systemInit(void);

/*
 *This function will enable the Clock.
 */
void clock(void)
{
    CLK_595 = 1;
    Delay100TCYx(1);
    CLK_595 = 0;
    Delay100TCYx(1);
}



/*
 * This function will send the data to shift register
 */
void dataSubmit(unsigned int data)
{
    int i;
    for (i=0 ; i<16 ; i++)
    {
        DATA_595 = (data >> i) & 0x01;
        clock();
    }
}

void sramLatch()
{
    WE = 0;         //The address bus is latched on the falling edge of WE# or CE#
    Delay10TCYx(4);  //wait for 40 ns
    WE = 1;         //The data bus is latched on the rising edge of WE# or CE#
    return;
}

void sramInitCmd()
{
    /*Commands are used to initiate the memory operation functions of the device. Commands are written
    to the device using standard microprocessor write sequences. A command is written by asserting WE#
    low while keeping CE# low. The address bus is latched on the falling edge of WE# or CE#, whichever
    occurs last. The data bus is latched on the rising edge of WE# or CE#, whichever occurs first.*/
    WE = 1;
    OE = 1;
    //CE = 0;
}

void sramRead()
{
    /*
     The Read operation of the SST39SF010A/020A/040 is controlled by CE# and OE#, both have to be
     low for the system to obtain data from the outputs. CE# is used for device selection. When CE# is high,
     the chip is deselected and only standby power is consumed. OE# is the output control and is used to
     gate data from the output pins. The data bus is in high impedance state when either CE# or OE# is
     high. Refer to the Read cycle timing diagram (Figure 5) for further details.
     */
    
    //CE = 0
    OE = 0;
  
}

void sramSecErase()
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
    
    
    
}

void sramLoadSeq()
{
    //Seq 1
        //Load data: AAH = 1010 1010b
    D7 = 1;
    D6 = 0;
    D5 = 1;
    D4 = 0;
    D3 = 1;
    D2 = 0;
    D1 = 1;
    D0 = 0;
    dataSubmit(0x5555);//Address: 5555H 
    sramLatch();
    
    //Seq 2
        //Load data: 55H =101 0101
    D7 = 0;
    D6 = 1;
    D5 = 0;
    D4 = 1;
    D3 = 0;
    D2 = 1;
    D1 = 0;
    D0 = 1;
    dataSubmit(0x2AAAA);//Address: 2AAAAH
    sramLatch();
      
    //Seq 3
        //Load data: A0H = 1010 0000
    D7 = 1;
    D6 = 0;
    D5 = 1;
    D4 = 0;
    D3 = 0;
    D2 = 0;
    D1 = 0;
    D0 = 0;
    dataSubmit(0x5555);//Address: 5555H
    sramLatch();
}

void sramByteProgramOp(int add, int data)
{
    /*
     * The SST39SF010A/020A/040 are programmed on a byte-by-byte basis. Before programming, the sector
        where the byte exists must be fully erased. The Program operation is accomplished in three steps.
        
     * The first step is the three-byte load sequence for Software Data Protection. 
     *
     * The second step is to load byte address and byte data. During the Byte-Program operation, the addresses are latched on the falling
        edge of either CE# or WE#, whichever occurs last. The data is latched on the rising edge of either
        CE# or WE#, whichever occurs first. 
     * 
     * The third step is the internal Program operation which is initiated
       after the rising edge of the fourth WE# or CE#, whichever occurs first. The Program operation, once
       initiated, will be completed, within 20 ?s.
     */
    
    sramLoadSeq();//Step 1
    //sramLoadData(add, data);//Step 2
    //sramWait();//Step 3
    
}

void main(void) 
{
    systemInit(); // System getting ready    
    Sleep();
}
    
/*
 This Function is for system initiation.
 */

void systemInit(void)
{
  TRISA = 0x00;   
}
