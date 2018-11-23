void scrollRecordsHR(char SECTOR, char message, char scrollState, unsigned char TYPESIZE) /* message this will be replaced with void*/
{
    union uINT RXint;
    int x;
    
    if (message == SCROLL_UP && HRreccnt > 4)
    {
        if (HRreadAdd != 0)
        {
            if(scrollState == SCROLL_DOWN)
            {
                scrollState = SCROLL_UP;
                HRreadAdd = HRreadAdd - 8;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXint.intCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[3] = hrDisp[2];
                hrDisp[2] = hrDisp[1]; 
                hrDisp[1] = hrDisp[0];
                hrDisp[0] = RXint.intVAL;
            }
            else
            {
                HRreadAdd = HRreadAdd - TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXint.intCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[3] = hrDisp[2];
                hrDisp[2] = hrDisp[1]; 
                hrDisp[1] = hrDisp[0];
                hrDisp[0] = RXint.intVAL;
            }
            HRscrollCnt--;  
        }
    }
        
    else if(message == SCROLL_DOWN && HRreccnt > 4)
    {
        if(HRreadAdd != HRreadAddX)
        {
            if (scrollState == SCROLL_UP) 
            {
                scrollState = SCROLL_DOWN;
                HRreadAdd = HRreadAdd + 8;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXint.intCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[0] = hrDisp[1];
                hrDisp[1] = hrDisp[2];
                hrDisp[2] = hrDisp[3];
                hrDisp[3] =  RXint.intCHAR[x];
            }
            else
            {
                HRreadAdd = HRreadAdd + TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXint.intCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[0] = hrDisp[1];
                hrDisp[1] = hrDisp[2];
                hrDisp[2] = hrDisp[3];
                hrDisp[3] =  RXint.intCHAR[x];
            }           
        }
        HRscrollCnt++;
    }
    else
    {
        return; // misra C 2004 rules 14.10 else if constructs shall be terminated with else
    }
}
    

void scrollRecordsHRV(char SECTOR, char message, char scrollState, unsigned char TYPESIZE) /* message this will be replaced with void*/
{
    union uFLOAT RXfloat;
    int x;
    
    if (message == SCROLL_UP && HRVreccnt > 4)
    {
        if (HRVreadAdd != 0)
        {
            if(scrollState == SCROLL_DOWN)
            {
                scrollState = SCROLL_UP;
                HRVreadAdd = HRVreadAdd - 16;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRVreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrvDisp[3] = hrvDisp[2];
                hrvDisp[2] = hrvDisp[1]; 
                hrvDisp[1] = hrvDisp[0];
                hrvDisp[0] = RXfloat.floatVAL;
            }
            else
            {
                HRVreadAdd = HRVreadAdd - TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRVreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrvDisp[3] = hrvDisp[2];
                hrvDisp[2] = hrvDisp[1]; 
                hrvDisp[1] = hrvDisp[0];
                hrvDisp[0] = RXfloat.floatVAL;
            }
            HRVscrollCnt--;  
        }
    }
        
    else if(message == SCROLL_DOWN && HRVreccnt > 4)
    {
        if(HRVreadAdd != HRVreadAddX)
        {
            if (scrollState == SCROLL_UP) 
            {
                scrollState = SCROLL_DOWN;
                HRVreadAdd = HRVreadAdd + 16;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRVreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrvDisp[0] = hrvDisp[1];
                hrvDisp[1] = hrvDisp[2];
                hrvDisp[2] = hrvDisp[3];
                hrvDisp[3] =  RXfloat.floatCHAR[x];
            }
            else
            {
                HRVreadAdd = HRVreadAdd + TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRVreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrvDisp[0] = hrvDisp[1];
                hrvDisp[1] = hrvDisp[2];
                hrvDisp[2] = hrvDisp[3];
                hrvDisp[3] =  RXfloat.floatCHAR[x];
            }           
        }
        HRVscrollCnt++;
    }
    else
    {
        return; // misra C 2004 rules 14.10 else if constructs shall be terminated with else
    }
}
    

