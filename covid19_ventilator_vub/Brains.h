/*
 * Brains.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#pragma once
#include "covid19_ventilator.h"

class Brains {
    private:
        int currentRequestedPressure;
        int currentRequestedTargetVolume;
        int currentRequestedBPM;
        int currentResquestedTriggerPressure;

        MACHINE_STATE currentState=STATE_STARTING;
        MACHINE_STATE newState=STATE_STARTING;
        Mode1 myMode1;
        Mode2 myMode2;
    public :
        Brains();
         void setup();
         void loop();
         void alarmNoBreathing();

};

extern Brains myBrains;
