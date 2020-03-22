/*
 * Logger.cpp
 *
 *  Created on: 21 mrt. 2020
 *      Author: gast1
 */

#include "Logger.h"
Logger myLogger;

#if SERIAL_TX_BUFFER_SIZE <500
#error you need to add the following define to the command line -DSERIAL_TX_BUFFER_SIZE=500
// enlarging the the tx serial buffer reduces delay caused by serial prints
#endif

void Logger::setup() {
	setupMillis = millis();
}

int log(const char *key, int oldValue, int newValue) {
	if (oldValue != newValue) {
		SerialOutput.print(key);
		SerialOutput.println(newValue);
	}
	return newValue;
}

Logger::Logger() {
	logDelay=1000;
	logedRequestedBPM =0;
	logedReqestedTargetVolume = 0;
	logedRequestedTriggerPressure =0;
	logedRequestedPressure = 0;
	setupMillis=0;
}


void Logger::loop() {

	static uint32_t lastMonitoringReport;
	if ((loopMillis - lastMonitoringReport > logDelay) && (logDelay > 0)) {
		lastMonitoringReport = loopMillis;
		SerialOutput.print("clock=");
		SerialOutput.println(loopMillis);
		logedRequestedBPM = log("bpm=", logedRequestedBPM,
				myUserInterface.getRequestedBpm());
		logedReqestedTargetVolume = log("Vol=", logedReqestedTargetVolume,
				myUserInterface.getRequestedTargetVolume());
		logedRequestedTriggerPressure = log("Trig=", logedRequestedTriggerPressure,
				myUserInterface.getRequestedTriggerPressure());
		logedRequestedPressure = log("Pres=", logedRequestedPressure,
				myUserInterface.getRequestedPressure());
		static int testcounter=0;
		testcounter= log("test=", testcounter,++testcounter);

	} else {
		static uint32_t lastPerformanceReport;
		if (loopMillis - lastPerformanceReport > 1000) {
			lastPerformanceReport = loopMillis;
			SerialOutput.print("loopTime:");
			SerialOutput.println(loopMillis - setupMillis);
			SerialOutput.print("LoopCntr:");
			SerialOutput.println(loopCounter);
			SerialOutput.print("Avg Time * 1000:");
			SerialOutput.println(
					(loopMillis - setupMillis) * 1000 / loopCounter);
			SerialOutput.print("Max loop :");
			SerialOutput.println(maxLoopDuration);
			maxLoopDuration = 0;
		}
	}
}

void Logger::setLogDelay(uint16_t newLogDelay) {

			logDelay = newLogDelay;
			SerialOutput.print("Setting log delay :");
						SerialOutput.println(logDelay);
}

void Logger::resend() {
	logedRequestedBPM=-1;
	logedReqestedTargetVolume=-1;
	logedRequestedTriggerPressure=-1;
	logedRequestedPressure=-1;
}
