//Adapted temperature sensor from Ismaeel Hosein (2018)
#include <p18f452.h> 
#include "delays.h"
#include "xlcd.h"
#include "ow.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 

void TemperatureSetup(void) {               //Setup of the temperature sensor
  ow_reset(); 
  ow_write(0x0C); 
  ow_write(0x00);
  ow_reset(); 
  ow_write(0xAC); 
  ow_reset();
}

float TemperatureMeasurement(void)          //Function to measure the temperature 
{
    int raw_reading = 0;                                //initialize variable for input data
    int total_temperature = 0;                      //initialize variable for total temperature 
    float average_temperature = 0.0;            //initialize variable for average temperature
    int count = 0;                                          //initialize variable for count
    while( count < 101){                                //while loop to sample data multiple times
	ow_write(0xEE); 
    	ow_write(0x22);                                                                                                                                                                                                                                                                                                                                                                      
    	ow_reset(); 
    	ow_write(0xAA); 
	raw_reading = ow_read();                //gets the reading and stores it in a variable
    	ow_reset();
    	total_temperature = total_temperature + raw_reading;            //adds all the temperature readings
        count++;                                            //increment count
    }
     average_temperature = (float) total_temperature / 101;             //finds the average of all the values taken
     return average_temperature;                                                       //return the value 
}

float whole_reading = 0.0;                      //initialize variable for the average temperature reading
int extract_integer;                                //initialize variable for the whole number part of the average temperature 
int extract_decimal;                                //initialize variable for the decimal part of the average temperature
char array[20];                                        //initialize variable to store the value as a string array

void ReadTemperature(){                                                                                     
    whole_reading =TemperatureMeasurement();                                    //call the function to measure the temperature
    extract_integer = whole_reading;                                                    //extract the whole part of the average temperature
    extract_decimal = (whole_reading-extract_integer)*100;                 //extract the decimal part of the average temperature
    sprintf(array,"%3d.%01d",extract_integer,extract_decimal);          //convert the values to a string array
    SetDDRamAddr(0x50); 
    putrsXLCD("Temp:           ");
    while(BusyXLCD());
    SetDDRamAddr(0x59);
    putsXLCD(array);
    while(BusyXLCD());
    SetDDRamAddr(0x5E);
    putrsXLCD(" C");
    while(BusyXLCD());
    return;
}

