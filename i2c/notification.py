import time
import RPi.GPIO as GPIO  

import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x06

# Setup out GPIO Interrupt
GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


def callback24(channel):  
    print "Rising edge detected on port 24.\n"
    number = readNumber()
    print "Number received "
    print number
    print "\n"
    
GPIO.add_event_detect(24, GPIO.RISING, callback=callback24)

def writeNumber(value):
    bus.write_byte(address, value)
    # bus.write_byte_data(address, 0, value)
    return -1

def readNumber():
    number = bus.read_byte(address)
# number = bus.read_byte_data(address, 1)
    return number

while True:
    time.sleep(10)
