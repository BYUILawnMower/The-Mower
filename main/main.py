#!/usr/bin/env python
import atexit
import blade
import i2c
import notification
import motor
import sensor
import sys
import time
import voltage

# Define the addresses of the Arduinos
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO   = 0x04
BLADE_ARDUINO   = 0x05
SENSOR_ARDUINO  = 0x06


while True:
    try:
        motor.driveStraight()
        time.sleep(1)

    except KeyboardInterrupt:
        motor.stop()
        print "\nClosing Program\n"
        sys.exit(0)
