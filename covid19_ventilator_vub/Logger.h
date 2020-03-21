/*
 * Logger.h
 *
 *  Created on: 21 mrt. 2020
 *      Author: gast1
 */
#pragma once
#include "covid19_ventilator.h"



class Logger {
	uint32_t setupMillis;

public :
	Logger(){};
     void setup();
     void loop();
};

extern Logger myLogger;
extern Stream &SerialOutput;
