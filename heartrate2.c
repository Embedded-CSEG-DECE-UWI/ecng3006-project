#include    <timers.h>
#include    <p18f452.h>
#include    <p18cxxx.h>
#include    "xlcd.h" 
#include    <stdlib.h>
#include    <adc.h>
#include    <delays.h>
#include    <capture.h>
#include    <portb.h>
#include    <string.h>
#include     <stdio.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF


int i=0; 
volatile int h60;
volatile char hdis[20];
volatile int tcount=0;
volatile int gcount=0;
unsigned int htime[20];
 int btime[20];
 int ctime[20];
 int c=0;
volatile int hrv1;
volatile int hcount=0;
volatile   char hrv2[4];
volatile   char hrv3[20];
volatile char hrate1[4];
volatile char hrate2[20];
int discount=0 ;
volatile int Key;
volatile char Keygen[12];
volatile int Key100;
extern char tempprint[20];
int acount;



void configuretmr0(void)
{
  OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
  WriteTimer0(0xE17B);
  PORTBbits.RB1=1;
}
void configuretmr1(void)
{OpenTimer1( TIMER_INT_ON &T1_16BIT_RW &T1_SOURCE_EXT &T1_PS_1_1 &T1_OSC1EN_OFF &T1_SYNC_EXT_OFF  );}

void start(void)
{
    int i=0;
    while (i<=20)
    {
        htime[i]=0; 
        i=i+1;
    }
    
    acount=0;
    gcount=0;
    hcount=0;
    discount=0;
 OpenXLCD(FOUR_BIT & LINES_5X7);
 while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "place finger to measure" );
 TRISCbits.RC2=1;
INTCONbits.GIE = 1;
configuretmr0();
 
TRISBbits.RB1=1;
   OpenRB1INT( PORTB_CHANGE_INT_ON );
   INTCONbits.GIE=1;

   
while(1){};

}

void test1(void)
{
    if (h60>200)
    {
        speakermain();
    }
    
    if (h60<60)
    {
        speakermain();
    }
    
    if (hrv1<60)
    {
        speakermain();
    }
}

void scroll (void)
{
    fulltemp();       //this calls the main temperature sensor code 
    if (i>=3){i=0;}
    OpenXLCD( FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putsXLCD(tempprint);//array temp[i]  //tempprint is the name of the char array that has the full tempearture value in newtrymain 
     while(BusyXLCD());
    
    
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD("glucose" );//array glucose[i]
       while(BusyXLCD());
    
 
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
     sprintf(hrate2,"heartrate=%d",h60)  ; 
    putsXLCD( hrate2 );//array heartrate [i]
     while(BusyXLCD());
    
     
    while(BusyXLCD());
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    sprintf(hrv3,"hrv=%d",hrv1)  ; 
    putsXLCD( hrv3 );
    i++;
    test1();
    }


void DelayFor18TCY( void )
{

 Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
   Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         


}

int  finddifference(int a,int b) 
{
    if(a>b)
    {
        c=a-b;
    }
    else
    {
        c=b-a;
    }
    
    return c ;
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

int KeySel()
{
    if (Key100>=9)
    {
        
        start();
       return 0;
    }
    else if (Key100==7)
    {   
       // i++;
        scroll();
        return i;
    }
    
     else if (Key100==6)
    {   
         //i--;
         scroll();
         return i;
    }
///tasks needed scroll 
}


int hrv(void)
{
     if (gcount>=1)
     {
         finddifference(htime[gcount-1],htime[gcount]) ;
    btime[gcount-1]=c;
     }
    else if (gcount>=2)
    {
    finddifference(btime[gcount-2],btime[gcount-1]);
    ctime[gcount-2]=c;
    if (ctime[gcount-2]>100)
    {hcount=hcount+1;}
     
    }
    
    return hcount;
    
}


//congifure cccp to trigger interrupt on every falling edge falling edge 
void heartbeatstart()
{
OpenCapture1(  CAPTURE_INT_ON & C1_EVERY_RISE_EDGE );
 configuretmr1();
 
}
int heartbeatstop(void)
{
    if (i>3)
    {i=0;}
    CloseCapture1();
    hrv1= hcount*100/gcount;
        
    itoa(hrv1,hrv2);
 
    return hrv1;
}





int hrate()
{
    if (i>3)
    {i=0;}
    h60= gcount*10;    
    scroll();
    
    return h60;
   
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
void high_ISR(void){
    INTCONbits.GIE = 0;
    
    
      if(INTCONbits.TMR0IF==1){
          tcount++;
      
          
        INTCONbits.TMR0IE=0;
        if (tcount==1)
        {heartbeatstart();
        configuretmr1();}
       
        OpenCapture1(  CAPTURE_INT_ON & C1_EVERY_RISE_EDGE );
        INTCONbits.TMR0IF=0;
         configuretmr0();
          OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD( "measuring" );
        if(tcount==4){
            tcount=0;
        INTCONbits.TMR0IE= 0;
        heartbeatstop(); 
        hrate();
    }
      }
  
    if (PIR1bits.TMR1IF==1)
    {
    PIR1bits.TMR1IF=0;
    }
    
    if (PIR1bits.CCP1IF==1)
    {
        
        htime[gcount]= ReadTimer0();
        gcount=gcount+1;
         PIR1bits.CCP1IF=0;  
        hrv();
    }
     
    
    
    if(INTCON3bits.INT1F==1)
    {
      ADCcon();
      Key100=Key/100;
       itoa (Key100, Keygen);
       KeySel(); 
       INTCON3bits.INT1F=0;
    }
  
    INTCONbits.GIE = 1;
    return;
}





void main (void)
{
    start();
}