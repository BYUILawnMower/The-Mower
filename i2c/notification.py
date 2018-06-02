import time
import RPi.GPIO as GPIO  

import smbus
import time

bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x06

# Setup out GPIO Interrupt
GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


def arduinoInterrupt(channel):  
    print "The arduino requests a data pull.\n"
    number = readData()
    print "Number received "
    print number
    print "\n"
    
GPIO.add_event_detect(24, GPIO.RISING, callback=arduinoInterrupt)

def writeData(value):
    bus.write_byte(address, value)
    # bus.write_byte_data(address, 0, value)
    return -1

def readData():
    number = bus.read_byte(address)
# number = bus.read_byte_data(address, 1)
    return number

while True:
    time.sleep(10)
