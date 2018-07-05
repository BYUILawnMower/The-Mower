#include <PinChangeInt.h>
#include <Wire.h>
#include "variables.h"

// Holds the I/O data from the I2C connection.
volatile int dataReceived = 0;
volatile int dataQueued = 0;

/***************************************************************
     To be filled in
****************************************************************/

void setup() {
  Serial.begin(9600); // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);


  // using the PinChangeInt library, attach the interrupts
  // used to read the channels
  PCintPort::attachInterrupt(THROTTLE_IN_PIN, calcThrottle, CHANGE);
  PCintPort::attachInterrupt(STEERING_IN_PIN, calcSteering, CHANGE);
  PCintPort::attachInterrupt(AUX_IN_PIN, calcAux, CHANGE);
  PCintPort::attachInterrupt(BLADE_IN_PIN, calcBlade, CHANGE);
}

/***************************************************************
     To be filled in
****************************************************************/

void loop()
{
  pwmRead();
  chooseInput();
  
  
  
  /*
    if the sabertooth can continue without continous updates
      do nothing here, but fill in the update sabertooth function

    if it needs continual updates
      write to the sabertooth
  */
}



