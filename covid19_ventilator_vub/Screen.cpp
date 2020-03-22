/*
 * Screen.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "covid19_ventilator.h"
#define DEFAULTBACKLIGHT HIGH



Screen::Screen() :
display(0x3F, 20,  4)
{


}

void Screen::setup() {
	display.init();
 display.setBacklight(DEFAULTBACKLIGHT);
}



void Screen::refreshValue_centi(int value, int xcor, int ycor) {
	static char stringBuffer[10];
     display.setCursor(xcor, ycor);
     snprintf(stringBuffer,9,"%03d.%02d",value/100,value%100);
     display.print(stringBuffer);
}
void Screen::refreshValue_deci(int value, int xcor, int ycor) {
	static char stringBuffer[10];
     display.setCursor(xcor, ycor);
     snprintf(stringBuffer,9,"%03d.%01d",value/10,value%10);
     display.print(stringBuffer);
}

void Screen::setBackGround() {
	//TODO print the chars and other on the screen
}

void Screen::print(int xcor, int ycor, int value) {
    display.setCursor(xcor, ycor);
    display.print(value);
}

void Screen::flashScreen(uint16_t frequency)  {
	flashFrequency=frequency;
}

void Screen::loop() {
	if(flashFrequency>0){
		if(loopMillis - flashTimer>flashFrequency){
			flashTimer=loopMillis;
			static bool backLight=0;
			display.setBacklight(backLight);
			backLight=!backLight;

		}

	}
}

void Screen::flashScreenStop()  {
	flashFrequency=-1;
	display.setBacklight(DEFAULTBACKLIGHT);
}
