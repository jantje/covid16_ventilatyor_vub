#include "covid19_ventilator.h"

UserInterface myUserInterface;
Alarm myAlarm(ALARMPIN);

Stream &SerialOutput = Serial;

uint32_t loopMillis;
uint32_t loopCounter = 0;
uint32_t PrefLoopMillis = loopMillis;
uint16_t maxLoopDuration = 0;


void setup() {
	Serial.begin(115200);
	SerialOutput.print(F("Starting ventilator\nmyUserInterface.setup() "));
	myUserInterface.setup();
	SerialOutput.print(F("done\nmyAlarm.setup() "));
	myAlarm.setup();
	SerialOutput.print(F("done\nmyLogger.setup() "));
	myLogger.setup();
	SerialOutput.println(F("done\nmySerialReader"));
	mySerialReader.setup();
	//TOFIX when sensors are not connected go into alarm instead of blocking
	SerialOutput.println(F("done\nbeademing"));
	beademing_setup();
	SerialOutput.println(F("done\nSetup Done"));
	digitalWrite(HIGH_PIN_PRESSURE_SENSOR,HIGH);

}

// The loop function is called in an endless loop
void loop() {
	loopMillis = millis();
	uint16_t LastloopDuration = loopMillis - PrefLoopMillis;
	maxLoopDuration = max(maxLoopDuration, LastloopDuration);
	PrefLoopMillis = loopMillis;
	loopCounter++;

	beademing_loop();

	if (millis() - loopMillis <= 2) {
		myAlarm.loop();
	}
	if (millis() - loopMillis <= 2) {
		myUserInterface.loop();
	}

	if (millis() - loopMillis <= 2) {
		myLogger.loop();
	}
	if (millis() - loopMillis <= 2) {
		mySerialReader.loop();
	}

}
