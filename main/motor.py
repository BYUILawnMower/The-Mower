import i2c

# Define the addresses of the Arduinos
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO   = 0x04
BLADE_ARDUINO   = 0x05
SENSOR_ARDUINO  = 0x06

# Define MOTOR_ARDUINO Commands
STOP            = 0x00
RIGHT_BUMPER    = 0x01
LEFT_BUMPER     = 0x02
FRONT_BUMPER    = 0x03
BOUNDRY         = 0x04
STRAIGHT        = 0x05

# On the timer Interrupt, this will get a status
# update from the motor arduino.
def getUpdate():
    update = i2c.readData(MOTOR_ARDUINO)
    if (update == 0x0a):
        print "Mode: Auto\n"
    if (update == 0x0b):
        print "Mode: Manual\n"

# Inform the MOTOR_ARDUINO that the boundry has
# been reached.
def boundry():
    i2c.writeData(MOTOR_ARDUINO, BOUNDRY)
    print "Boundry"
    return 0

# Inform the MOTOR_ARDUINO th right bumper was hit.
def rightBumper():
    i2c.writeData(MOTOR_ARDUINO, RIGHT_BUMPER)
    print "Right Bumper"
    return 0

# Inform the MOTOR_ARDUINO th left bumper was hit.
def leftBumper():
    i2c.writeData(MOTOR_ARDUINO, LEFT_BUMPER)
    print "Left Bumper"
    return 0
# Inform the MOTOR_ARDUINO th front bumper was hit.
def frontBumper():
    i2c.writeData(MOTOR_ARDUINO, FRONT_BUMPER)
    print "Front Bumper"
    return 0

# Tell the MOTOR_ARDUINO to stop
def stop():
    i2c.writeData(MOTOR_ARDUINO, STOP)
    print "Stop"
    return 0

# Tell the arduino to continue straight.
def driveStraight():
    i2c.writeData(MOTOR_ARDUINO, STRAIGHT)
    
