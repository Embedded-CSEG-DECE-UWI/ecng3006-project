#include <p18f452.h>
#include <delays.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "xlcd.h"

#include "Temperature_Header.h"
#include "HR_Header.h"
#include "HRV_Header.h"
#include "Speaker_Header.h"
#include "Scroll_Header.h"

#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000UL

int welcome_cnt = 0;

// --------------------- LCD delays ----------------------
 void DelayFor18TCY(void)
 {
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void)
{
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void)
{
    Delay1KTCYx(15);
    return;
}
// --------------------------------------------------------


// ----------------- Functions ----------------------------
void heartbeat_system(void)
{
    TRISBbits.TRISB4 = 0;
    
    PORTBbits.RB4 = 0;
    Delay10KTCYx(10);
    
    PORTBbits.RB4 = 1;
    Delay10KTCYx(10);
    
    return;
}

void Refresh_LCD(void)
{
    while(BusyXLCD());
    
    SetDDRamAddr(0x00); // line 1
    putrsXLCD("                ");
    SetDDRamAddr(0x40); // line 2
    putrsXLCD("                ");
    SetDDRamAddr(0x10); // line 3
    putrsXLCD("                ");
    
    SetDDRamAddr(0x00); // line 1
    putrsXLCD("BPM Key 1");
        
    SetDDRamAddr(0x40); // line 2
    putrsXLCD("HRV Key 4");
        
    SetDDRamAddr(0x10); // line 3
    putrsXLCD("TMP Key 7");
    
     while(BusyXLCD());
}


// --------------------------------------------------------

void init_LCD(void)
{ 
    TRISD = 0x00;
    PORTD = 0x00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
 }



void Key_Check(void)
{
    int encoder;    
    char key[20];
    char display[20];
    
    // Read encoder
    encoder = 0;
    encoder = encoder | PORTCbits.RC7;
    encoder = encoder << 1;
    encoder = encoder | PORTCbits.RC6;
    encoder = encoder << 1;
    encoder = encoder | PORTCbits.RC5;
    encoder = encoder << 1;
    encoder = encoder | PORTCbits.RC4;
    
    // Switch case 
    switch (encoder)
    {
        case 0x00:
          sprintf(key,"1");     // ------------ HR --------------------
          HR_Task();
          break;
          
        case 0x01:
          sprintf(key,"4");
          HRV_Task();           // -------------- HRV -----------------
          break;
          
        case 0x03:
          sprintf(key,"7");     // ----------- Temperature ------------
          Temperature_Task();
          break;
          
        case 0x02:
          sprintf(key,"0");
          break;
          
        case 0x04:
          sprintf(key,"2");
          break;
          
        case 0x05:
          sprintf(key,"5");
          break;
          
        case 0x07:
          sprintf(key,"8");
          break;
          
        case 0x06:
          sprintf(key,"F");
          break;
          
        case 0x08:
          sprintf(key,"3");
          break;
          
        case 0x09:
          sprintf(key,"6");
          break;
          
        case 0x0B:
          sprintf(key,"9");
          break;
          
        case 0x0A:
          sprintf(key,"E");
          break;
          
        case 0x0C:
          sprintf(key,"A");     // ------------- Scroll -----------------
          display_scroll();
          inc_scroller();
          break;
          
        case 0x0D:
          sprintf(key,"B");     // ------------- Refresh LCD ------------
          Refresh_LCD();
          break;
          
        case 0x0F:
          sprintf(key,"C");     // -------------- Speaker on ------------
          Speaker_On_Task();
          break;
          
        case 0x0E:
          sprintf(key,"D");     // -------------- Speaker off ------------
          Speaker_Off_Task();
          break;
          
    }
        // Display 
        while(BusyXLCD());
        SetDDRamAddr(0x50);
        putrsXLCD("                ");
        
        while(BusyXLCD());
        SetDDRamAddr(0x50);
        sprintf(display,"Key: %s",key);
        putsXLCD(display);   
 } 

    
 
// -------------------------------- INTERRUPT ----------------------------------
void high_ISR(void);
 
