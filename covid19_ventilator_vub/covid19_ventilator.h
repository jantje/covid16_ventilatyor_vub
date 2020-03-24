/*
 * covid16_ventilatyor.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#pragma once
#include "Arduino.h"

typedef enum {
    STATE_STARTING = 0,   //first startup of the machine
    STATE_STOPPED,
    STATE_RUNNING_MODE1,
    STATE_RUNNING_MODE2
} MACHINE_STATE;
#include "pins.h"
#include "Button.h"
#include "Screen.h"
#include "UserInterface.h"
#include "Alarm.h"
#include "Logger.h"
#include "SerialReader.h"

//Some global variabels to track performance
extern uint32_t loopMillis;
extern uint32_t loopCounter;
extern uint32_t PrefLoopMillis;
extern uint16_t maxLoopDuration;

//Just in case we want to redirect info to another serial
extern Stream &SerialOutput;

//we work in deci internally by using this define we can easily switch to centi
#define UPLIFT  10

//methods in the beademhalings code
float BREATHE_CONTROL_getInhalePressure();
void BREATHE_CONTROL_setInhalePressure(float setting);

void BREATHE_CONTROL_setPointInhalePressure(float setting);
float BREATHE_CONTROL_getPointInhalePressure();

float BREATHE_getBPM();
float BREATHE_getPID();

void Stepper_ENABLE(bool en);
float getLastpatientPressure();

