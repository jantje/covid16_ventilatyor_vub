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

void Logger::loop() {

	static uint32_t lastMonitoringReport;
	if ((loopMillis - lastMonitoringReport > logDelay) && (logDelay>0)) {
		lastMonitoringReport = loopMillis;
		SerialOutput.print("bpm=");
		SerialOutput.println(myUserInterface.getRequestedBpm());
		SerialOutput.print("Vol=");
		SerialOutput.println(myUserInterface.getRequestedTargetVolume());
		SerialOutput.print("Trig=");
		SerialOutput.println(myUserInterface.getRequestedTriggerPressure());
		SerialOutput.print("Pres=");
		SerialOutput.println(myUserInterface.getRequestedPressure());
	} else {
		static uint32_t lastPerformanceReport;
		if (loopMillis - lastPerformanceReport > 1000) {
			lastPerformanceReport = loopMillis;
			SerialOutput.print("loopTime:");
			SerialOutput.println(loopMillis - setupMillis);
			SerialOutput.print("LoopCntr:");
			SerialOutput.println(loopCounter);
			SerialOutput.print("Avg Time * 1000:");
			SerialOutput.println((loopMillis - setupMillis )*1000 / loopCounter);
			SerialOutput.print("Max loop :");
			SerialOutput.println(maxLoopDuration);
			maxLoopDuration=0;
		}
	}
}
