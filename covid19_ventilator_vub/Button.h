/*
 * button.h
 *
 *  Created on: 21 mrt. 2020
 *      Author: jan
 */

#pragma once
#include "Arduino.h"

extern uint32_t loopMillis;

class Button {
    private:
        uint8_t buttonPin;
        bool officialState;
        uint32_t pressedSince;
    public :
        Button();
        void setPin(uint8_t buttonPin);
         void setup( );
         void loop();
         bool isPressed();
         int jumpValue();

};

