import i2c
import motor
import RPi.GPIO as GPIO  
import sensor
import smbus
import time
import voltage

# Define interrupt status codes.
ERROR_STOP      = 0x00
RIGHT_BUMP      = 0x01
LEFT_BUMP       = 0x02
FRONT_BUMP      = 0x03
BOUNDRY         = 0x04
TIMER           = 0x05

# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO   = 0x04
BLADE_ARDUINO   = 0x05
SensorArduino   = 0x06

# Setup GPIO Interrupt pin
GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

# When an interrupt signal is received from the
# sensor arduino, this function will pull the status
# code from the said arduino and respond accordingly.
def arduinoInterrupt(channel):  
    interruptData =i2c.readData(SensorArduino)
          
    if (interruptData == TIMER):      # 0x05
        voltage.getUpdate()
        motor.getUpdate()
        sensor.getUpdate()
    if (interruptData == BOUNDRY):    # 0x04
        motor.boundry()
    if (interruptData == FRONT_BUMP): # 0x03
        motor.frontBumper()
    if (interruptData == RIGHT_BUMP): # 0x02
        motor.rightBumper()
    if (interruptData == LEFT_BUMP):  # 0x01
        motor.leftBumper()
    if (interruptData == ERROR_STOP): # 0x00
        motor.stop()
   
    
       
GPIO.add_event_detect(24, GPIO.RISING, callback=arduinoInterrupt)



 
