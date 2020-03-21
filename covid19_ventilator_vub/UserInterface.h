/*
 * UserInterface.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"
#include "LiquidCrystal_I2C.h"

class UserInterface {

        Screen myScreen;
        int requestedPressure;
        int requestedTargetVolume;
        int requestedBPM;
        int requestedTriggerPressure;
        Button buttons[12];
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
        bool IsAlarmDisabled() const;
};
extern UserInterface myUserInterface;

