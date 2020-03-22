/*
 * UserInterface.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */


#define BUTTON_MUTE 13
#define BUTTOM_BREATH 12
#define BUTTON_START_STOP 11
#define BUTTON_TRIG_UP 7
#define BUTTON_TRIG_DOWN 3
#define BUTTON_BPM_UP 8
#define BUTTON_BPM_DOWN 4
#define BUTTON_VOLUME_UP 9
#define BUTTON_VOLUME_DOWN 5
#define BUTTON_VOLUMEPRESSURE_UP 10
#define BUTTON_VOLUMEPRESSURE_DOWN 6
#define BUTTON_MODE 2
//TODO deze arrays aanpak is niet zo goed omdat je zo 2 indirecties hebt
//verzin iets beter
#include "UserInterface.h"

UserInterface::UserInterface() :
		myScreen() {
	Screen myScreen();
	requestedPressure = 20 * 10;
	requestedTargetVolume = 600 * 10;
	requestedBPM = 12 * 10;
	requestedTriggerPressure = 8 * 10;
}

void UserInterface::setup() {
	myScreen.setup();
	uint8_t buttonPins[NUMBUTTONS] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

	for (unsigned int curButton = 0; curButton < NUMBUTTONS; curButton++) {
		buttons[curButton].setPin(buttonPins[curButton]);
		buttons[curButton].setup();
	}
	pinMode(BUTTOM_BREATH, INPUT_PULLUP);
	pinMode(BUTTON_MUTE, INPUT_PULLUP);
}

void UserInterface::loop() {
	static uint32_t lastReadTime = loopMillis;

	static int buttonJump[NUMBUTTONS];
	if (loopMillis - lastReadTime > 10) {
		//read the buttons every 10 miliseconds
		lastReadTime = loopMillis;
		myScreen.loop();
		for (unsigned int curButton = 0; curButton < NUMBUTTONS; curButton++) {
			buttons[curButton].loop();
			buttonJump[curButton] = buttons[curButton].jumpValue();
		}

		requestedTriggerPressure = requestedTriggerPressure + buttonJump[7]
				- buttonJump[3];
		requestedBPM = requestedBPM + (buttonJump[8] - buttonJump[4]) * 5;
		requestedTargetVolume = requestedTargetVolume + buttonJump[9]
				- buttonJump[5];
		requestedPressure = requestedPressure + buttonJump[10] - buttonJump[6];
		if (requestedTriggerPressure < 0) {
			requestedTriggerPressure = 0;
		}
		if (requestedBPM < 0) {
			requestedBPM = 0;
		}
		if (requestedTargetVolume < 0) {
			requestedTargetVolume = 0;
		}
		if (requestedPressure < 0) {
			requestedPressure = 0;
		}

		static int counter=0;

		//mute the alarm if needed
		if (digitalRead(BUTTON_MUTE) == LOW) {
			myAlarm.muteAllert();
		}
		//Trigger the alarm for testing
		//TOFIX remove this code after testing
		if (digitalRead(BUTTOM_BREATH) == LOW) {
			myAlarm.allert(ALERT_NO_BREATHING);
		}
		static int prefRequestedTriggerPressure = -1;
		if (prefRequestedTriggerPressure != requestedTriggerPressure) {
			myScreen.refreshValue_deci(requestedTriggerPressure, 12, 3);
			prefRequestedTriggerPressure = requestedTriggerPressure;
		}
		static int prefrequestedBPM = -1;
		if (prefrequestedBPM != requestedBPM) {
			myScreen.refreshValue_deci(requestedBPM, 12, 2);
			prefrequestedBPM = requestedBPM;
		}
		static int prefrequestedTargetVolume = -1;
		if (prefrequestedTargetVolume != requestedTargetVolume) {
			myScreen.refreshValue_deci(requestedTargetVolume, 12, 1);
			prefrequestedTargetVolume = requestedTargetVolume;
		}
		static int prefRequestedPressure = -1;
		if (prefRequestedPressure != requestedPressure) {
			myScreen.refreshValue_deci(requestedPressure, 12, 0);
			prefRequestedPressure = requestedPressure;
		}

	}

	//
	//    if (Display_setpoint_trigger != setpointData.trigger) {
	//      Display_setpointTrigger(setpointData.trigger);
	//      display.setCursor(12, 3);
	//      display.print(Display_setpoint_trigger);
	//    }
	//
	//    if (Display_mode != setpointData.mode) {
	//      Display_setMode(setpointData.mode);
	//      display.setCursor(19, 0);
	//      char c = Display_mode + 65; // ascii table for A (if 0)
	//      display.print(c);
	//    }
	//
	//    if (Display_current_P != currentData.pressure) {
	//      Display_setPressure(currentData.pressure);
	//      display.setCursor(2, 0);
	//      display.print(Display_current_P);
	//
	//    }
	//
	//    if (Display_current_V != currentData.volume) {
	//      Display_setVolume(currentData.volume);
	//      display.setCursor(2, 1);
	//      display.print(Display_current_V);
	//    }
	//
	//    if (Display_current_bpm != currentData.bpm) {
	//      Display_setBreathsPerMinute(currentData.bpm);
	//      display.setCursor(2, 2);
	//      display.print(Display_current_bpm);
	//    }
	//
	//    if (Display_current_trigger != currentData.trigger) {
	//      Display_setTrigger(currentData.trigger);
	//      display.setCursor(2, 3);
	//      display.print(Display_current_trigger);
	//    }
}


