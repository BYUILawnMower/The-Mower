import i2c

# Define the addresses of the Arduinos
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO   = 0x04
BLADE_ARDUINO   = 0x05
SENSOR_ARDUINO  = 0x06

def getUpdate():
    update = i2c.readData(SENSOR_ARDUINO)
    return update
    
