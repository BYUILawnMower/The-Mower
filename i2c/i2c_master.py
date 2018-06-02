import smbus
import time
import atexit
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
MotorAddress = 0x04

def writeNumber(value):
    bus.write_byte(MotorAddress, value)
    return -1

def readNumber():
    state = bus.read_byte(MotorAddress)
    return state

def endProgram():
    writeNumber(0)
    return -1

atexit.register(endProgram)

# 0 = stop    
# 1 = go straight
# 2 = turn left
# 3 = turn right
inc = 0
while True:
    time.sleep(1)
    state = readNumber()


    if state > 3:
        state = 0;
        print "If statement\n"    
    writeNumber(state+1)
    print state  

