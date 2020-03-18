/*
 * Brains.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "Brains.h"

Brains::Brains() {
}

void Brains::setup(){

}
void Brains::loop(){
    int newRequestedPressure =myUserInterface.getRequestedPressure();
    int newRequestedTargetVolume =myUserInterface.getRequestedTargetVolume();
    int newRequestedBPM =myUserInterface.getRequestedBpm();
    int newResquestedTriggerPressure =myUserInterface.getRequestedTriggerPressure();
    if( currentRequestedPressure !=newRequestedPressure){
        //requested pressure has changed do something
        currentRequestedPressure =newRequestedPressure;
    }
    if(currentRequestedTargetVolume!=newRequestedTargetVolume){
        //target volume has changed dosomething
        currentRequestedTargetVolume=newRequestedTargetVolume;
    }
    if(currentRequestedBPM!=newRequestedBPM){
        //BPM has changed do something
        currentRequestedBPM=newRequestedBPM;
    }
    if(currentResquestedTriggerPressure!=newResquestedTriggerPressure){
        //target volume has changed dosomething
        currentResquestedTriggerPressure!=newResquestedTriggerPressure;
    }
    switch (currentState){
        case STATE_STARTING:{
            break;
        }
        case STATE_STOPPED:{
            break;
        }
        case STATE_RUNNING_MODE1: {
            myMode1.loop();
            break;
        }
        case STATE_RUNNING_MODE2: {
            myMode2.loop();
            break;
        }
    }

}
