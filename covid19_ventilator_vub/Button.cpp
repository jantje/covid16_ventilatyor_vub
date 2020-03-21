/*
 * button.cpp
 *
 *  Created on: 21 mrt. 2020
 *      Author: jan
 */

#include "Button.h"

Button::Button() {
     buttonPin=255;
    officialState=HIGH;
    pressedSince=millis();
}

void Button::setup() {
    if(buttonPin!=255){
        pinMode(buttonPin,INPUT_PULLUP);
    }
}
#define UNSTABLE 3
void Button::loop() {

    static uint32_t lastDebounceTime;
    static int internalState=HIGH;
    if(buttonPin==255){
        return;
    }
    int lastReadState = digitalRead(buttonPin);
    if (lastReadState!=officialState)  {
        if(internalState==UNSTABLE){
            if(loopMillis-lastDebounceTime>10){
                officialState=lastReadState;
                pressedSince=loopMillis;
            }
        }
        else{
            lastDebounceTime = millis();
            internalState=UNSTABLE;
        }
    }

   }

   //PROCESS BUTTON DATA-----------------------------------------------------------------------
   /* Additional coding required -> if a button is kept pressed the modified data value should take bigger steps instead of a single step.

       This function takes the previousState of all buttons into account and modifies the global data accordingly.
   */


bool Button::isPressed() {
    return officialState==LOW;
}


void Button::setPin(uint8_t pin){
    buttonPin=pin;
}

int Button::jumpValue() {
    if(!isPressed()){
        return 0;
    }
    if(pressedSince-loopMillis>5000){
        return 10;
    }
    if(pressedSince-loopMillis>1000){
        return 5;
    }
    return 1;
}
