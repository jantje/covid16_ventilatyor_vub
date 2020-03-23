/*
 * Beademinglus.ino
 *
 *  Created on: 23 mrt. 2020
 *      Author: jan
 */
#ifndef  SERIAL_TX_BUFFER_SIZE

void beademing_loop();
void beademing_setup();
void setup() {
    Serial.begin(115200);
    beademing_setup();
}

void beademing_loop() {
    beademing_loop();
}
#endif
