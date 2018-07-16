#!/usr/bin/env python
from Tkinter import *

#imports
import i2c
import time

#Arduino Addresses
VOLTAGE_ARDUINO = 0x03
MOTOR_ARDUINO = 0x04

#function to display Auto/Man mode on display
def modeDisplay():
    update = i2c.readData(MOTOR_ARDUINO)
    if (update == 0x0a):
        labelModeText.set("AUTO")
    if (update == 0x0b):
        labelModeText.set("MANUAL")

    #poll modeDisplay() every 10ms for main window    
    root.after(10, modeDisplay)

#function to display the Voltage readins on display
def voltDisplay():

    #get 12 Vdc from arduino, calculate 5 Vdc
    voltage1 = i2c.readData(VOLTAGE_ARDUINO)
    time.sleep(.01)
    voltageCalcOne = (voltage1 * (46.5 / 1023))
     
    #get 24 Vdc from arduino, calculate 24 Vdc
    voltage2 = i2c.readData(VOLTAGE_ARDUINO)
    time.sleep(.01)
    voltageCalcTwo = (voltage2 * (45.23 / 1023))
        
    #set voltages to labels
    labelVoltText1.set(str(round(voltageCalcOne)) + "  (12V BAT)")
    labelVoltText2.set(str(round(voltageCalcTwo)) + "  (24V BAT)")

    #poll voltDisplay() every 10ms for main window
    root.after(10, voltDisplay)

    
#Set tkinter main window
root = Tk()

#Setup Exit Button in "root" window
button = Button(root, font=("Helvetica", 20), text="Quit.", fg="red", command=quit)
button.pack(side=RIGHT, padx=45, pady=10, ipadx=10, ipady=10)

#Setup label for AUTO / MAN mode on display
labelModeText = StringVar()
label1 = Label(root, textvariable=labelModeText, font=("Helvetica", 32))
label1.pack(anchor=CENTER, expand=TRUE)

#Setup label for 12V Voltage display
labelVoltText1 = StringVar()
label2 = Label(root, textvariable=labelVoltText1, font=("Helvetica", 24))
label2.pack()

#Setup label for 24V Voltage display
labelVoltText2 = StringVar()
label3 = Label(root, textvariable=labelVoltText2, font=("Helvetica", 24))
label3.pack()               

#Window title, size and window mainloop (will always run)
root.title("BYU-I Lawn Mower App")
root.geometry('810x540')
root.after(10, modeDisplay)
root.after(10, voltDisplay)
root.mainloop()