void scrollRecordsTEMP(char SECTOR, char message, char scrollState, unsigned char TYPESIZE) /* message this will be replaced with void*/
{
    union uFLOAT RXfloat;
    int x;
    
    if (message == SCROLL_UP && TEMPreccnt > 4)
    {
        if (TEMPreadAdd != 0)
        {
            if(scrollState == SCROLL_DOWN)
            {
                scrollState = SCROLL_UP;
                TEMPreadAdd = TEMPreadAdd - 16;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, TEMPreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                tempDisp[3] = tempDisp[2];
                tempDisp[2] = tempDisp[1]; 
                tempDisp[1] = tempDisp[0];
                tempDisp[0] = RXfloat.floatVAL;
            }
            else
            {
                TEMPreadAdd = TEMPreadAdd - TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, TEMPreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                tempDisp[3] = tempDisp[2];
                tempDisp[2] = tempDisp[1]; 
                tempDisp[1] = tempDisp[0];
                tempDisp[0] = RXfloat.floatVAL;
            }
            TEMPscrollCnt--;  
        }
    }
        
    else if(message == SCROLL_DOWN && TEMPreccnt > 4)
    {
        if(TEMPreadAdd != TEMPreadAddX)
        {
            if (scrollState == SCROLL_UP) 
            {
                scrollState = SCROLL_DOWN;
                TEMPreadAdd = TEMPreadAdd + 16;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, TEMPreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                tempDisp[0] = tempDisp[1];
                tempDisp[1] = tempDisp[2];
                tempDisp[2] = tempDisp[3];
                tempDisp[3] =  RXfloat.floatCHAR[x];
            }
            else
            {
                TEMPreadAdd = TEMPreadAdd + TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, TEMPreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                tempDisp[0] = tempDisp[1];
                tempDisp[1] = tempDisp[2];
                tempDisp[2] = tempDisp[3];
                tempDisp[3] =  RXfloat.floatCHAR[x];
            }           
        }
        TEMPscrollCnt++;
    }
    else
    {
        return; // misra C 2004 rules 14.10 else if constructs shall be terminated with else
    }
}
    

void scrollRecordsHR(char SECTOR, char message, char scrollState, unsigned char TYPESIZE) /* message this will be replaced with void*/
{
    union uFLOAT RXfloat;
    int x;
    
    if (message == SCROLL_UP && HRreccnt > 4)
    {
        if (HRreadAdd != 0)
        {
            if(scrollState == SCROLL_DOWN)
            {
                scrollState = SCROLL_UP;
                HRreadAdd = HRreadAdd - 8;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[3] = hrDisp[2];
                hrDisp[2] = hrDisp[1]; 
                hrDisp[1] = hrDisp[0];
                hrDisp[0] = RXfloat.floatVAL;
            }
            else
            {
                HRreadAdd = HRreadAdd - TYPESIZE;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[3] = hrDisp[2];
                hrDisp[2] = hrDisp[1]; 
                hrDisp[1] = hrDisp[0];
                hrDisp[0] = RXfloat.floatVAL;
            }
            HRscrollCnt--;  
        }
    }
        
    else if(message == SCROLL_DOWN && HRreccnt > 4)
    {
        if(HRreadAdd != HRreadAddX)
        {
            if (scrollState == SCROLL_UP) 
            {
                scrollState = SCROLL_DOWN;
                HRreadAdd = HRreadAdd + 8;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[0] = hrDisp[1];
                hrDisp[1] = hrDisp[2];
                hrDisp[2] = hrDisp[3];
                hrDisp[3] =  RXfloat.floatCHAR[x];
            }
            else
            {
                HRreadAdd = HRreadAdd + TYPESIZE;
                HRreadAdd = HRreadAdd + 8;
                for (x = 0; x < TYPESIZE; x++)
                {
                    readDATA(SECTOR, HRreadAdd + x);
                    RXfloat.floatCHAR[x] = RXbits.CHARBITS;
                }
                hrDisp[0] = hrDisp[1];
                hrDisp[1] = hrDisp[2];
                hrDisp[2] = hrDisp[3];
                hrDisp[3] =  RXfloat.floatCHAR[x];
            }           
        }
        HRscrollCnt++;
    }
    else
    {
        return; // misra C 2004 rules 14.10 else if constructs shall be terminated with else
    }
}
    

