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
        uint32_t stroke;
        uint32_t newStroke;
        uint8_t stepPin;
        uint8_t dirPin;
        uint8_t enablepin;
    public :
        Stepper(uint8_t stepPin,  uint8_t dirPin, uint8_t enablepin);
         void setup( );
         void loop();

         /**
          * The speed is the delay betweeen 2 steps
          * not sure this should be miliseconds or nanoseconds
          */
         int setSpeed(int speed){
             newSpeed =speed;
             return currentSpeed;
         }
         int setEnable(bool enable);
         uint32_t setStroke(uint32_t stroke){
             newStroke=stroke;
             return stroke;
         };
         /**tell the machine how many times the machine needs to loop per minute
          * this may be 100 bigger to support fractions
          */

         int setBPM(int beatsPerMinute);

};

extern Stepper myBagStepper;

