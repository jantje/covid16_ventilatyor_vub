/*
 * Stepper.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Stepper.h"

Stepper::Stepper(uint8_t stepPin, uint8_t dirPin, uint8_t enablepin) {
}

void Stepper::setup() {
    setEnable(false);
}

void Stepper::loop() {
    // emergency breathing
    if (state==STATE_WAITING_TO_START_CYCLE && ((loopMillis-timeSinceLastCycle)>MAX_TIME_BETWEEN_BREATH_CYCLES)){
        startCycle();
        myBrains.alarmNoBreathing();
    }
}



int Stepper::setEnable(bool newEnable) {
}


