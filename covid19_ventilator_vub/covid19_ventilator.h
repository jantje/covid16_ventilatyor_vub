/*
 * covid16_ventilatyor.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#pragma once
#include "Arduino.h"


typedef enum
{
    STATE_STARTING = 0,   //first startup of the machine
    STATE_STOPPED,
    STATE_RUNNING_MODE1,
    STATE_RUNNING_MODE2
}MACHINE_STATE;

#include "Stepper.h"
#include "Mode1.h"
#include "Mode2.h"
#include "Brains.h"
#include "Screen.h"
#include "ButtonControler.h"
#include "Sensors.h"
#include "UserInterface.h"
#include "Alarm.h"

extern uint32_t loopMillis;
extern Stream &SerialOutput ;



