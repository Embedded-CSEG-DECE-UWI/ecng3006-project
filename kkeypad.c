#include    <timers.h>
#include    <p18f452.h>
#include    <p18cxxx.h>
#include    "xlcd.h" 
#include    <stdlib.h>
#include    <adc.h>
#include    <delays.h>
#include    "portb.h"




#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
int i;
int discount=0 ;
volatile int Key;
volatile char Keygen[12];
volatile int Key100;


int ADCcon()
{
    TRISEbits.RE0 = 1;
    OpenADC (ADC_FOSC_2 & ADC_RIGHT_JUST & ADC_8ANA_0REF,ADC_CH5 & ADC_INT_ON);
    Delay10TCYx( 5 ); // Delay for 50TCY 
   ConvertADC(); // Start conversion
    while( BusyADC() ); // Wait for completion
     Key = ReadADC(); // Read result
     CloseADC(); // Disable A/D converter
     return Key;
    
}

void DelayFor18TCY( void )
{
/* Create a delay of 18 cycles */
    Delay10TCYx(1); 

Nop(); 

Nop(); 

Nop(); 

Nop(); 

Nop(); 

Nop(); 

Nop(); 

Nop(); 
}


void DelayPORXLCD (void)
{
/* Create a delay of 15 ms */
    Delay10KTCYx(1);
    Delay1KTCYx(5); 
}
void DelayXLCD (void)
{
/* Create a delay of 5 ms */
    Delay1KTCYx(5); 
}
int KeySel()
{
    if (Key100==10)
    {
        configuretmr0();
       discount++;
       return 0;
    }
    else if (Key100==7)
    {   
        i++;
        return i;
    }
    
     else if (Key100==6)
    {   
         i--;
         return i;
    }
///tasks needed scroll 
}

 

