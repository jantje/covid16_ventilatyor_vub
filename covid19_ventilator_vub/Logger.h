/*
 * Logger.h
 *
 *  Created on: 21 mrt. 2020
 *      Author: gast1
 */
#pragma once
#include "covid19_ventilator.h"

class Logger {
	uint32_t setupMillis;
	uint16_t logDelay;
	int logedRequestedBPM;
	int logedReqestedTargetVolume;
	int logedRequestedTriggerPressure;
	int logedRequestedPressure;

public:
	Logger();
	void setup();
	void loop();
	void setLogDelay(uint16_t newLogDelay);
	void resend();

	;
};

extern Logger myLogger;
extern Stream &SerialOutput;
