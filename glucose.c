#include <adc.h>
#include <p18f452.h>
#include "GblVar.h"

void glucose_measure(void){
    
    glucose = 0;
    
    OpenADC(    ADC_FOSC_8      &
                ADC_RIGHT_JUST  &
                ADC_1ANA_0REF   ,
                ADC_CH0         &
                ADC_INT_OFF     );
    
    ConvertADC();
    while( BusyADC() );
    
    glucose = ReadADC();
    
    CloseADC();
    glucose = glucose * 4.88;
    glucose = glucose + 40;
    
}

