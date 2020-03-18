/*
 * Sensors.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"

class Sensors {
        uint8_t mystepperEindeloopBeginPin;
        uint8_t mystepperEindeloopEindPin;
        bool myStepperEindeloopBegin;
        bool myStepperEindeloopEind;
    public:
        Sensors(uint8_t stepperEindeloopBeginPin, uint8_t stepperEindeloopEindPin);
         void setup();
         void loop();
         bool stepperEindeloopBegin()const;
         bool stepperEindeloopEind()const;
};

extern Sensors mySensors;
