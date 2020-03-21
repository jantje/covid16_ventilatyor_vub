/*
 * Logger.cpp
 *
 *  Created on: 21 mrt. 2020
 *      Author: gast1
 */

#include "Logger.h"
Logger myLogger;

void Logger::setup() {
	setupMillis = millis();
}

void Logger::loop() {

	static uint32_t loopCounter = 0;
	static uint32_t PrefLoopMillis = loopMillis;
	static uint16_t maxLoopDuration = 0;
	uint16_t LastloopDuration = loopMillis - PrefLoopMillis;

	maxLoopDuration = max(maxLoopDuration, LastloopDuration);
	PrefLoopMillis = loopMillis;
	loopCounter++;

	if (millis()-loopMillis>2){
		// if the loop took to long don't log
		return;
	}
	static uint32_t lastMonitoringReport;
	if (loopMillis - lastMonitoringReport > 40) {
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
