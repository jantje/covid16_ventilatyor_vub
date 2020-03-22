/*
 * SerialReader.h
 *
 *  Created on: 22 mrt. 2020
 *      Author: gast1
 */

#pragma once
#include "SerialStringReader.h"

class SerialReader {
	SerialStringReader myReader;
public:
	SerialReader();
     void setup();
     void loop();
};

extern SerialReader mySerialReader;

