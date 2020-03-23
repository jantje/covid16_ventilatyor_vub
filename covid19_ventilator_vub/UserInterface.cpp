/*
 * UserInterface.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#define MAX_LCD_WRITES 1

//TODO deze arrays aanpak is niet zo goed omdat je zo 2 indirecties hebt
//verzin iets beter
#include "UserInterface.h"

UserInterface::UserInterface()
                :
                myScreen() {
    Screen myScreen();
    requestedPressure = 20 * UPLIFT;
    requestedTargetVolume = 600 * UPLIFT;
    requestedBPM = 12 * UPLIFT;
    requestedTriggerPressure = 8 * UPLIFT;
}

void UserInterface::setup() {
    myScreen.setup();
    uint8_t buttonPins[NUMBUTTONS] = {
        BUTTON_VOLUMEPRESSURE_UP,
        BUTTON_VOLUMEPRESSURE_DOWN,
        BUTTON_VOLUME_UP,
        BUTTON_VOLUME_DOWN,
        BUTTON_BPM_UP,
        BUTTON_BPM_DOWN,
        BUTTON_TRIG_UP,
        BUTTON_TRIG_DOWN,

        BUTTON_MUTE,
        BUTTOM_BREATH,
        BUTTON_MODE };

    for (unsigned int curButton = 0; curButton < NUMBUTTONS; curButton++) {
        buttons[curButton].setPin(buttonPins[curButton]);
        buttons[curButton].setup();
    }

}


void UserInterface::loop() {
    static uint32_t lastReadTime = loopMillis;
    if (loopMillis - lastReadTime > 10) {
        //read the buttons every 10 miliseconds
        lastReadTime = loopMillis;
        myScreen.loop();
        for (unsigned int curButton = 0; curButton < NUMBUTTONS; curButton++) {
            buttons[curButton].loop();
        }

        requestedPressure = requestedPressure + buttons[0].jumpValue() - buttons[1].jumpValue();
        requestedTargetVolume = requestedTargetVolume + buttons[2].jumpValue() - buttons[3].jumpValue();
        requestedBPM = requestedBPM + (buttons[4].jumpValue() - buttons[5].jumpValue()) * 5;
        requestedTriggerPressure = requestedTriggerPressure + buttons[6].jumpValue() - buttons[7].jumpValue();

        //TOFIX Set realistic minimum and maximum values
        requestedTriggerPressure=constrain(requestedTriggerPressure,0,1000*UPLIFT-1);
        requestedBPM=constrain(requestedBPM,0,1000*UPLIFT-1);
        requestedTargetVolume=constrain(requestedTargetVolume,0,1000*UPLIFT-1);
        requestedPressure=constrain(requestedPressure,0,1000*UPLIFT-1);

        static int breathHoldState =0; //0 off 1 on
        if (digitalRead(BUTTOM_BREATH) == LOW) {
         if(breathHoldState==0){
             breathHoldState=1;
             Stepper_ENABLE(false);

         }
        }else{
            if(breathHoldState==1){
                breathHoldState=0;
                Stepper_ENABLE(true);
            }
        }

        //mute the alarm if needed
        if (digitalRead(BUTTON_MUTE) == LOW) {
            myAlarm.muteAllert();
        }
        //Trigger the alarm for testing
        //TOFIX remove this code after testing
        if (digitalRead(BUTTON_MODE) == LOW) {
            myAlarm.allert(ALERT_NO_BREATHING);
        }
        int lcdWrites = 0;
        static int prefRequestedPressure = -1;
        if ((prefRequestedPressure != requestedPressure) && (lcdWrites < MAX_LCD_WRITES)) {
            myScreen.refreshValue_deci(requestedPressure, 12, 0);
            prefRequestedPressure = requestedPressure;
            lcdWrites++;
        }
        static int prefrequestedTargetVolume = -1;
        if ((prefrequestedTargetVolume != requestedTargetVolume) && (lcdWrites < MAX_LCD_WRITES)) {
            myScreen.refreshValue_deci(requestedTargetVolume, 12, 1);
            prefrequestedTargetVolume = requestedTargetVolume;
            lcdWrites++;
        }
        static int prefrequestedBPM = -1;
        if ((prefrequestedBPM != requestedBPM) && (lcdWrites < MAX_LCD_WRITES)) {
            myScreen.refreshValue_deci(requestedBPM, 12, 2);
            prefrequestedBPM = requestedBPM;
            lcdWrites++;
        }
        static int prefRequestedTriggerPressure = -1;
        if (prefRequestedTriggerPressure != requestedTriggerPressure) {
            myScreen.refreshValue_deci(requestedTriggerPressure, 12, 3);
            prefRequestedTriggerPressure = requestedTriggerPressure;
            lcdWrites++;
        }



        static int prefActualPressure = -1;
        int actualPressure=BREATHE_CONTROL_getInhalePressure()*UPLIFT;
        if ((prefActualPressure != actualPressure) && (lcdWrites < MAX_LCD_WRITES)) {
            myScreen.refreshValue_deci(actualPressure, 0, 0);
            prefActualPressure = actualPressure;
            lcdWrites++;
        }
        //TOFIX where do I get this info
        static int prefActualTargetVolume = -1;
        int actualTargetVolume=0;
        if ((prefActualTargetVolume != actualTargetVolume) && (lcdWrites < MAX_LCD_WRITES)) {
            myScreen.refreshValue_deci(actualTargetVolume, 0, 1);
            prefActualTargetVolume = actualTargetVolume;
            lcdWrites++;
        }
        static int prefActualBPM = -1;
        int actualBPM=BREATHE_getBPM()*UPLIFT;
        if ((prefActualBPM != actualBPM) && (lcdWrites < MAX_LCD_WRITES)) {
            myScreen.refreshValue_deci(actualBPM, 0, 2);
            prefActualBPM = actualBPM;
            lcdWrites++;
        }
        static int prefActualTriggerPressure = -1;
        int actualTriggerPressure=0;
        if (prefActualTriggerPressure != actualTriggerPressure) {
            myScreen.refreshValue_deci(actualTriggerPressure, 0, 3);
            prefActualTriggerPressure = actualTriggerPressure;
            lcdWrites++;
        }
    }
}

