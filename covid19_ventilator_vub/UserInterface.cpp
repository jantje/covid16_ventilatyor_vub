/*
 * UserInterface.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "UserInterface.h"

UserInterface::UserInterface(ButtonControler &buttonControler, Screen &screen)
                :
                myButtonControler(buttonControler), myScreen(screen) {
    requestedPressure = 0;
    requestedTargetVolume = 0;
    requestedBPM = 0;
    requestedTriggerPressure = 0;
}

void UserInterface::setup() {
    myScreen.setup();
    myButtonControler.setup();
}

void UserInterface::loop() {
    myScreen.loop();
    myButtonControler.loop();

}
