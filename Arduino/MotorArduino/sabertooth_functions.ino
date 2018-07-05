// If set to 1 it will turn off the serial writes to the sabertooth and write to the serial
// monitor instead. In normal operation it will be set to 0.
#define DEVELOPMENT 0

/***************************************************************
    This function will base its output from the Aux channel on
    the RF remote. If the switch is low, or there is no input
    from the controller is will
****************************************************************/
void chooseInput() {
  if (AuxShared > 1500)
  {
    RF_updateSabertooth();
    dataQueued = 0x0b;
  }
  else
  {
    PI_updateSabertooth();
    dataQueued = 0x0a;
  }
}

/***************************************************************
  This function takes the MOTOR_ARDUINO command from the
  Raspberry Pi and will call the corrisponing function(s).
****************************************************************/
void PI_updateSabertooth(void) {
  switch (dataReceived) {
    case 0:
      Stop();
      break;
    case 1:
      turnLeft();
      driveStraight();
      break;
    case 2:
      turnRight();
      driveStraight();
      break;
    case 3:
      boundry();
      break;
    default:
      driveStraight();
  }
}

/***************************************************************
    This function will call the left and right RF functions.
****************************************************************/

void RF_updateSabertooth(void) {
  RF_right();
  RF_left();
}


/***************************************************************
  This function will take the value of the PWM input signal from
  the RF controller and map it to a value between 128 and 255.
  This value can then be recognized by the sabertooth.
****************************************************************/

void RF_right()
{
  //                     value,inLo,inHi,OutLo,OutHi
  int right = map(SteeringShared, 960, 2000, 255, 128);


  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (!DEVELOPMENT)
  {
    Serial.write(right);
  }
}

/***************************************************************
  This function will take the value of the PWM input signal from
  the RF controller and map it to a value between 1 and 127.
  This value can then be recognized by the sabertooth.
****************************************************************/

void RF_left()
{
  //                       value,inLo,inHi,OutLo,OutHi
  int left =  map(ThrottleShared, 960, 2000, 127, 1);

  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (!DEVELOPMENT)
  {
    Serial.write(left);
  }
}

/***************************************************************
  This function will write a 0 to the sabertooth which will stop
  both motors.
****************************************************************/

void Stop()
{
  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (!DEVELOPMENT)
  {
    Serial.write(0);
  }
}

/***************************************************************
  This function is called from the Raspberry Pi, and will turn
  the mower to the right approximately 120 degrees and then
  continue forward.
****************************************************************/

void turnRight() {
  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (DEVELOPMENT)
  {
    Serial.println("Right");
  }
  Stop();
  delay(1000);
  writeToSabertooth(5, -5);
  delay(2000);
  driveStraight();

}

/***************************************************************
  This function is called from the Raspberry Pi, and will turn
  the mower to the left approximately 120 degrees and then
  continue forward.
****************************************************************/

void turnLeft() {
  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (DEVELOPMENT)
  {
    Serial.println("Left");
  }
  Stop();
  delay(1000);
  writeToSabertooth(-5, 5);
  delay(2000);
  driveStraight();
}

/***************************************************************
  This function is called from the Raspberry Pi, and will back
  the mower up and turn it to the right approximately 120 degrees
  and then continue forward.
****************************************************************/

void boundry() {
  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (DEVELOPMENT)
  {
    Serial.println("Backup");
  }
  Stop();
  delay(1000);
  writeToSabertooth(-5, -5);
  delay(2000);
  turnRight();

}

/***************************************************************
  This function will have the mower drive forward.
****************************************************************/

void driveStraight(void) {
  writeToSabertooth(7, 7);
}


/***************************************************************
  This function will take a number between -10 and 10 for the
  left wheel, and the right wheel and convert it to the corrisponding
  value that the sabertooth can then interperet.
****************************************************************/

void writeToSabertooth(int leftIn, int rightIn) {
  int right = map(rightIn, -10, 10, 255, 128);
  int left =  map(leftIn, -10, 10, 127, 1);

  // If Development mode is enabled, the sabertooth serial output
  // is disabled so the serial monitor can be used.
  if (!DEVELOPMENT)
  {
    Serial.write(right);
    Serial.write(left);
  }
}





