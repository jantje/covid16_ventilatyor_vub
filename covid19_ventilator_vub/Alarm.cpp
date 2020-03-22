/*
 * Alarm.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Alarm.h"

Alarm::Alarm(uint8_t alarmPin) {
	pin = alarmPin;
	curState = ALERT_STATE_OFF;
	soundHorn = false;
	lastMuteTime = 0;
}

void Alarm::setup() {
	pinMode(pin, OUTPUT);
	digitalWrite(pin, 0);
}

void Alarm::loop() {
	switch (curState) {
	case ALERT_STATE_OFF: {
		if (soundHorn) {
			SerialOutput.println(F("Alarm start ringing"));
			analogWrite(pin, 125);
			curState = ALERT_STATE_ON;
			myUserInterface.flashScreen(500);
		}
		break;
	}
	case ALERT_STATE_MUTED: {
		if (loopMillis - lastMuteTime > 60000) {
			curState = ALERT_STATE_OFF;
			soundHorn = 0;
			for (int curAlert = 0; curAlert < ALERT_LAST_ALERT_TYPE;
					curAlert++) {
				allerts[curAlert] = 0;
			}
		}
		break;
	}
	case ALERT_STATE_ON: {
		if (muteRequested) {
			analogWrite(pin, 0);
			lastMuteTime = loopMillis;
			curState == ALERT_STATE_MUTED;
			muteRequested = false;
			myUserInterface.flashScreenStop();
			break;
		}

	}
	}

}

void Alarm::allert(ALERT_TYPES alert) {
	soundHorn = true;
	allerts[alert]++;
}

void Alarm::muteAllert() {
	muteRequested = true;
}
