/*
 * Alarm.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once

#include "covid19_ventilator.h"

class Alarm {
        uint32_t LastNoBreathingAlert;
        uint32_t LastPressureToHighAlert;
        uint32_t LastPressureZeroAlert;
        uint32_t LastNoFlowAlert;
        uint32_t LastMechanicalFailureAlert;
        uint32_t LastPowerFailureAlert;
        uint8_t pin;
        uint8_t allertCounter;
    public :
        Alarm(uint8_t alarmPin);
         void setup();
         void loop();
         void alarmNoBreathing(){
             allert(LastNoBreathingAlert);
         }
         void alarmPressureToHigh(){
             allert(LastPressureToHighAlert);
         }
         void alarmPressureZero(){
             allert(LastPressureZeroAlert);
         }
         void alarmNoFlow(){
             allert(LastNoFlowAlert);
         }
         void alarmMechanicalFailure(){
             allert(LastMechanicalFailureAlert);
         }
         void alarmPowerFailure(){
             allert(LastNoBreathingAlert);
         }
private:
         void allert(uint32_t& timer);
};

extern Alarm myAlarm;


