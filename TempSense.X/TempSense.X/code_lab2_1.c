/////////////////////////////////////////////////////////////////// 
//Student ID No.: 

///////////////////////////////////////////////////////////////////
#include "includes.h" 
#include <delays.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <p18f452.h> 
#include "xlcd_A.h"
#include "ow.h"
#include"Temp_DS1821.c"


/* Write the appropriate code to set configuration bits: * - set HS oscillator * - disable watchdog timer * - disable low voltage programming */
#pragma config OSC = HS
#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000

#define OW_LAT LATCbits.LATC7
#define OW_PIN PORTCbits.RC7
#define OW_TRIS TRISCbits.TRISC7

#define OUTPUT 0
#define INPUT 1

#define l1 0x00 //addresses of the beginning of line1
#define l2 0x44 //addresses of the beginning of line2
#define l3 0x10 //addresses of the beginning of line3
#define l4 0x50 //addresses of the beginning of line4

//char tempDisplay[3];



// Write LCD delay functions 
void DelayFor18TCY(void){
     Nop(); 
     Nop();
     Nop();
     Nop(); 
     Nop(); 
     Nop();
     Nop(); 
     Nop(); 
     Nop();
     Nop();
     Nop(); 
     Nop(); 
     Nop();
     Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}





int setup(void) {
  DelayPORXLCD();
  while (BusyXLCD());
  OpenXLCD(FOUR_BIT & LINES_5X7);
  DelayPORXLCD();
  while (BusyXLCD());
  SetDDRamAddr(0x40);

}

// configures the temperature sensor
/*
void tempConfig(void) {
 
  ow_reset(); //initialize the temp sensor
  ow_write_byte(0x0C); // master issues write to status command
  ow_write_byte(0x00); // writes to the status for continuous, one wire mode
  ow_reset(); //reset the device
  ow_write_byte(0xAC); // writes to the status for continuous, one wire mode
  ow_reset();

}

//measures the temperature value
float measureTemp(void)

{
  int loop = 0;
  float tempAvg = 0.0;
  int tempRead, tempTotal = 0;

  while (loop < 150) {
   
    ow_write_byte(0xEE); // begin temperature conversion
    ow_write_byte(0x22); //stop temperature                                                                                                                                                                                                                                                                                                                                                                     
    ow_reset(); //reset the device
    ow_write_byte(0xAA); //master issuses read temperature command
    tempRead = ow_read_byte(); // master reads temp value
    ow_reset();
    tempTotal = tempTotal + tempRead;
    loop++;

  }
  tempAvg = (float) tempTotal / 150;

  return tempAvg;
}


// reverses a string 'str' of length 'len' 
void reverse(char * str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

// Converts a given integer x to string str[].  d is the number 
// of digits required in output. If d is more than the number 
// of digits in x, then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) {
  int i = 0;
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }

  // If number of digits required is more, then 
  // add 0s at the beginning 
  while (i < d)
    str[i++] = '0';

  reverse(str, i);
  str[i] = '\0';
  return i;
}

// Converts a floating point number to string. 
void ftoa(float n, char * res, int afterpoint) {
  // Extract integer part 
  int ipart = (int) n;

  // Extract floating part 
  float fpart = n - (float) ipart;

  // convert integer part to string 
  int i = intToStr(ipart, res, 0);

  // check for display option after point 
  if (afterpoint != 0) {
    res[i] = '.'; // add dot 

    // Get the value of fraction part upto given no. 
    // of points after dot. The third parameter is needed 
    // to handle cases like 233.007 
    fpart = fpart * pow(10, afterpoint);

    intToStr((int) fpart, res + i + 1, afterpoint);
  }
}
*/


/* Write the appropriate code to do the following: * define the stack sizes for task1 and task2 in app_cfg.h file * use the defines to assign stack sizes here. */
OS_STK TaskAStk[100];
//OS_STK TaskBStk[100];


