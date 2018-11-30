#include "GblVar.h"
#include <portb.h>
#include <p18f452.h>

void keypad_cfg (void)
{
    //set port pins that are used
    //pins used RB1, D  - RC4, C - RC5, B - RC6, A - RC7
    TRISCbits.RC7 = 1;      //Output A from the encoder
    TRISCbits.RC6 = 1;      //Output B from the encoder
    TRISCbits.RC5 = 1;      //Output C from the encoder
    TRISCbits.RC4 = 1;      //Output D from the encoder
   
    TRISBbits.RB1= 1;       //Set INT 1 pin as input 
   
    INTCON3bits.INT1IE = 1; //enable the INT1 external interrupt 
    INTCON3bits.INT1IF = 0; //clear external interrupt INT1 flag
	INTCON2bits.INTEDG1= 1; //set interrupt INT1 on rising edge

    INTCON3bits.INT1IP = 1; //Set INT1 Priority bit to high priority  
    
    return;
}

void keypad_read (void)
{
/* -------------------------------KEYPAD KEYS---------------------------------*/
/*---The if statements are to determine the key pressed. The conditions are---*/
/*--------in the form of D output, C output B output and A output.------------*/

    //KEY "F"
    if ((PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = 'F';
        
    }
    
    //KEY "1"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        keyval[0] = '1';
    }
    
    //KEY "A"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = 'A';
    }
    
    //KEY "2"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = '2';
    }
    
    //KEY "3"
    else if(!(PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        keyval[0] = '3';
    }
    
    //KEY "4"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval[0] = '4';
    }
    
    //KEY "B"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = 'B';
    }
    
    //KEY "6"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval[0] = '6';
    }
    
    //KEY "5"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = '5';
    }
    
    //KEY "7"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval[0] = '7';
    }
    
    //KEY "C"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = 'C';
    }
    
    //KEY "9"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval[0] = '9';
    }
    
    //KEY "8"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = '8';
    }
    
    //KEY "0"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval[0] = '0';
    }
    
    //KEY "D"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval[0] = 'D';
    }
    
    //KEY "E"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval[0] = 'E';
    }
    
}

/* Place the following code in the low isr
 * 
 * 
 * 
     if(INTCON3bits.INT1IF){
        INTCONbits.GIEH =0;
        keyPad();
        INTCON3bits.INT1IF = 0; //clears the external interrupt flag
        INTCONbits.GIEH =1;
        INTCON3bits.INT1IE = 1;
    }
 * 
 * 
 * 
 */
