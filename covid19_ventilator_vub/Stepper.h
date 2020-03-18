/*
 * Stepper.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "covid19_ventilator.h"
#define MAX_TIME_BETWEEN_BREATH_CYCLES 5000  //TODO this is important number !!!!
#define MAXMOVESPEED 500                     //TODO validate this number
#define TIME_BREATH_WAIT 500                  //TODO validate this number
typedef enum
{
    STATE_DISABLED = 0,   //first startup of the machine
    STATE_STARTING_UP,    //Machine is in unknown location
    STATE_BREATHING_IN,   //machine is providing air
    STATE_BREATH_WAIT,     //machine is waiting for patient to suck up air
    STATE_BREATHING_OUT,   //machine is returning to start position
    STATE_WAITING_TO_START_CYCLE //machine is waiting to do the next cycle
}STEPPER_STATE;

class Stepper {
    private:
        int currentSpeed;
        int newSpeed;
        uint16_t actualSpeed;
        bool curentEnabled;
        bool newEnabled;
        STEPPER_STATE state;
        STEPPER_STATE nextState;
        uint32_t timeStartLastCycle;
        uint32_t timeLastPinHigh;
        uint32_t lastStateChange;
        uint32_t stroke;
        uint32_t newStroke;
        uint8_t stepPin;
        uint8_t dirPin;
        uint8_t enablepin;
        int numSteps;
        uint8_t stepPinStatus;
        void switchToState(STEPPER_STATE state);
        void startStepping(int speed);
        void stopStepping(){startStepping(0);}
        void doStep();
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
         int setEnable(bool enable){
             newEnabled=curentEnabled;
         }

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
          * Will fail if the stepper is not in the right position or
          * disabled
          *
          * returns false if the cycle cannot be started else true
          */
         bool startCycle();

         /**
          * tells when the last cycle has started
          */
         uint32_t getTimeLastCycle() const{
             return timeStartLastCycle;
         }

         STEPPER_STATE getState() const{
             return state;
         }

};

extern Stepper myBagStepper;

