/*
 * Screen.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "Arduino.h"
class Screen {
    private:
        uint8_t pinSDA;
        uint8_t pinSDL;

        int requestedPressure;
        int requestedTargetVolume;
        int requestedBPM;
        int resquestedTriggerPressure;
    public :
        Screen(uint8_t pinSDA, uint8_t pinSDL);
         void setup();
         void loop();

        int getRequestedBpm() const {
            return requestedBPM;
        }

        int getRequestedPressure() const {
            return requestedPressure;
        }

        int getRequestedTargetVolume() const {
            return requestedTargetVolume;
        }

        int getResquestedTriggerPressure() const {
            return resquestedTriggerPressure;
        }
};


