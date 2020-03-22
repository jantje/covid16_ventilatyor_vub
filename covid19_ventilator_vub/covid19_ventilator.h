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
#include "pins.h"
#include "Button.h"
#include "Screen.h"
#include "UserInterface.h"
#include "Alarm.h"
#include "Logger.h"
#include "SerialReader.h"

extern uint32_t loopMillis;
extern uint32_t loopCounter ;
extern uint32_t PrefLoopMillis ;
extern uint16_t maxLoopDuration ;
extern Stream &SerialOutput ;



