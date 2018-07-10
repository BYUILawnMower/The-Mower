#!/usr/bin/env python3
from tkinter import *

#imports
import time
import RPi.GPIO as GPIO
from gpiozero import LED


#Set up GPIO with BCM for button
GPIO.setmode(GPIO.BCM)
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)

#Set LED output with gpiozero lib
led=LED(21)

#LED turn on/off function
def ledToggle():
    if led.is_lit:
        led.off()
        ledButton["text"]="Turn LED On"
    else:
        led.on()
        ledButton["text"]="Turn LED Off"

#function for button press
def check_button():
    if (GPIO.input(26) == GPIO.LOW):
        labelText.set("Button Pressed.")
    else:
        labelText.set("")

    #loop for checking button push every 10ms
    root.after(10, check_button)


    
#Set tkinter main window
root = Tk()

#Setup Exit Button in "root" window
button = Button(root, text="Quit.", fg="red", command=quit)
button.pack(side=RIGHT, padx=10, pady=10, ipadx=10, ipady=10)

#Setup lightButton for later
ledButton = Button(root, text='Turn LED On', command=ledToggle, bg='bisque2', height=1, width=24)
ledButton.pack(side=LEFT, padx=10, pady=10, ipadx=10, ipady=10)

#Label (for "root" window) for incomming message when button pressed
labelText = StringVar()
labelText.set("Button Pressed.")
label1 = Label(root, textvariable=labelText, height=4)
label1.pack(side=LEFT)

#Window title, size and window mainloop (will always run)
root.title("LED Blinker")
root.geometry('810x540')
root.after(10, check_button)
root.mainloop()
