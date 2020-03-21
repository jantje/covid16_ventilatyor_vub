/*
 * Screen.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Screen.h"



Screen::Screen(uint8_t pinSDA, uint8_t pinSDL) :
display(0x3F, 20,  4)
{

}

void Screen::setup() {

    display.setBacklight(HIGH);
    // display.print("Hello, Medical world!");

    display.clear();

}

void Screen::loop() {

}

void Screen::refreshValue(int value, int xcor, int ycor) {
     display.setCursor(xcor, ycor);
     display.print(value);
}
