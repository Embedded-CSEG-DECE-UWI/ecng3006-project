/* 
 * File:   GblVar.h
 * Author: aasif
 *
 * Created on November 12, 2018, 7:29 PM
 */

#ifndef GBLVAR_H
#define	GBLVAR_H

#ifndef LCD_line_0
#define LCD_line_0 ((const unsigned char *) 0x00)
#endif

#ifndef LCD_line_1
#define LCD_line_1 ((const unsigned char *) 0x40)
#endif

#ifndef LCD_line_2
#define LCD_line_2 ((const unsigned char *) 0x14)
#endif

#ifndef LCD_line_3
#define LCD_line_3 ((const unsigned char *) 0x54)
#endif

/*Global Variables*/
extern unsigned int pulseCount;
extern int pulseTimerCounter;
extern int pnnCount;
extern char bpm [20];
extern char pNN [20];
extern unsigned int interval1;
extern unsigned int interval2;
extern unsigned int time1;
extern unsigned int time2;
extern unsigned int time3;
extern int tsk;
extern int wait;
extern char keyval[1];
extern float temperature;
extern int storeInterval;
extern int glucose;


#endif	/* GBLVAR_H */


