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
    switchToState(STATE_DISABLED);
    pinMode(enablepin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
}

void Stepper::loop() {
    if (nextState != state) {
        switchToState(nextState);
    }
    if (newEnabled != curentEnabled) {
        switchToState(STATE_DISABLED);
    }
    switch (state) {
        case STATE_DISABLED: {
            if (newEnabled) {
                curentEnabled = newEnabled;
                switchToState(STATE_STARTING_UP);
            }
            break;
        }
        case STATE_STARTING_UP: {
            if (mySensors.stepperEindeloopBegin()) {
                switchToState(STATE_WAITING_TO_START_CYCLE);
            } else {
                doStep();
            }
            break;
        }
        case STATE_BREATHING_IN: {
            if (numSteps >= stroke) {
                switchToState(STATE_BREATH_WAIT);
            } else {
                doStep();
            }
            break;
        }
        case STATE_BREATH_WAIT: {
            if (loopMillis - lastStateChange > TIME_BREATH_WAIT) {
                //TODO validate this number
            }
            break;
        }
        case STATE_BREATHING_OUT: {
            if (mySensors.stepperEindeloopBegin()) {
                switchToState(STATE_WAITING_TO_START_CYCLE);
            } else {
                doStep();
            }
            break;
        }
        case STATE_WAITING_TO_START_CYCLE: {
            if ((loopMillis - timeStartLastCycle) > MAX_TIME_BETWEEN_BREATH_CYCLES) {
                SerialOutput.println(F("Stepper waited to long; forcing cycle start"));
                startCycle();
                myBrains.alarmNoBreathing();
            }
        }
    }

    // emergency breathing

}

void Stepper::switchToState(STEPPER_STATE newState) {
    switch (newState) {
        case STATE_DISABLED: {
            curentEnabled = false;
            stopStepping();
            break;
        }
        case STATE_STARTING_UP: {

            startStepping(-1 * MAXMOVESPEED);
            break;
        }
        case STATE_BREATHING_IN: {
            timeStartLastCycle = loopMillis;
            startStepping(currentSpeed);
            break;
        }
        case STATE_BREATH_WAIT: {
            stopStepping();
            break;
        }
        case STATE_BREATHING_OUT: {
            startStepping(-1*currentSpeed);
            break;
        }
        case STATE_WAITING_TO_START_CYCLE: {
            stopStepping();
            break;
        }

    }
    lastStateChange = loopMillis;
}

void Stepper::startStepping(int speed) {
    if (speed == 0) {
        digitalWrite(enablepin, LOW);
    } else {
        digitalWrite(enablepin, HIGH);
        if (speed > 0) {
            digitalWrite(dirPin, HIGH);
        } else {
            digitalWrite(dirPin, LOW);
        }
    }
    actualSpeed = abs(speed);
    numSteps=0;
}

void Stepper::doStep() {
    //TODO need to be checked with actual motor this way max speed is 500 steps/second
    //would be great if I would know the time the pin needs to be high :-)
    if((stepPinStatus==HIGH) &&(loopMillis-timeLastPinHigh>=1)){
        digitalWrite(stepPin,LOW);
        stepPinStatus=LOW;
    }
    if(loopMillis-timeLastPinHigh>=actualSpeed){
        timeLastPinHigh=loopMillis;
        digitalWrite(stepPin,HIGH);
        stepPinStatus=HIGH;
        numSteps++;
    }
}

bool Stepper::startCycle() {
    if (state == STATE_WAITING_TO_START_CYCLE) {
        nextState = STATE_STARTING_UP;
        return true;
    }
    return false;
}
