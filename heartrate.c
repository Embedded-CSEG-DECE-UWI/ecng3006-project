#include    <timers.h>
#include    <p18f452.h>
#include    <p18cxxx.h>
#include    "xlcd.h" 
#include    <stdlib.h>
#include    <adc.h>
#include    <delays.h>
#include    <capture.h>
#include    <portb.h>



#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

volatile int h60;
volatile char hdis[20];
volatile int tcount=0;
volatile int gcount=0;
unsigned int htime[15];
unsigned int btime;
volatile int hrv1=0;
volatile int hcount=0;
volatile char hrv2[4];
volatile char hrate1[4];
volatile int Key;
volatile char Keygen[12];
volatile int Key100;
int discount=0;
int i=0;






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

void scrollup (void)
{
    
    if (i>=3){i=0;}
    
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "line1" );//array temp[i]
    
    
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putsXLCD( Keygen );//array glucose[i]
    
    
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putsXLCD( hrate1[i] );//array heartrate [i]
    
   
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putsXLCD( hrv2[i] );//array hrv[i]
    
    
    }

void scrolldown (void)
{
   
    if(i<0){i=3;}

    OpenXLCD( FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "line1" );//array temp[i]

    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "line2" );//array glucose[i]
    
   
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "line3" );//array heartrate [i]
    
    
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "" );//array hrv[i]
    
    
    }



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

void configuretmr1(void)
{
OpenTimer1( TIMER_INT_ON &T1_16BIT_RW &T1_SOURCE_EXT &T1_PS_1_1 &T1_OSC1EN_OFF &T1_SYNC_EXT_OFF  );
}

//congifure cccp to trigger interrupt on every falling edge falling edge 
void heartbeatstart()
{
    OpenCapture1(  CAPTURE_INT_ON & CAP_EVERY_RISE_EDGE );
 configuretmr1();
}
int heartbeatstop(void)
{
   
    CloseCapture1();
   

}
// configure timer0 to count for two seconds 
void configuretmr0(void)
{
  OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
  WriteTimer0(0xE17B);
  PORTBbits.RB1=1;
}

// configure timer1 to count for six seconds 


int hrv(void)
{
    btime=htime[gcount-1]-htime[gcount];
    if (btime>15550)
    {hcount++;}
    hrv1= hcount*100/gcount; 
    
    
    return hrv1;
    
}

int hrate()
{
    h60= gcount*10;
    
    
    return h60;
   
}


void KeySel(void)
{
    if (Key100==10)
    {
       configuretmr0();
    
    }
    else if (Key100==7)
    {   //memory shift up 
        i++;
        scrollup();
    
    }
    
     else if (Key100==6)
    {   //memory shift down 
         i--;
         scrollup();
    }
}
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
    INTCONbits.GIE = 0;
    
    
      if(INTCONbits.TMR0IF==1){
          tcount++;
        while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "Measuring" );
         
        
    if(tcount==1);{
       heartbeatstart();  }
     
    
    INTCONbits.TMR0IF=0;    
    configuretmr0();
          
          if(tcount==4)
                        {
        INTCONbits.TMR0IE= 0;
        heartbeatstop(); 
       hrate();
       scrollup();
       
                        }
    
      }
    
    if (PIR1bits.CCP1IF==1)
    {
       htime[gcount]= ReadTimer1();
        gcount++;
        hrv();
        PIR1bits.CCP1IF=0;
    }
    
      if(INTCON3bits.INT1F==1){
          ADCcon();
      Key100=Key/100;
       itoa (Key100, Keygen);
       KeySel(); 
       INTCON3bits.INT1F=0;
  
    INTCONbits.GIE = 1;
     return;
                            }
}

void smain(void)
{

    OpenXLCD( FOUR_BIT & LINES_5X7);

    TRISCbits.RC2=1;
configuretmr0();
   TRISBbits.RB1=1;
   OpenRB1INT( PORTB_CHANGE_INT_ON );
   INTCONbits.GIE = 1;
//if (discount<=3)
   // {discount=0;}
    itoa(hrv1,hrv2[discount]);
    itoa(h60,hrate1[discount]);
  //  discount++ ;
    
    while(1){};

}
    void main (void)

{
    smain();
}
