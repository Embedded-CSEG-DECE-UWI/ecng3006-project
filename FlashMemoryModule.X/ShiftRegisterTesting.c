#include <p18f452.h>
#include <delays.h>

/*Based on code from https://circuitdigest.com/microcontroller-projects/interfacing-74HC595-serial-shift-register-with-pic16f877a*/

/*
 * File:   main.c
 * Author: Sourav Gupta
 * By:- circuitdigest.com
 * Created on May 30, 2018, 2:26 PM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT0 = OFF
#pragma config CPB = OFF

/*
 Hardware related definition
 */

#define _XTAL_FREQ 20000000 //Crystal Frequency, used in delay
#define DATA_595 PORTCbits.RC0
#define STROBE_595 PORTCbits.RC1
#define CLK_595 PORTCbits.RC3

void system_init(void){
    TRISCbits.RC0 = 0;
    TRISCbits.RC1 = 0;
    TRISCbits.RC3 = 0;
    }

/*
 *This function will enable the Clock.
 */
void clock(void){
    CLK_595 = 1;
    Delay10TCYx(500);
    CLK_595 = 0;
    Delay10TCYx(500);
}

/*
 *This function will strobe and enable the output trigger.
 */

void strobe(void){
    STROBE_595 = 1;
    Delay10TCYx(500);
    STROBE_595 = 0;
    } 


void data_submit(unsigned int data){
    int i =0;    
    for (i =0; i<8; i=i+1)
    {
        DATA_595 = (data >> i) & 0x01;
        clock();
    }
    strobe(); // Data finally submitted 
}

void main()
{
     system_init(); // System getting ready    
    while(1){
        data_submit(0b00000000);
        Delay1KTCYx(200);
        data_submit(0b10000000);
        Delay1KTCYx(200);
        data_submit(0b01000000);
        Delay1KTCYx(200);
        data_submit(0b00100000);
        Delay1KTCYx(200);
        data_submit(0b00010000);
        Delay1KTCYx(200);
        data_submit(0b00001000);
        Delay1KTCYx(200);       
        data_submit(0b00000100);
        Delay1KTCYx(200);
        data_submit(0b00000010);
        Delay1KTCYx(200);
        data_submit(0b00000001);
        Delay1KTCYx(200);
        data_submit(0xFF);        
        Delay1KTCYx(200);
     }    
}