/*
 * covid16_ventilatyor.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#pragma once


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
