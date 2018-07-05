import smbus
import time

# for RPI Version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the arduino program
address = 0x08

def writeNumber(value):
    bus.write_byte(address, value)

    # bus.write_byte_data(adderss, 0, value)
    return -1

def readNumber():
    #voltage = bus.read_byte(address)
    voltage = bus.read_byte_data(address, 1)
    return voltage

def lowBattery(voltage):
    if (voltage > 1.3):
        return True
    elif (voltage <= 1.3):
        print("LOW BATTERY, RETURN TO STATION")
        return False

while True:
    var = input("Enter 'req' to obtain battery voltage: ")
    data_list = list(var)
    for i in data_list:
        writeNumber(int(ord(i)))
        time.sleep(1)

    voltage1 = readNumber()
    voltage2 = readNumber()
    voltageCalcOne = voltage1 * (46.5 / 1023)
    voltageCalcTwo = voltage2 * (45.23 / 1023)

    print ("Arduino: 12V battery: ",
           round(voltageCalcOne,2)," 24V battery: ",
           round(voltageCalcTwo,2))
    lowBattery(voltageCalcOne)
    lowBattery(voltageCalcTwo)

    writeNumber(int(0x0A))

