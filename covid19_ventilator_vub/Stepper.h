/*
 * Stepper.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"
#define MAX_TIME_BETWEEN_BREATH_CYCLES 5000  //TODO this is important number !!!!
typedef enum
{
    STATE_DISABLED = 0,   //first startup of the machine
    STATE_BREATHING_IN,
    STATE_BREATH_WAIT,
    STATE_BREATHING_OUT,
    STATE_WAITING_TO_START_CYCLE
}STEPPER_STATE;

class Stepper {
    private:
        int currentSpeed;
        int newSpeed;
        bool enabled;
        STEPPER_STATE state;
        uint32_t timeSinceLastCycle;
        uint32_t stroke;
        uint32_t newStroke;
        uint8_t stepPin;
        uint8_t dirPin;
        uint8_t enablepin;
    public :
        Stepper(uint8_t stepPin,  uint8_t dirPin, uint8_t enablepin);
         void setup( );
         void loop();

         /**
          * The speed is the delay betweeen 2 steps
          * not sure this should be miliseconds or nanoseconds
          */
         int setSpeed(int speed){
             newSpeed =speed;
             return currentSpeed;
         }
         int setEnable(bool enable);

         /**
          * Tell the stepper how many steps it needs to take
          * This is for each stroke
          * stroke * 2 * speed is the time a cycle takes
          * If there is no wait time between in and out breathing
          */
         uint32_t setStroke(uint32_t stroke){
             newStroke=stroke;
             return stroke;
         };

         /**
          * Tell the stepper it should start a cycle
          * a cycle is 1 breath in and out
          */
         void startCycle();

         /**
          * tells when the last cycle has finished
          */
         uint32_t getTimeSinceLastCycle() const{
             return timeSinceLastCycle;
         }

         STEPPER_STATE getState() const{
             return state;
         }

};

extern Stepper myBagStepper;

