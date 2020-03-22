/*
 * UserInterface.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"
#include "LiquidCrystal_I2C.h"
#include "Pins.h"
#define NUMBUTTONS 12

class UserInterface {

        Screen myScreen;
        int requestedPressure;
        int requestedTargetVolume;
        int requestedBPM;
        int requestedTriggerPressure;
        Button buttons[NUMBUTTONS];
    public:
        UserInterface();
        void setup();
        void loop();
        int getRequestedPressure() const {
            return requestedPressure;
        }

        int getRequestedTargetVolume() const {
            return requestedTargetVolume;
        }

        int getRequestedTriggerPressure() const {
            return requestedTriggerPressure;
        }

        int getRequestedBpm() const {
            return requestedBPM;
        }

        void flashScreen(uint16_t frequency) {
        	myScreen.flashScreen(frequency);
        }
        void flashScreenStop() {
        	myScreen.flashScreenStop();
        }

};
extern UserInterface myUserInterface;

