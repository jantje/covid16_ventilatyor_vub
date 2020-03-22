
#include "covid19_ventilator.h"







UserInterface myUserInterface;
Sensors mySensors(1,2);
Alarm myAlarm(ALARMPIN);


Stream &SerialOutput = Serial;


uint32_t loopMillis;

void setup()
{
    Serial.begin(115200);
    SerialOutput.print(F("Starting ventilator\nmyUserInterface.setup() "));
    myUserInterface.setup();
    SerialOutput.print(F("done\nmySensors.setup() "));
    mySensors.setup();
    SerialOutput.print(F("done\nmyAlarm.setup() "));
    myAlarm.setup();
    SerialOutput.print(F("done\nmyLogger.setup() "));
    myLogger.setup();
    SerialOutput.println(F("done\nmyLogger Done"));
    //TOFIX when sensors are not connected go into alarm instead of blocking
    //beademing_setup();
    SerialOutput.println(F("done\nSetup Done"));
}

// The loop function is called in an endless loop
void loop()
{
    loopMillis=millis();
    //TOFIX enable when done
    //beademing_loop();
    myAlarm.loop();
    mySensors.loop();
    myUserInterface.loop();
    myLogger.loop();

}
