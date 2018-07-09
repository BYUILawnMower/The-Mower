#!/usr/bin/env python3
from tkinter import *

#imports
import time
import RPi.GPIO as GPIO


#Set up GPIO with BCM not BOARD
GPIO.setmode(GPIO.BCM)
#GPIO.setup(35, GPIO.OUT)
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)

#Integrate this function later to light LED
def say_hi():
    print ("Lighting up LED")
 #   GPIO.output(35, GPIO.HIGH)
    #time.sleep(5)
 #   GPIO.output(35, GPIO.LOW)


#Fucntion for button push (puts notification on screen if pushed)
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
hi_there = Button(root, text="Light my LED!", command=say_hi)
hi_there.pack(side=LEFT, padx=10, pady=10, ipadx=10, ipady=10)

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
