/*
 * UserInterface.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

/* Array Position  - Function
         0           Mute
         1           Breath Hold
         2           Start/Stop
        7/3          Trig Up/Down
        8/4          BPM Up/Down
        9/5          V Up/Down
       10/6          P Up/Down
         11          Mode
*/
#include "UserInterface.h"

UserInterface::UserInterface() :
		myScreen() {
	Screen myScreen();
	requestedPressure = 20*10;
	requestedTargetVolume = 600*10;
	requestedBPM = 12*10;
	requestedTriggerPressure = 8*10;
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
	static uint32_t lastReadTime = loopMillis;
	static uint32_t lastPrintTime = loopMillis;

	static int buttonJump[sizeof(buttons)];
	if (loopMillis - lastReadTime > 10) {
		lastReadTime = loopMillis;
		myScreen.loop();
		for (unsigned int curButton = 0; curButton < sizeof(buttons);
				curButton++) {
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
	} else {
		if (loopMillis - lastPrintTime > 10) {
			lastPrintTime=loopMillis;
			static int delayCounter = 0;
			delayCounter++;
			switch (delayCounter % 4) {
			case 0: {
				myScreen.refreshValue_deci(requestedTriggerPressure, 12, 3);
				break;
			}
			case 1: {
				myScreen.refreshValue_deci(requestedBPM, 12, 2);
				break;
			}
			case 2: {
				myScreen.refreshValue_deci(requestedTargetVolume, 12, 1);
				break;
			}
			case 3: {
				myScreen.refreshValue_deci(requestedPressure, 12, 0);
				break;
			}
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
}

