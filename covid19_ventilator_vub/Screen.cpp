/*
 * Screen.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Screen.h"



Screen::Screen() :
display(0x3F, 20,  4)
{


}

void Screen::setup() {
	display.init();
 display.setBacklight(HIGH);
}



void Screen::refreshValue_centi(int value, int xcor, int ycor) {
	static char stringBuffer[10];
     display.setCursor(xcor, ycor);
     snprintf(stringBuffer,10,"%03d.%02d",value/100,value%100);
     display.print(stringBuffer);
}
void Screen::refreshValue_deci(int value, int xcor, int ycor) {
	static char stringBuffer[10];
     display.setCursor(xcor, ycor);
     snprintf(stringBuffer,10,"%03d.%01d",value/10,value%10);
     display.print(stringBuffer);
}
