import i2c
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO   = 0x04
BLADE_ARDUINO   = 0x05
SENSOR_ARDUINO  = 0x06

def getUpdate():
    voltage1 = i2c.readData(VOLTAGE_ARDUINO)
    voltage2 = i2c.readData(VOLTAGE_ARDUINO)
    voltageCalcOne = voltage1 * (46.5 / 1023)
    voltageCalcTwo = voltage2 * (45.23 / 1023)
    print "Voltage 1: ", round(voltageCalcOne), "\n"
    print "Voltage 2: ", round(voltageCalcTwo), "\n"
    lowBattery(voltageCalcOne)
    lowBattery(voltageCalcTwo)
    

def lowBattery(voltage):
    if (voltage > 1.3):
        return True
    elif (voltage <= 1.3):
        print("LOW BATTERY, RETURN TO STATION")
        return False


