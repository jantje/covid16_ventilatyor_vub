/*
 * Brains.h
 *
 *  Created on: 18 mrt. 2020
 *      Author: jan
 */

#ifndef BRAINS_H_
#define BRAINS_H_

class Brains {
    private:
        int currentRequestedPressure;
        int currentRequestedTargetVolume;
        int currentRequestedBPM;
        int currentResquestedTriggerPressure;
    public :
        Brains();
         void setup();
         void loop();
};

#endif /* BRAINS_H_ */
