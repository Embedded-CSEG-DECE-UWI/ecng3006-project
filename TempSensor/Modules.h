<<<<<<< HEAD
/* 
 * File:   Modules.h
 * Author: 815008434
 *
 * Created on November 11, 2019, 7:01 PM
 */

#ifndef MODULES_H
#define	MODULES_H

#include    <p18f452.h>
#include    <delays.h>
#include    "FreeRTOS.h"
#include    <semphr.h>
#include    <queue.h>

#define USEC18DELAY 0
#define USEFREERTOSQUEUE 1

/*****GLOBAL SEMAPHORE/QUEUE VARIABLES*****/

extern QueueHandle_t xlcdQueue;

/**********TEMPERATURE SENSOR MODULE**********/

#define OW_LAT LATBbits.LATB4
#define OW_PIN PORTBbits.RB4
#define OW_TRIS TRISBbits.TRISB4

#define OUTPUT 0
#define INPUT 1

unsigned char ow_reset(void);

void ow_write_byte(unsigned char data);

char ow_read_byte(void);

void tempTask (void *pvParameter);

/********LCD MODULE*********/

void lcdTask (void *pvParameter);

struct lcdMessage{
    unsigned char srcID;
    unsigned char srcMessage[16];
};

#endif	/* MODULES_H */

=======
/* 
 * File:   Modules.h
 * Author: 815008434
 *
 * Created on November 11, 2019, 7:01 PM
 */

#ifndef MODULES_H
#define	MODULES_H

#include    <p18f452.h>
#include    <delays.h>
#include    "FreeRTOS.h"
#include    <semphr.h>
#include    <queue.h>

#define USEC18DELAY 0
#define USEFREERTOSQUEUE 1

/*****GLOBAL SEMAPHORE/QUEUE VARIABLES*****/

extern QueueHandle_t xlcdQueue;

/**********TEMPERATURE SENSOR MODULE**********/

#define OW_LAT LATBbits.LATB4
#define OW_PIN PORTBbits.RB4
#define OW_TRIS TRISBbits.TRISB4

#define OUTPUT 0
#define INPUT 1

unsigned char ow_reset(void);

void ow_write_byte(unsigned char data);

char ow_read_byte(void);

void tempTask (void *pvParameter);

/********LCD MODULE*********/

void lcdTask (void *pvParameter);

struct lcdMessage{
    unsigned char srcID;
    unsigned char srcMessage[16];
};

#endif	/* MODULES_H */

>>>>>>> b587c5aa9c9fcf01a242fc30d0430e5349df2f53
