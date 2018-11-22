/* 
 * File:   Modules.h
 * Author: Yehu Carrington
 *
 * Created on November 17, 2018, 11:15 PM
 */

#ifndef MODULES_H
#define	MODULES_H
#include <p18f452.h>

void InitPIC();
void TemperatureStub(void);
void HeartRateStub(void);
void GlucoseStub(void);
void SPO2Stub(void);
void SpeakerTestStub(void);
void LCDRefreshStub(void);
void BlinkLEDStub(void);
void DefaultStub(void);
void RamLeftStub(void);
void RamRightStub(void);
void RamRateLowStub(void);
void RamRateHighStub(void);

#endif	/* MODULES_H */

