/***************************************************************
     When the Right Bumper ISR is triggered, this function will
     write the status code to the data queue and request a
     data pull from the Raspberry Pi.
****************************************************************/

void rightBumperISR(void) {
  if (sensorUpdateFlag & BUMPER_RIGHT)
  {
    dataQueued = 0x01;
    requestDataPull();
    Serial.println ("Right Bumper");
    sensorUpdateFlag &= ~BUMPER_RIGHT;
  }

}

/***************************************************************
     When the Left Bumper ISR is triggered, this function will
     write the status code to the data queue and request a
     data pull from the Raspberry Pi.
****************************************************************/

void leftBumperISR(void) {
  if (sensorUpdateFlag & BUMPER_LEFT)
  {
    dataQueued = 0x02;
    requestDataPull();
    Serial.println ("Left Bumper");
    sensorUpdateFlag &= ~BUMPER_LEFT;
  }
}

/***************************************************************
     When the Front Bumper ISR is triggered, this function will
     write the status code to the data queue and request a
     data pull from the Raspberry Pi.
****************************************************************/

void frontBumperISR(void) {
  if (sensorUpdateFlag & BUMPER_FRONT)
  {
    dataQueued = 0x03;
    requestDataPull();
    Serial.println ("Front Bumper");
    sensorUpdateFlag &= ~BUMPER_FRONT;
  }
}

/***************************************************************
     When the boundry wire ISR is triggered, this function will
     write the status code to the data queue and request a
     data pull from the Raspberry Pi.
****************************************************************/

void boundryWireISR(void) {
  float voltage;
  if (sensorUpdateFlag & BOUNDRY_WIRE)
  {
    int readValue = analogRead(BOUNDRY_WIRE); //check the signal wire
    voltage = (5.0 / 1023.0) * readValue;     //Convert to value to voltage
    if (voltage > 2)
    {
      dataQueued = 0x04;
      requestDataPull();
      Serial.println ("Boundry Wire");
      sensorUpdateFlag &= ~BOUNDRY_WIRE;
    }
  }

}

/***************************************************************
    Whenever a sensor is triggered, this function will notify
    the pi that it needs to pull data from this arduino.
****************************************************************/
void requestDataPull(void) {
  digitalWrite(PI_INTERRUPT, HIGH);
  digitalWrite(PI_INTERRUPT, LOW);
}


