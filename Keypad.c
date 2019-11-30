#include<p18f452.h>
#include"xlcd.h"
#include<delays.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


char value_out;

void low_isr(void);
void keypad_isr(void);



void start_up(void)
{
    //------------------CONFIGURE INTERRUPT
    INTCON2bits.INTEDG1=1;
    INTCON3bits.INT1E=1;
    INTCON3bits.INT1F=0;
    INTCONbits.GIE=1;
    //------------------Configure Ports
    TRISBbits.RB1=1;
    TRISCbits.RC4=1;
    TRISCbits.RC5=1;
    TRISCbits.RC6=1;
    TRISCbits.RC7=1;;

     
}

void keypress(void)
{
    
    int value =0;      // Initialise variable
    
    // Store values from the pins RC4,RC5,RC6,RC7 
    value = value | PORTCbits.RC7;
    value = value << 1;
    value = value | PORTCbits.RC6;
    value = value << 1;
    value = value | PORTCbits.RC5;
    value = value << 1;
    value = value | PORTCbits.RC4;
     

               // Create switch cases                         
              switch(value)
                 {
                     case 0:                
                         value_out='1';  
                     break;     
                     case 1:               
                         value_out='4';  
                     break;
                     case 2:               
                         value_out='7';  
                     break;
                     case 3:               
                         value_out='*';  
                     break;
                     case 4:               
                         value_out='2';  
                     break;
                     case 5:               
                         value_out='5';  
                     break;
                     case 6:              
                         value_out='8';  
                     break;
                     case 7:              
                         value_out='0';  
                     break;
                     case 8:              
                         value_out='3';  
                     break;   
                     case 9:              
                         value_out='6';  
                     break;
                     case 10:              
                         value_out='9';  
                     break;
                     case 11:              
                         value_out='#';  
                     break;
                    case 12:             
                         value_out='A';  
                     break;
                     case 13:              
                         value_out='B';  
                     break;
                     case 14:              
                         value_out='C';  
                     break;
                     case 15:               
                         value_out='D';
                     break;
              }

         if (value_out == '1')       
                {
                    System_Init();      // Initialise system to start calculating parameters
                    Config_LCD();       // Clear LCD
                    while( BusyXLCD() ); 
                    SetDDRamAddr( 0x00 );    // Write to line 1
    
                   while( BusyXLCD() );
                   putrsXLCD( "CALCULATING..." );  // Display on LCD
        
                }
              else
                {   
                  Config_LCD();         // Clear LCD
                  while( BusyXLCD() );
                  SetDDRamAddr( 0x00 );   // Write to line 1
    
                   while( BusyXLCD() );
                   putrsXLCD( "Invalid key" );    // Display to LCD
                   Delay10KTCYx(10000);           
                   
                }
    
                
}

