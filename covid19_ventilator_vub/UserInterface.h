/*
 * UserInterface.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"

class UserInterface {
        ButtonControler &myButtonControler;
        Screen &myScreen;
        int requestedPressure;
        int requestedTargetVolume;
        int requestedBPM;
        int requestedTriggerPressure;
    public:
        UserInterface(ButtonControler &buttonControler, Screen &screen);
        void setup();
        void loop();
        int getRequestedPressure() const {
            return requestedPressure;
        }
        ;

        int getRequestedTargetVolume() const {
            return requestedTargetVolume;
        }

        int getRequestedTriggerPressure() const {
            return requestedTriggerPressure;
        }

        int getRequestedBpm() const {
            return requestedBPM;
        }
};
extern UserInterface myUserInterface;

