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
}



int Stepper::setEnable(bool newEnable) {
}


int Stepper::setBPM(int beatsPerMinute) {
}
