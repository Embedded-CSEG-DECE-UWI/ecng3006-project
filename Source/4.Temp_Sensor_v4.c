#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include "ow.h"
#include "xlcd.h"

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

// The system has to measure the ambient temperature (in degrees Centigrade to +/- 0.1 degree Centigrade) at which a reading is taken.

unsigned char temp_read_LSB;// = 10;
unsigned char temp_read_MSB;// = 65000;
unsigned char temp_degree = 0xDF;

unsigned int temp_LSB = 0;
unsigned int temp_MSB = 0;
unsigned int temp_integer = 0;
unsigned int temp_fraction = 0;
unsigned int temp_sign = 0;

unsigned int temp_hundreds = 0;
unsigned int temp_tens = 0;
unsigned int temp_ones = 0;

int counter = 0;

float temp_float = 0.0;

int average_integer = 0;
int average_fraction = 0;
int sum_integer = 0;
int sum_fraction = 0;
int running_average_integer = 0;
int running_average_fraction = 0;

int temp_sum_fraction = 0;
float decimal_division_initial_value = 0.0;
float integer_division_initial_value = 0.0;

float decimal_division_final_value = 0.0;
int decimal_division_final_value_integer = 0;

int integer_variable_extraction = 0;
float integer_division_value_to_add = 0.0;

float average_fraction_float = 0;

int counter2 = 5;
int test = 0;

char lcdVariable[20];                               //array that will contain the pulse count to display on the LCD

void configTemp (void);
void readTemp (void);
void obtainInteger (void);
void obtainFraction (void);
int approximation (int);
void obtainSign (void); 
void resetTempConversion (void);
void runningAverage (void);

void errorCalibration (void);

void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
}
 
void DelayXLCD(void){                               //1000us = 1ms
    Delay1KTCYx(5);  
 }
 
void DelayPORXLCD(void){
    Delay1KTCYx(15);
 }
 
void init_lcd(void){ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
}

void printTemp (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putsXLCD(lcdVariable);
    while(BusyXLCD());
}

void configTemp (void){
    ow_reset();                                             //resets the D1822 thermometer
    
    ow_write_byte(0xCC);                                    //Skip ROM check command
    ow_write_byte(0x4E);
    ow_write_byte(0x00);
    ow_write_byte(0x00);
    ow_write_byte(0x5F);
}

void readTemp (void){
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0x44);                                    //Begin temperature read and conversion
    Delay10KTCYx(40);                                     //The required time needed for the temp conversion process is 750ms. 800ms was implemented to give
                                                            //a sizeable error window
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0xBE);
    temp_read_LSB = ow_read_byte();
    temp_read_MSB = ow_read_byte();   
}

void obtainInteger (void){
    temp_LSB = temp_read_LSB >> 4;
    temp_MSB = temp_read_MSB << 4;
    temp_integer = temp_MSB | temp_LSB;  
}

void obtainFraction (void){
    /*Assortment of checks to determine the fraction*/
    if(temp_read_LSB & 0x01){
        temp_float += 0.0625;
    }
    if(temp_read_LSB & 0x02){
        temp_float += 0.125;
    }
    if(temp_read_LSB & 0x04){
        temp_float += 0.25;
    }
    if(temp_read_LSB & 0x08){
        temp_float += 0.5;
    }
    
    temp_fraction = temp_float*1000;
}

int approx_value = 0;

int approximation (int a){
    temp_hundreds = a/100;
    temp_tens = a - (temp_hundreds*100);
    
    temp_tens = temp_tens/10;
    temp_ones = a - (temp_hundreds*100) - (temp_tens*10);
    
    if (temp_ones >= 5){
        temp_tens += 1;
    }
    
    if (temp_tens >= 5){
        temp_hundreds +=1;
    }
    
    approx_value = temp_hundreds;
    
    return approx_value;
}

