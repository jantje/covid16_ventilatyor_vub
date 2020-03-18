/*
 * covid16_ventilatyor.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#pragma once
#include "Arduino.h"
#include "Stepper.h"
#include "Mode1.h"
#include "Mode2.h"
#include "Brains.h"

typedef enum
{
    STATE_STARTING = 0,   //first startup of the machine
    STATE_STOPPED,
    STATE_RUNNING_MODE1,
    STATE_RUNNING_MODE2
}MACHINE_STATE;

extern int currentPressure;
extern int currentTargetVolume;
extern int currentBPM;
extern int currentTriggerPressure;
