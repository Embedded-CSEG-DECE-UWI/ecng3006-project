#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include "ow.h"
#include "GblVar.h"

#define OW_LAT LATBbits.LATB5
#define OW_PIN PORTBbits.RB5
#define OW_TRIS TRISBbits.TRISB5



void tempSense_cfg(void) {
 
  ow_reset(); 
  ow_write_byte(0x0C); 
  ow_write_byte(0x00);
  ow_reset(); 
  ow_write_byte(0xAC); 
  ow_reset();
}

void tempSense_measure(void)
{
    int tempVal = 0;
    int tempSum = 0;
    float tempAvg = 0.0;
    int count = 0;
    while( count < 200){
	ow_write_byte(0xEE); 
    	ow_write_byte(0x22);                                                                                                                                                                                                                                                                                                                                                                      
    	ow_reset(); 
    	ow_write_byte(0xAA); 
	tempVal = ow_read_byte();
    	ow_reset();
    	tempSum = tempSum + tempVal;
        count++;
    }
     tempAvg = (float) tempSum / 200;
     temperature = tempAvg;
     return;
} 


