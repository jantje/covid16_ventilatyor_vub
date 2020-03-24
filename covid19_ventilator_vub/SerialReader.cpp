/*
 * SerialReader.cpp
 *
 *  Created on: 22 mrt. 2020
 *      Author: jantje
 */
#include "covid19_ventilator.h"
#include "SerialReader.h"
SerialReader mySerialReader;

SerialReader::SerialReader() {
}

void SerialReader::setup() {
	myReader.setup();
}

void SerialReader::loop() {
	myReader.loop();
	if (myReader.messageReceived()) {
		const char *newMessage = myReader.getMessage();
		Serial.println(myReader.getMessage());
		if (strncmp(newMessage, "FREQ=", 5) == 0) {

			int freq;
			if (sscanf(newMessage + 5, "%d", &freq) == 1) {
				if (freq == -1) {
					myLogger.resend();
				} else {
					myLogger.setLogDelay(freq);
				}
			}
		} else if (strncmp(newMessage, "STEPS=", 6) == 0) {
			int numSteps;
			if (sscanf(newMessage + 6, "%d", &numSteps) == 1) {
				if (numSteps > 100) {
					Serial.print("Setting steps to: ");
					Serial.println(numSteps);
					setNumberOfSteps(numSteps);
				}
			}
		}

	}
}
