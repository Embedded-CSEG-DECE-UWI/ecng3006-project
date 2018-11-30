/*
Code written by Bobby By, Agatha Lee, Dan Niecestro 02-2009
This code uses a PWM signal from PIC 18F4520 to define the frequencies 
that produce the basic notes in one octave of the musical scale, 
and plays a simple song on a piezo speaker.
The volume of the speaker can be set by changing the duty cycle value (1~125)
*/

//adapted from http://hades.mech.northwestern.edu/index.php/Driving_a_piezo_speaker_with_a_PIC

#include <p18f452.h>
#include <delays.h>
#include <pwm.h>
#include <timers.h>


#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming
#define _XTAL_FREQ 4000000UL


//define timer scaling value for each note
#define C 0x65 //prescaler of 4
#define D 0x5A
#define E 0x51
#define F 0x4C
#define G 0x44
#define A 0x3E
#define B 0x37
#define C2 0x33

#define Bf 0x85 //prescaler of 16

#define x 25 

//testing speaker
//Playing Jingle Bells
char song[x]={E, E, E, E, E, E, E, G, C, D, E, F, F, F, F, F, E, E, E, E, D, D, E, D, G}; //insert notes of song in array
int length[x]={1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2}; //relative length of each note
int i;

void main(void)

{
    TRISCbits.TRISC2 = 0;
    SetDCPWM1(5);
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_4 & T2_POST_1_1);
    while(1)
    {
     for (i=0; i<x; i++) {     //play x notes inside song array
      
      OpenPWM1(song[i]); 
                               //set PWM frequency according to entries in song array
      Delay1KTCYx(400* length[i]); //each note is played for 400ms*relative length

      OpenPWM1(1); 		//the PWM frequency set beyond audible range
                                //in order to create a short silence between notes
      Delay10KTCYx(25); 	//play nothing for 50 ms                  
      }
    }
    Sleep(); 
}