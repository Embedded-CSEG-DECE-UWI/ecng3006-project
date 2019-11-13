#include    <p18f452.h>
#include    <stdio.h>
#include    "Modules.h"
#include    "xlcd_GpE.h"


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

unsigned char TempMSB;              //Are all these variables for the main function ?
unsigned char TempLSB;
unsigned int MSBTemporary = 0;
unsigned int LSBTemporary = 0;
unsigned int TempInt = 0;
unsigned char degree = 0xDF;
unsigned char demi;
unsigned char fract;

float fracFloat = 0.0000;
int sign = 0;
int fracInt = 0;
int x = 0;
char Temperature[20];

//Global Variable
int key;


//Setting up interrupts High Interrupt
#pragma code HIGH_INTERRUPT_VECTOR = 0x08

void high_ISR(void) {
    if (INTCONbits.TMR0IF == 1)
    {
    _asm
            goto timer10sIsr
    _endasm
    }
    if (INTCONbits.INT0IF == 1)
    {
        _asm
        goto bpmCountIsr
        _endasm
    }
}
#pragma interrupt timer10sIsr
#pragma interrupt bpmCountIsr
#pragma code

//Setting up Low Interrupts
#pragma code LOW_INTERRUPT_VECTOR = 0x18

void low_ISR(void)

{
    if (INTCON3bits.INT2IF == 1)
    _asm
            goto KeyPressInterrupt
    _endasm
    
}

#pragma interrupt KeyPressInterrupt
#pragma code

void KeyPressInterrupt(void) 
{
        key = (BIT0 * 1 + BIT1 * 2 + BIT2 * 4 + BIT3 * 8);
        switch (key) {
            case (0):
                heartRateModule();
                break;
            case (1):
                TestBeep();
                break;
            case (2):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("3");
                while (BusyXLCD());
                break;
            case (3):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("A");
                while (BusyXLCD());
                break;
            case (4):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("4");
                while (BusyXLCD());
                break;
            case (5):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("5");
                while (BusyXLCD());
                break;
            case (6):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("6");
                while (BusyXLCD());
                break;
            case (7):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("B");
                while (BusyXLCD());
                break;
            case (8):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("7");
                while (BusyXLCD());
                break;
            case (9):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("8");
                while (BusyXLCD());
                break;
            case (10):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("9");
                while (BusyXLCD());
                break;
            case (11):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("C");
                while (BusyXLCD());
                break;
            case (12):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("0");
                while (BusyXLCD());
                break;
            case (13):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("F");
                while (BusyXLCD());
                break;
            case (14):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("E");
                while (BusyXLCD());
                break;
            case (15):
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("D");
                while (BusyXLCD());
                break;
            default:
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("An Error!");
                while (BusyXLCD());
                break;
        }

       
        INTCONbits.INT0IF = 0;   //Clear the external interrupt flag.
        return;
}

void main(void) {
    configKeypad();
    InitLCD();
    initSpeakerModule();
    while (1) {
        
        // We should state a condition in which this can occur
        
        OW_reset_pulse(); //reset 1822P
        OW_write_byte(0x0C); // Skip ROM Check
        
        OW_reset_pulse(); //reset 1822P
        OW_write_byte(0x45); // Skip ROM Check
        
        OW_reset_pulse(); //reset 1822P
        OW_write_byte(0xEE); //
        
        Delay10KTCYx(80);
        
        OW_reset_pulse(); //reset device
        OW_write_byte(0xAA); //skip ROM check
        TempLSB = OW_read_byte(); //Read first byte, LS and store in TempLSB

        while (BusyXLCD());
        SetDDRamAddr(0x50); //Set cursor to top line
        while (BusyXLCD());
        putsXLCD(TempLSB); //Write top line value
    }
}