void obtainSign (void){
    temp_sign = (temp_read_MSB & 0xF8);
    
    if(temp_sign == 0){
        sprintf(lcdVariable, "Temp:+%d.%d%cC", running_average_integer, running_average_fraction, temp_degree);
    }
    else{
        sprintf(lcdVariable, "Temp:-%d.%d%cC", temp_integer, temp_hundreds, temp_degree);
    }
}

void resetTempConversion (void){
    temp_float = 0.0;
    temp_integer = 0;
    temp_fraction = 0;
    temp_sign = 0;
}

void errorCalibration (void){
    counter = 0;
    
    configTemp();
    
    while (counter != 5){
        readTemp();
        obtainInteger();
        obtainFraction();
        temp_fraction = approximation(temp_fraction);
        
        sum_integer += temp_integer;
        temp_sum_fraction += temp_fraction;
        
        //Added code to accurately calculate the sum of temperature readings
        if(temp_sum_fraction > 9){
            sum_integer += 1;
            sum_fraction = temp_sum_fraction - 10;
        }
        else{
            sum_fraction = temp_sum_fraction;
        }
        //End of section----------------------------------------------------
        
        resetTempConversion();
        
        WriteCmdXLCD(0x01);
        while(BusyXLCD());
        sprintf(lcdVariable, "Time: %d", counter);
        putsXLCD(lcdVariable);
        while(BusyXLCD());
       
        counter++;
    }
    
    //AVERAGE
    //Section that divides the decimal portion of the reading
    decimal_division_initial_value = (float)sum_fraction/(float)(counter*10);
    integer_division_initial_value = sum_integer/counter;
    
    integer_variable_extraction = integer_division_initial_value;
    
    integer_division_value_to_add = integer_division_initial_value - (float)integer_variable_extraction;
    decimal_division_final_value = decimal_division_initial_value + integer_division_value_to_add; 
    decimal_division_final_value_integer = decimal_division_final_value*1000;
    
    
    average_integer = integer_variable_extraction;
    average_fraction = decimal_division_final_value_integer;
    
    average_fraction = approximation(average_fraction);
    //resetTempConversion();
}

void runningAverage (void){
    counter2 += 1;
    
    sum_integer += temp_integer;
    temp_sum_fraction += temp_fraction;
        
    //Added code to accurately calculate the sum of temperature readings
    if(temp_sum_fraction > 9){
        sum_integer += 1;
        sum_fraction = temp_sum_fraction - 10;
    }
    else{
        sum_fraction = temp_sum_fraction;
    }
        
    decimal_division_initial_value = (float)sum_fraction/(float)(counter2*10);
    integer_division_initial_value = sum_integer/counter2;
    
    integer_variable_extraction = integer_division_initial_value;
    
    integer_division_value_to_add = integer_division_initial_value - (float)integer_variable_extraction;
    decimal_division_final_value = decimal_division_initial_value + integer_division_value_to_add; 
    decimal_division_final_value_integer = decimal_division_final_value*1000;
    
    running_average_integer = integer_variable_extraction;
    running_average_fraction = decimal_division_final_value_integer;
    
    running_average_fraction = approximation(running_average_fraction);
}

void print (void){
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    sprintf(lcdVariable, "T:%d.%d,A:%d.%d", temp_integer, temp_fraction, average_integer, average_fraction);
    putsXLCD(lcdVariable);
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    sprintf(lcdVariable, "Count:%d", counter2);
    putsXLCD(lcdVariable);
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    sprintf(lcdVariable, "Sum:%d", sum_integer);
    putsXLCD(lcdVariable);   
}

void main(void)
{
    init_lcd();
    
    errorCalibration();
    obtainSign();
    printTemp();
        
    while(1){ 
        resetTempConversion();
        readTemp();
        obtainInteger();
        obtainFraction();
        temp_fraction = approximation(temp_fraction);
        runningAverage();
        obtainSign();
        printTemp();
    }
    Sleep();
}