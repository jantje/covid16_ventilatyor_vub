/*
 * Alarm.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Alarm.h"

Alarm::Alarm(uint8_t alarmPin) {
    pin=alarmPin;
    LastNoBreathingAlert=0;
    LastPressureToHighAlert=0;
    LastPressureZeroAlert=0;
    LastNoFlowAlert=0;
    LastMechanicalFailureAlert=0;
    allertCounter=0;
}

void Alarm::setup() {
}

void Alarm::loop() {
    if(allertCounter>0){
        //new alert arrived
        SerialOutput.println(F("Alarm is ringing"));
    }
    allertCounter=0;

}

void Alarm::allert(uint32_t& timer) {
    timer=loopMillis;
    allertCounter++;
}

