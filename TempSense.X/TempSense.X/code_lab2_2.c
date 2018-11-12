/////////////////////////////////////////////////////////////////// 
//Student ID No.: 

///////////////////////////////////////////////////////////////////
#include "includes.h" 
#include "xlcd_A.h"
#include <timers.h> 
#include <delays.h>
#include <stdlib.h>
#include <string.h>
#include <p18f452.h>


/* Write the appropriate code to set configuration bits: * - set HS oscillator * - disable watchdog timer * - disable low voltage programming */
#pragma config OSC = HS
#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000

INT8U *err;
OS_EVENT *LCDSem;

/* Write LCD delay functions */
void DelayFor18TCY(void){
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
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


/* Write the appropriate code to do the following: * define the stack sizes for task1 and task2 in app_cfg.h file * use the defines to assign stack sizes here. */
OS_STK TaskAStk[TaskA_size];
OS_STK TaskBStk[TaskB_size];


/* Write the appropriate code to do the following: 
 * Configure PORTB pin 1 as an output 
 * TaskA will loop until the global variable stopped is set. 
 * Within the loop -- print string "Task 1 rocks! \n" to LCD top row
 *  * -- toggle PORTB pin 1 * -- delay for 1 second using OSTimeDlyHMSM( ) 
 * TaskA will delete itself if the loop is exited. */ 
static void TaskA(void *pdata) {
   
    TRISBbits.TRISB1 = 0;
        
    for(;;){
      
      OSSemPend(LCDSem, 0, err);
      
      while( BusyXLCD() );
      SetDDRamAddr( 0x00 );
      while(BusyXLCD());
      putrsXLCD(" Task 1 rocks!");
      PORTBbits.RB1 = 0;
      OSTimeDlyHMSM (0,0,1,0);       /* Delay task for 1 second */
      PORTBbits.RB1 = 1;
      OSTimeDlyHMSM (0,0,1,0);
      
      OSSemPost(LCDSem);
    }
    OSTaskDel(OS_PRIO_SELF);        //TaskA will delete itself if the loop is exited.
}

                                                                                                                                                                                                                                                                                                                                                 
/* Write the appropriate code to do the following: 
 * Configuee PORTB pin 2 as an output 
 * TaskB will loop until the global variable stopped is set. 
 * Within the loop -- print string "Task 2 rules?\n" to LCD bottom row 
 * -- toggle PORTB pin 2 * -- delay of 200 ticks using OSTimeDly( ) 
 * TaskB will delete itself if the loop is exited. */ 
static void TaskB(void *pdata) {
    
    TRISBbits.TRISB2 = 0;
    
    for(;;){
        
      OSSemPend(LCDSem, 0, err);
      
      while( BusyXLCD() );
      SetDDRamAddr( 0x10 );
      while(BusyXLCD());
      putrsXLCD(" Task 2 rules!");
      PORTBbits.RB2 = 1;
      OSTimeDly(200);     /* Delay task for 1 second */
      PORTBbits.RB2 = 0;
      OSTimeDly(200);
      
      OSSemPost(LCDSem);                
    }
    OSTaskDel(OS_PRIO_SELF);    //TaskB will delete itself if the loop is exited.
}

void main(void) { 
    // Write the appropriate code to disable all interrupts 
    INTCONbits.GIE = 0;
    // Write the appropriate code to initialise uC/OS II kernel
    OSInit();
    /* Write the appropriate code to enable timer0 , 
     * using 16 bit mode on internal clk source and pre-scalar of 1. */
	 OpenTimer0( TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_EDGE_RISE & T0_PS_1_1 ); /* Write the appropriate code to enable timer0 , 

    /* Write the appropriate code to set timer0 registers 
     * such that timer0 expires at 10ms using 4 Mhz oscillator. 
     * Do the same in vectors.c in CPUlowInterruptHook( ). */
	 WriteTimer0(0xEC78);   
    /* Write the appropriate code to define the priorities for taskA 
     * and taskB in app_cfg.h. Use these defines to assign priorities 
     * when creating taskA and taskB with OSTaskCreate( ) */
    
    
    OSTaskCreate(TaskA,
            (void *)0,&TaskAStk[0],
            0);
    
     OSTaskCreate(TaskB,
            (void *)0,&TaskBStk[0],
            1);
     
    LCDSem = OSSemCreate(1); 
    
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