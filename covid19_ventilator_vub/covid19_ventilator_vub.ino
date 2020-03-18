#include "Arduino.h"
#include "covid16_ventilatyor.h"
#include "Mode1.h"
#include "Mode2.h"


MACHINE_STATE currentState=STATE_STARTING;
MACHINE_STATE newState=STATE_STARTING;
int currentPressure;
int currentTargetVolume;
int currentBPM;
int currentTriggerPressure;
Mode1 mode1;
Mode2 mode2;

void setup()
{
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop()
{
 switch (currentState){
     case STATE_STARTING:{
         break;
     }
     case STATE_STOPPED:{
         break;
     }
     case STATE_RUNNING_MODE1: {
         mode1.loop();
         break;
     }
     case STATE_RUNNING_MODE2: {
         mode2.loop();
         break;
     }
 }
}
