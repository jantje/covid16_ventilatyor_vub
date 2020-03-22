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
				if(freq==-1){
					myLogger.resend();
				}else{
				myLogger.setLogDelay(freq);
				}
			}
		}

	}
}
