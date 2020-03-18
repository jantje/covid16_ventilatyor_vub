/*
 * Stepper.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "Arduino.h"

class Stepper {
    private:
        int currentSpeed;
        int newSpeed;
        bool enabled;
        uint8_t stepPin;
        uint8_t dirPin;
        uint8_t enablepin;
    public :
        Stepper(uint8_t stepPin,  uint8_t dirPin, uint8_t enablepin);
         void setup( );
         void loop();
         int setSpeed(int speed);
         int setEnable(bool enable);
         int setStroke(int stroke);
         int setBPM(int beetsPerMinute);


};


