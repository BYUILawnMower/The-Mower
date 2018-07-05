#include <Wire.h>
#include "variables.h"


void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);            // join i2c bus with address #8
  Wire.onReceive(receiveData);
  Wire.onRequest(voltageRead);         // register event
  // Set up timer Interrupt
  
}

void loop() {
  // Do nothing
}
