#include <p18cxxx.h>
#include <adc.h> 
#include <delays.h>

#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

int result;
int conversionV;
int conversionG;

void main(void)
{
    while(1){
 OpenADC( ADC_FOSC_RC & ADC_RIGHT_JUST & ADC_1ANA_0REF, ADC_CH0 & ADC_INT_OFF ); // configure A/D convertor
 Delay10TCYx(1); // Delay for 50TCY
 ConvertADC(); // Start conversion
 while( BusyADC() ); // Wait for completion
 result = ReadADC(); // Read result
 conversionV = 0.0056*result; //TEMPORARY VALUE FOR VOLTAGE IN V
 conversionG = 21.6*conversionV; //TEMPORARY VALUE FOR GLUCOSE IN mg/dL
 CloseADC(); // Disable A/D converter
 //Delay10TCYx(1); 
    }
    Sleep();
}
