#include <PinChangeInt.h>
#include <Wire.h>

#include "variables.h"

// Holds the I/O data for the I2C connection.
volatile int dataReceived = 0;
volatile int dataQueued = 0;

/***************************************************************
    This is where we are setting up all the GPIO pins and
    attaching interrupts to them. We also begin our serial
    communication and set the arduino up as a slave on the
    I2C interface.
****************************************************************/

void setup() {
  Serial.begin(9600); // start serial for output

  pinMode(PI_INTERRUPT, OUTPUT);
  pinMode(BUMPER_RIGHT, INPUT_PULLUP);
  pinMode(BUMPER_LEFT, INPUT_PULLUP);
  pinMode(BUMPER_FRONT, INPUT_PULLUP);
  pinMode(BOUNDRY_WIRE, INPUT_PULLUP);

  pinMode(COLLAR_POWER, OUTPUT);

  // using the PinChangeInt library, attach the interrupts
  // used to read the channels
  PCintPort::attachInterrupt(BUMPER_RIGHT, rightBumperISR, FALLING);
  PCintPort::attachInterrupt(BUMPER_LEFT, leftBumperISR, FALLING);
  PCintPort::attachInterrupt(BUMPER_FRONT, frontBumperISR, FALLING);
  PCintPort::attachInterrupt(BOUNDRY_WIRE, boundryWireISR, CHANGE);

  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  setUpTimerISR();
}

/***************************************************************
  Everything works on interrupts, so there is nothing to be done
  in the main loop.
****************************************************************/

void loop() {
  boundryWireISR();
}




