#include    <p18f452.h>
#include    <stdio.h>
#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <delays.h>


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

//Global Variable
int key;

//Setting up interrupts High Interrupt
#pragma code high_vector = 0x08
void high_interrupt(void) 
{
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
    
    if (INTCON3bits.INT2IF == 1)
    {
    _asm
            goto KeyPressInterrupt
    _endasm
    }
}

#pragma code

//Setting up Low Interrupts
/*
#pragma code low_vector = 0x18
void low_interrupt (void)
{
    _asm
            goto KeyPressInterrupt
    _endasm
}
#pragma code*/

#pragma interrupt KeyPressInterrupt
void KeyPressInterrupt(void) 
{
        key = (BIT0 * 1 + BIT1 * 2 + BIT2 * 4 + BIT3 * 8);
        switch (key) {
            case (0):
                heartRateModule();
                break;
            case (1):
                //TestBeep();
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
    InitLCD();
    TRISBbits.RB4 = 0;
    PORTBbits.RB4 = 0;
    configKeypad();         //This Function also enables all interrupts


    while (1)
    {
        
    }

}