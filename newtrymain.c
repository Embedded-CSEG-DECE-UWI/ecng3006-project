#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include "ow.h"
#include "xlcd.h"

//Reference for Code Template used from Previous Group Wiki
// Group F - 2b||!2b. ?Group_F - Temp_Sensor .? GitHub. Accessed October 29, 2019. 
//https://github.com/Embedded-CSEG-DECE-UWI/ecng3006-project/blob/Group-F-Temp_Sensor/Source/2.TempSensor_v4.c.
 

unsigned char tempLSB;
unsigned char tempMSB;
unsigned char temp_degree = 0xDF;

unsigned int tempLOW = 0;
unsigned int tempHIGH = 0;
unsigned int tempINT= 0;
unsigned int tempDEC = 0;
unsigned int Sign = 0;

unsigned int Hundreds = 0;
unsigned int Tens = 0;
unsigned int Ones = 0;

int counter = 0;

float Float_Val = 0.0;

int AvgInt = 0;
int AVG_Fract = 0;
int SumInt = 0;
int SumFract = 0;
int running_AvgInt = 0;
int running_AvgFract = 0;

char tempprint[20];       

void configTemp (void);
void readTemp (void);
void obtainint (void);
void obtainfract (void);
int approximation (int);
void obtainSign (void); 
void Resettmp (void);
void runningAverage (void);

void errorcal (void);


//The function below configures the temperature sensor for the correct operation 

void configTemp (void){
    ow_reset();                                            
    
    ow_write_byte(0xCC);                                    
    ow_write_byte(0x4E);
    ow_write_byte(0x00);
    ow_write_byte(0x00);
    ow_write_byte(0x5F);
}

//the function below reads the temperature value from the temperature sensor and stores it in two variables 

void readTemp (void){
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0x44);                                    
    Delay10KTCYx(40);                                     
                                                            
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0xBE);
    tempLSB = ow_read_byte();
    tempMSB = ow_read_byte();   
}

//This function converts two registers into a single integer value 

void obtainint (void){
    tempLOW = tempLSB >> 4;
    tempHIGH = tempMSB << 4;
    tempINT= tempHIGH | tempLOW;  
}

void obtainfract (void){
   
    if(tempLSB & 0x01){
        Float_Val += 0.0625;
    }
    if(tempLSB & 0x02){
        Float_Val += 0.125;
    }
    if(tempLSB & 0x04){
        Float_Val += 0.25;
    }
    if(tempLSB & 0x08){
        Float_Val += 0.5;
    }
    
    tempDEC = Float_Val*1000;
}

int approx_value = 0;

int approximation (int a){
    Hundreds = a/100;
    Tens = a - (Hundreds*100);
    
    Tens = Tens/10;
   Ones = a - (Hundreds*100) - (Tens*10);
    
    if (Ones >= 5){
        Tens += 1;
    }
    
    if (Tens >= 5){
        Hundreds +=1;
    }
    
    approx_value = Hundreds;
    
    return approx_value;
}

void obtainSign (void){
    Sign = (tempMSB & 0xF8);
    
    if(Sign == 0){
        sprintf(tempprint, "Temp:+%d.%d%cC", running_AvgInt, running_AvgFract, temp_degree);
    }
    else{
        sprintf(tempprint, "Temp:-%d.%d%cC", tempINT, Hundreds, temp_degree);
    }
}

void Resettmp (void){
    Float_Val = 0.0;
    tempINT= 0;
    tempDEC = 0;
    Sign = 0;
}

int temp_SumFract = 0;
float DEC_div_initial = 0.0;
float INT_div_initial = 0.0;

float DEC_div_val = 0.0;
int DEC_div_val_integer = 0;

int INT_var = 0;
float INT_div_to_add = 0.0;

float AVG_Fract_float = 0;

void errorcal (void){
    counter = 0;
    
    configTemp();
    
    while (counter != 5){
        readTemp();
        obtainint();
        obtainfract();
        tempDEC = approximation(tempDEC);
        
        SumInt += tempINT;
        temp_SumFract += tempDEC;
        
        
        if(temp_SumFract > 9){
            SumInt += 1;
            SumFract = temp_SumFract - 10;
        }
        else{
            SumFract = temp_SumFract;
        }
        Resettmp(); 
        counter++;
    }
    
   
    DEC_div_initial = (float)SumFract/(float)(counter*10);
    INT_div_initial = SumInt/counter;
    
    INT_var = INT_div_initial;
    
    INT_div_to_add = INT_div_initial - (float)INT_var;
    DEC_div_val = DEC_div_initial + INT_div_to_add; 
    DEC_div_val_integer = DEC_div_val*1000;
    
    
    AvgInt = INT_var;
    AVG_Fract = DEC_div_val_integer;
    
    AVG_Fract = approximation(AVG_Fract);
 
}

int counter2 = 5;
int test = 0;
void runningAverage (void){
    counter2 += 1;
    
    SumInt += tempINT;
    temp_SumFract += tempDEC;
        
    if(temp_SumFract > 9){
        SumInt += 1;
        SumFract = temp_SumFract - 10;
    }
    else{
        SumFract = temp_SumFract;
    }
        
    DEC_div_initial = (float)SumFract/(float)(counter2*10);
    INT_div_initial = SumInt/counter2;
    
    INT_var = INT_div_initial;
    
    INT_div_to_add = INT_div_initial - (float)INT_var;
    DEC_div_val = DEC_div_initial + INT_div_to_add; 
    DEC_div_val_integer = DEC_div_val*1000;
    
    running_AvgInt = INT_var;
    running_AvgFract = DEC_div_val_integer;
    
    running_AvgFract = approximation(running_AvgFract);
}


void fulltemp(void)
{
  
    errorcal();
    Resettmp();
    readTemp();             
    obtainint();     
    obtainfract();
    tempDEC = approximation(tempDEC);
    runningAverage();
    obtainSign();   //this puts the temperature variables into the actual buffer to be sent to the LCD  
    

}
