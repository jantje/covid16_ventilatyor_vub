/*
 * ButtonControler.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */
#pragma once
#include "Arduino.h"

class ButtonControler {
    public :
        ButtonControler(uint8_t button1pin,  uint8_t button2pin, uint8_t button3pin);
         void setup( );
         void loop();

};


