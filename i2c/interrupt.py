
import time
import RPi.GPIO as GPIO  
GPIO.setmode(GPIO.BCM)  
  

GPIO.setup(24, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)  
  
# now we'll define the threaded callback function  
# this will run in another thread when our event is detected  
def callback24(channel):  
    print "Rising edge detected on port 24.\n"
  
print "Waiting for interrupt"
  
 
GPIO.add_event_detect(24, GPIO.RISING, callback=callback24)

while True:
    time.sleep(5)
    
GPIO.cleanup()           # clean up GPIO on normal exit 
