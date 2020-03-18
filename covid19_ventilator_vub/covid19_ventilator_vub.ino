
#include "covid19_ventilator.h"
#define BAG_STEPPER_PIN     (uint8_t) 4
#define BAG_STEPPER_DIR_PIN  (uint8_t) 5
#define BAG_STEPPER_ENABLE_PIN (uint8_t) 6

#define SDA_PIN A4
#define SDL_PIN 45





Brains myBrains;
Stepper myBagStepper(BAG_STEPPER_PIN,  BAG_STEPPER_DIR_PIN, BAG_STEPPER_ENABLE_PIN);
Screen myScreen(SDA_PIN,SDL_PIN);
ButtonControler myButtonControler(1,2,3);
UserInterface myUserInterface(myButtonControler,myScreen);
Sensors mySensors(1,2);

Stream &SerialOutput = Serial;

void setup()
{
    SerialOutput.print(F("Starting ventilator\nmyUserInterface.setup() "));
    myUserInterface.setup();
    SerialOutput.print(F("done\nmyBrains.setup() "));
    myBrains.setup();
    SerialOutput.print(F("done\nmyBagStepper.setup() "));
    myBagStepper.setup();
    SerialOutput.print(F("done\nmySensors.setup() "));
    mySensors.setup();
}

// The loop function is called in an endless loop
void loop()
{
    mySensors.loop();
    myUserInterface.loop();
    myBrains.loop();


}
