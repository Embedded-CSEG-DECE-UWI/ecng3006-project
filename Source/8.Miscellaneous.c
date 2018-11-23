#include <p18cxxx.h>
#include <reset.h> 
#include <delays.h>

#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF
//#pragma config WDTPS = 128


void main(void)
{
    TRISBbits.RB0 = 0xFF;
    TRISBbits.RB3 = 0x00;
    TRISBbits.RB4 = 0x00;
    PORTBbits.RB4 = 0;
    while(1){
    if(PORTBbits.RB0 == 1)
    {
        PORTBbits.RB3 = 1;
        Delay10KTCYx(5);      
        PORTBbits.RB3 = 0;
        Delay10KTCYx(5);
    }
    if(PORTBbits.RB0 == 0)
    {
        PORTBbits.RB4 = 1;
        Delay10KTCYx(5);      
        PORTBbits.RB4 = 0;
        Delay10KTCYx(5);
    }
    }
    Sleep();
}
