/*
 * Alarm.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Alarm.h"

Alarm::Alarm(uint8_t alarmPin) {
    pin=alarmPin;
}

void Alarm::setup() {
}

void Alarm::loop() {
    if(allertCounter>0){
        //new alert arrived
    }
    allertCounter=0;

}

void Alarm::allert(uint32_t& timer) {
    timer=loopMillis;
    allertCounter++;
}

