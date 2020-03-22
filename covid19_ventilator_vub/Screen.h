/*
 * Screen.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"
#include "LiquidCrystal_I2C.h"
class Screen {
    private:
        uint8_t pinSDA;
        uint8_t pinSDL;
        LiquidCrystal_I2C display;
        int flashFrequency;
        uint32_t flashTimer;


    public :
        Screen();
         void setup();
         void loop();
         void refreshValue_centi(int value,int xcor,int ycor);
         void refreshValue_deci(int value,int xcor,int ycor);
         void setBackGround();
         void print(int xcor,int ycor,int value);
         void flashScreen(uint16_t frequency) ;
         void flashScreenStop() ;


};


