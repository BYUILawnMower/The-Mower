import smbus

# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

#
def writeData(address, value):
    try:
        bus.write_byte(address, value)
        success = True
    except:
        print "Could not write to arduino ", address, "\n"
    return -1

def readData(address):
    try:
        state = bus.read_byte(address)     
    except:
        print "Could not read from arduino ", address, "\n"
        state = 0  
    return state
