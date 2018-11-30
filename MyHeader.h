/* 
 * File:   MyHeader.h
 * Author: aasif
 *
 * Created on November 12, 2018, 6:54 PM
 */

#ifndef MYHEADER_H
#define	MYHEADER_H

/*Function Prototypes*/
void pulseCounter_cfg(void);
void pulseCounter_ext2Int(void);
void pulseCounter_tmrInt (void);
void pulseCounter_ccpInt (void);

void keypad_cfg(void);
void keypad_read(void);

void tempSense_cfg(void);
void tempSense_measure(void);

void speaker_on(void);

void menu(void);
void clrScreen(void);

#endif	/* MYHEADER_H */


