/*
 * Alarm.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once

#include "covid19_ventilator.h"

typedef enum {
	ALERT_NO_BREATHING = 0, ALERT_PRESSURE_TO_HIGH, ALERT_LAST_ALERT_TYPE
} ALERT_TYPES;
typedef enum {
	ALERT_STATE_MUTED = 0,   //first startup of the machine
	ALERT_STATE_OFF,
	ALERT_STATE_ON,
} ALARM_STATE;
class Alarm {

public:
	Alarm(uint8_t alarmPin);
	void setup();
	void loop();
	void allert(ALERT_TYPES alert);
	void muteAllert();

private:
	uint32_t lastMuteTime;
	uint8_t pin;
	int allerts[ALERT_LAST_ALERT_TYPE];
	ALARM_STATE curState;
	bool soundHorn;
	bool muteRequested;
};

extern Alarm myAlarm;

