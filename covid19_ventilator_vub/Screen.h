/*
 * Screen.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "Arduino.h"
#include "LiquidCrystal_I2C.h"
class Screen {
    private:
        uint8_t pinSDA;
        uint8_t pinSDL;
        LiquidCrystal_I2C display;

    public :
        Screen(uint8_t pinSDA, uint8_t pinSDL);
         void setup();
         void loop();
         void refreshValue(int value,int xcor,int ycor);


};


