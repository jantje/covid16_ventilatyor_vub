/*
 * Sensors.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Sensors.h"

Sensors::Sensors(uint8_t stepperEindeloopBeginPin, uint8_t stepperEindeloopEindPin) {
    mystepperEindeloopBeginPin=stepperEindeloopBeginPin;
    mystepperEindeloopEindPin=stepperEindeloopEindPin;
}

void Sensors::setup() {
    pinMode(mystepperEindeloopBeginPin,INPUT);
    pinMode(mystepperEindeloopEindPin,INPUT);

}

void Sensors::loop() {
    myStepperEindeloopBegin=(digitalRead( mystepperEindeloopBeginPin)==LOW);
    myStepperEindeloopEind=(digitalRead( mystepperEindeloopEindPin)==LOW);

}