/* Write the appropriate code to do the following: 
 * Configure PORTB pin 1 as an output 
 * TaskA will loop until the global variable stopped is set. 
 * Within the loop -- print string "Task 1 rocks! \n" to LCD top row
 *  * -- toggle PORTB pin 1 * -- delay for 1 second using OSTimeDlyHMSM( ) 
 * TaskA will delete itself if the loop is exited. */ 
   void TaskA(void *pdata) {
   
    //TRISBbits.TRISB1 = 0;
        
    for(;;)
    {
    float tempRecord;
    
    char tempDisplay[3];
    
    tempConfig();
      
    tempRecord = measureTemp();

    ftoa(tempRecord, tempDisplay, 1);// converts the floating point temperature value to a string/character array

    /*
      while( BusyXLCD() );
      SetDDRamAddr( 0x10 );
      while(BusyXLCD());
      putrsXLCD(" Task 2 rules!");
      //PORTBbits.RB2 = 1;
      //OSTimeDly(200);     /* Delay task for 1 second 
      //PORTBbits.RB2 = 0;
      //OSTimeDly(200);
    */
    
    
    
    DelayPORXLCD();
    //while(BusyXLCD());
    //SetDDRamAddr(0x50);
    while (BusyXLCD());
    putsXLCD(tempDisplay);
    //WriteCmdXLCD(DOFF);
    while (BusyXLCD());
    SetDDRamAddr(0x40);
        
    /*  
      while( BusyXLCD() );
      SetDDRamAddr( 0x00 );
      while(BusyXLCD());
      putrsXLCD(" Task 1 rocks!");
      PORTBbits.RB1 = 0;
      OSTimeDlyHMSM (0,0,1,0);       /* Delay task for 1 second 
      PORTBbits.RB1 = 1;
      OSTimeDlyHMSM (0,0,1,0);
      
     
      
    }
    OSTaskDel(OS_PRIO_SELF);        //TaskA will delete itself if the loop is exited.
}

                                                                                                                                                                                                                                                                                                                                                 
/* Write the appropriate code to do the following: 
 * Configuee PORTB pin 2 as an output 
 * TaskB will loop until the global variable stopped is set. 
 * Within the loop -- print string "Task 2 rules?\n" to LCD bottom row 
 * -- toggle PORTB pin 2 * -- delay of 200 ticks using OSTimeDly( ) 
 * TaskB will delete itself if the loop is exited. */ 

/*
static void TaskB(void *pdata) {
    
    TRISBbits.TRISB2 = 0;
    
    for(;;)
    {
        
      
      
      while( BusyXLCD() );
      SetDDRamAddr( 0x40 );
      while(BusyXLCD());
      putrsXLCD(" Task 2 rules!");
      PORTBbits.RB2 = 1;
      OSTimeDly(200);     /* Delay task for 1 second 
      PORTBbits.RB2 = 0;
      OSTimeDly(200);
      
      
                
    }
    OSTaskDel(OS_PRIO_SELF);    //TaskB will delete itself if the loop is exited.
}
*/
void main(void) { 
    // Write the appropriate code to disable all interrupts 
    INTCONbits.GIE = 0;
    // Write the appropriate code to initialise uC/OS II kernel
    OSInit();
    /* Write the appropriate code to enable timer0 , 
     * using 16 bit mode on internal clk source and pre-scalar of 1. */
	// OpenTimer0( TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_EDGE_RISE & T0_PS_1_1 ); /* Write the appropriate code to enable timer0 , 

    /* Write the appropriate code to set timer0 registers 
     * such that timer0 expires at 10ms using 4 Mhz oscillator. 
     * Do the same in vectors.c in CPUlowInterruptHook( ). */
	// WriteTimer0(0xEC78);   
    /* Write the appropriate code to define the priorities for taskA 
     * and taskB in app_cfg.h. Use these defines to assign priorities 
     * when creating taskA and taskB with OSTaskCreate( ) */
    
    
    OSTaskCreate(TaskA,(void *)0,&TaskAStk[0],0);
    
    // OSTaskCreate(TaskB,
    //        (void *)0,&TaskBStk[0],
     //       1);
     
     

    
    // Initialise the LCD display 
    
    PORTD = 0x00;
    TRISD = 0x00;
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    

    
    // Write the appropriate code to start uC/OS II kernel
    OSStart();
}