#!/usr/bin/env python
from Tkinter import *

#imports
import i2c
import time
#import RPi.GPIO as GPIO



#Set up GPIO with BCM for button
#GPIO.setmode(GPIO.BCM)
#GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)


#Arduino Addresses
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO = 0x04
BLADE_ARDUINO = 0x05
SENSOR_ARDUINO = 0x06

#function to display voltage readings
def voltDisplay():
    update = i2c.readData(MOTOR_ARDUINO)
    if (update == 0x0a):
        labelText.set("AUTO")
    if (update == 0x0b):
        labelText.set("MANUAL")
    
    root.after(10, voltDisplay)


#Set tkinter main window
root = Tk()

#Setup Exit Button in "root" window
button = Button(root, font=("Helvetica", 20), text="Quit.", fg="red", command=quit)
button.pack(side=RIGHT, padx=45, pady=10, ipadx=10, ipady=10)

#Setup lightButton for later
#ledButton = Button(root, text='Turn LED On', command=ledToggle, bg='bisque2', height=1, width=24)
#ledButton.pack(side=LEFT, padx=10, pady=10, ipadx=10, ipady=10)

#Label (for "root" window) for incomming message when button pressed
labelText = StringVar()
label1 = Label(root, textvariable=labelText, font=("Helvetica", 32))
label1.pack(anchor=CENTER, expand=TRUE)



#Window title, size and window mainloop (will always run)
root.title("LED Blinker")
root.geometry('810x540')
root.after(10, voltDisplay)
root.mainloop()
