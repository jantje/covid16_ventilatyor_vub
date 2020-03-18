
#include "covid16_ventilatyor.h"
#define BAG_STEPPER_PIN      4
#define BAG_STEPPER_DIR_PIN  5
#define BAG_STEPPER_ENABLE_PIN 6


MACHINE_STATE currentState=STATE_STARTING;
MACHINE_STATE newState=STATE_STARTING;

Mode1 myMode1;
Mode2 myMode2;
Brains myBrains;
Stepper myBagStepper(BAG_STEPPER_PIN,  BAG_STEPPER_DIR_PIN, BAG_STEPPER_ENABLE_PIN);

Stream &SerialOutput = Serial;

void setup()
{
    SerialOutput.print(F("Starting ventilator\myMode1.setup() "));
    myMode1.setup();
    SerialOutput.print(F("done\mode2.setup() "));
    myMode2.setup();
    SerialOutput.print(F("done\myBrains.setup() "));
    myBrains.setup();
    SerialOutput.print(F("done\myBagStepper.setup() "));
    myBagStepper.setup();
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
         myMode1.loop();
         break;
     }
     case STATE_RUNNING_MODE2: {
         myMode2.loop();
         break;
     }
 }
}
