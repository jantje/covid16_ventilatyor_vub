/*
 * Sensors.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"

class Sensors {
    public:
        Sensors(uint8_t sensorPin1, uint8_t sensorPin2);
         void setup();
         void loop();
};


