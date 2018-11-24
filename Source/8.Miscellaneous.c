#include <p18cxxx.h>

/* Set configuration bits for use with PICKit3 */
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//1.The system has to estimate EITHER heart rate variability using pNN50 (as a %) OR a person’s oxygen saturation level (as a %)
//2. All sensors/system measurements should be calibrated and/or the error quanti?ed.

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