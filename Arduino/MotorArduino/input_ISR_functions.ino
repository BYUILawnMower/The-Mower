
/***************************************************************
  This function will 
****************************************************************/

void calcThrottle()
{
  // if the pin is high, its a rising edge of the signal pulse, so lets record its value
  if (digitalRead(THROTTLE_IN_PIN) == HIGH)
  {
    ThrottleStart = micros();
  }
  else
  {
    // else it must be a falling edge, so lets get the time and subtract the time of the rising edge
    // this gives use the time between the rising and falling edges i.e. the pse duration.
    ThrottleShared = (uint16_t)(micros() - ThrottleStart);

    // use set the throttle flag to indicate that a new throttle signal has been received
    updateFlagShared |= THROTTLE_FLAG;
  }
}

/***************************************************************
  To be filled in
****************************************************************/

void calcSteering()
{
  if (digitalRead(STEERING_IN_PIN) == HIGH)
  {
    SteeringStart = micros();
  }
  else
  {
    SteeringShared = (uint16_t)(micros() - SteeringStart);
    updateFlagShared |= STEERING_FLAG;
  }
}

/***************************************************************
  To be filled in
****************************************************************/

void calcAux()
{
  if (digitalRead(AUX_IN_PIN) == HIGH)
  {
    AuxStart = micros();
  }
  else
  {
    AuxShared = (uint16_t)(micros() - AuxStart);
    updateFlagShared |= AUX_FLAG;
  }
}

void calcBlade()
{
  if (digitalRead(BLADE_IN_PIN) == HIGH)
  {
    BladeStart = micros();
  }
  else
  {
    BladeShared = (uint16_t)(micros() - BladeStart);
    updateFlagShared |= BLADE_FLAG;
   
  }
}

