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
	display.init();
 display.setBacklight(HIGH);


}

void Screen::loop() {

}

void Screen::refreshValue(int value, int xcor, int ycor) {
	static char stringBuffer[10];
     display.setCursor(xcor, ycor);
     snprintf(stringBuffer,10,"%03d.%02d",value/100,value%100);
     display.print(stringBuffer);
}
