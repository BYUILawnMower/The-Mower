/***************************************************************
  To be filled in
****************************************************************/

void pwmRead(void) {
  // create local variables to hold a local copies of the channel inputs
  // these are declared static so that thier values will be retained
  // between calls to loop.
  static uint16_t Throttle;
  static uint16_t Steering;
  static uint16_t Aux;
  static uint16_t Blade;

  // local copy of update flags
  static uint8_t updateFlag;

  // check shared update flags to see if any channels have a new signal
  if (updateFlagShared)
  {
    noInterrupts(); // turn interrupts off quickly while we take local copies of the shared variables

    // take a local copy of which channels were updated in case we need to use this in the rest of loop
    updateFlag = updateFlagShared;

    if (updateFlag & THROTTLE_FLAG)
    {
      Throttle = ThrottleShared;
    }

    if (updateFlag & STEERING_FLAG)
    {
      Steering = SteeringShared;
    }

    if (updateFlag & AUX_FLAG)
    {
      Aux = AuxShared;
      //chooseInput(AuxShared);
    }

    if (updateFlag & BLADE_FLAG)
    {
      Blade = BladeShared;
    }

    // clear shared copy of updated flags as we have already taken the updates
    // we still have a local copy if we need to use it in updateFlag
    updateFlagShared = 0;

    interrupts(); // we have local copies of the inputs, so now we can turn interrupts back on
    // as soon as interrupts are back on, we can no longer use the shared copies, the interrupt
    // service routines own these and could update them at any time. During the update, the
    // shared copies may contain junk. Luckily we have our local copies to work with.

  }
  // Clear the update flag
  updateFlag = 0;

}