#pragma code high_vector = 0x08
 void high_interrupt_vector(void){
     _asm 
     GOTO high_ISR
     _endasm
 }
#pragma code 
 
#pragma interrupt high_ISR
void high_ISR(void)
{
    // Disable global interrupts
    INTCONbits.GIE = 0;
    
    // --------- Keypad interrupt -----------------
    if(INTCONbits.INT0F==1)
    {
     Key_Check();
     INTCONbits.INT0E = 0;
     INTCONbits.INT0F = 0; 
    }
    // --------------------------------------------
    
    // ------------- HR interrupt -----------------
    if(INTCON3bits.INT1IF==1)
    {
        INTCON3bits.INT1IE = 0;
        countHBs();
        INTCON3bits.INT1IF = 0;
        INTCON3bits.INT1IE = 1;
    }
    
    if(INTCONbits.TMR0IF==1)
    {
        INTCONbits.TMR0IE= 0;
        stopHBs();
        INTCONbits.TMR0IF==0;
    }
    // ---------------------------------------------
    
    // ------------- HRV interrupt -----------------
     if(PIR1bits.TMR1IF==1)
    {
        PIR1bits.TMR1IF=0;
        overflow_inc();
    } 
    
    if(PIR2bits.CCP2IF==1)
    {  
        PIR2bits.CCP2IF = 0;  
        hrvMain();
    }   
    // ---------------------------------------------

    // Re-enable interrupts
    INTCONbits.INT0E = 1;
    INTCONbits.GIE = 1;
    
    return;
}
// -----------------------------------------------------------------------------
 

 void main()
 {
     //Enable INTCON global interrupt bit
     INTCONbits.GIE = 1;    
     
   //Set inputs
    TRISCbits.RC7=1;      
    TRISCbits.RC6=1;
    TRISCbits.RC5=1;
    TRISCbits.RC4=1; 
    
    // -------- Keypad interrupts initialize ---------------
    INTCONbits.INT0IE = 1;      //Enable INT0 
    INTCON2bits.INTEDG0 = 0;    //Falling Edge
    
    // -------- HRinterrupts initialize ---------------
    //RCONbits.IPEN = 1;              //Enable Priority Levels
    INTCON2bits.INTEDG1 = 0;        //bit 5	INTEDG1: External Interrupt1 Edge Select bit, Interrupt on falling edge  
    //INTCON3bits.INT1IP = 1;         //bit 6	INT1IP: INT1 External Interrupt Priority bit  
    INTCON3bits.INT1IE = 0;         //bit 3	INT1IE: INT1 External Interrupt Enable bit 
    
    // -------- HRVinterrupts initialize ---------------
    RCONbits.IPEN =   1;             //Enable Priority Levels
    PIR2bits.CCP2IF = 0;             //CCP Interrupt Flag
    IPR2bits.CCP2IP = 1;             //CCPIP Interrupt High Priority 
    IPR1bits.TMR1IP = 1;             //Timer1 Interrupt ; High Priority 
    PIE1bits.TMR1IE = 1;             //Timer1 Interrupt Enable
    PIR1bits.TMR1IF=0;               //Timer1 Interrupt Flag initial cleared.
    INTCONbits.GIEH= 1;              //Enable Interrupt
    TRISDbits.RD3 = 0;               //Set RB7 as Output
    PORTDbits.RD3 = 0;               //Set RB7 LOW     
    TRISCbits.RC1 = 1;               //Set RC1 as Input
    
    init_LCD();
    
    // ----------- Welcome splash ------------
    
    if(welcome_cnt == 0)
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00); // line 1
    putrsXLCD("Group B");
        
    SetDDRamAddr(0x40); // line 2
    putrsXLCD("uP Project");
        
    SetDDRamAddr(0x10); // line 3
    putrsXLCD("Key B: Menu");
        
    SetDDRamAddr(0x50); // line 4
    putrsXLCD(":)");
    while(BusyXLCD());
    
    welcome_cnt++;
    }
    else
    {
     
    }
    
    
    // ----------------------------------------

     while(1)
     {
         
        heartbeat_system();
        
     }
    
 }

