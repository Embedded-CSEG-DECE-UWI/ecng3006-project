#include <p18f452.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "ow.h"
#include <xlcd.h>

void Temperature(){
    unsigned char MSB;
    unsigned char LSB;
    unsigned char TLow;
    unsigned char vDisp[9];
    unsigned char DP;
    unsigned int MSBTemp = 0;
    unsigned int LSBTemp=0;
    unsigned int TempInt = 0;
    unsigned char degree = 0xDF;
    float fracFloat = 0.0000;
    int sign = 0;
    int fracInt =0;
    int x = 0;
    char Temperature[20];
    
    TRISBbits.RB3=0; //set RC7 as output to transistor
    
        ow_reset();  
        ow_write_byte(0xCC); // Skip ROM Check
        ow_write_byte(0x44); //Temperature conversion 
        PORTBbits.RB3 = 1;  //Strong pullup 
        
         for(x = 1; x<=8;x++){ //800ms 
           Delay1KTCYx(100);
        }
        
        PORTBbits.RB3 = 0; //Turn off strong pullup
        
        ow_reset(); 
        ow_write_byte(0xCC); 
        ow_write_byte(0xBE); //read scratchpad
        LSB = ow_read_byte(); 
        MSB = ow_read_byte(); 
     
        
        
        
        LSBTemp = LSB >> 4; 
        MSBTemp = MSB << 4;
        TempInt = MSBTemp| LSBTemp;
        
        //Acquire Fraction
        if(LSB & 0x01){fracFloat += 0.0625;}
        if(LSB & 0x02){fracFloat += 0.125;}
        if(LSB & 0x04){fracFloat += 0.25;}
        if(LSB & 0x08){fracFloat += 0.5;}
        fracInt =fracFloat*1000;

        //Sign check
        sign = ((MSB >> 3 )& 0x3F);
        if(sign == 0){
            sprintf(Temperature,"+%d.%03d%cC",TempInt,fracInt,degree);
            
            TempInt = 0;
            fracInt= 0;
            fracFloat =0.0;
        }
        else{
            sprintf(Temperature,"-%d.%03d%cC",TempInt,fracInt);
            TempInt = 0;
            fracInt= 0;
            fracFloat =0.0;

        }
        
        while(BusyXLCD());
        SetDDRamAddr(0x10); //Set cursor to top line
        while(BusyXLCD());
        Delay1KTCYx(110); //LCD delay
        while(BusyXLCD());
        putrsXLCD( "Temp = " );
        while( BusyXLCD() );
        putsXLCD(Temperature);
        sprintf(Temperature,"                   ");
}
