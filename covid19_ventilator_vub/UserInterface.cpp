/*
 * UserInterface.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "UserInterface.h"

UserInterface::UserInterface(uint8_t pinSDA, uint8_t pinSDL) :
		myScreen(pinSDA, pinSDL) {
	Screen myScreen();
	requestedPressure = 0;
	requestedTargetVolume = 0;
	requestedBPM = 0;
	requestedTriggerPressure = 0;
}

void UserInterface::setup() {
	myScreen.setup();
	uint8_t buttonPins[sizeof(buttons)] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3,
			2 };
	unsigned int curButton;
	for (curButton = 0; curButton < sizeof(buttons); curButton++) {
		buttons[curButton].setPin(buttonPins[curButton]);
		buttons[curButton].setup();
	}
}

void UserInterface::loop() {
	static uint32_t lastactionTime = loopMillis;
	if (loopMillis - lastactionTime > 10) {
		lastactionTime=loopMillis;
		uint8_t buttonJump[sizeof(buttons)];
		myScreen.loop();
		for (unsigned int curButton = 0; curButton < sizeof(buttons);
				curButton++) {
			buttons[curButton].loop();
			buttonJump[curButton] = buttons[curButton].jumpValue();
		}

		requestedTriggerPressure = requestedTriggerPressure + buttonJump[7]
				- buttonJump[3];
		requestedBPM = requestedBPM + buttonJump[8] - buttonJump[4];
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

		myScreen.refreshValue(requestedTriggerPressure, 12, 3);
		myScreen.refreshValue(requestedBPM, 12, 2);
		myScreen.refreshValue(requestedTargetVolume, 12, 1);
		myScreen.refreshValue(requestedPressure, 12, 0);

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
}
