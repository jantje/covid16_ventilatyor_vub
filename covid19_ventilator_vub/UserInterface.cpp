/*
 * UserInterface.cpp
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#include "UserInterface.h"

UserInterface::UserInterface(ButtonControler &buttonControler, Screen &screen) {
}

void UserInterface::setup() {
    myScreen.setup();
    myButtonControler.setup();
}

void UserInterface::loop() {
    myScreen.loop();
    myButtonControler.loop();

}
