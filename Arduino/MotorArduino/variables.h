// This defines the address of this arduino on the I2C bus
#define SLAVE_ADDRESS   0x04

// Channel pins from the RF controller
#define THROTTLE_IN_PIN 8
#define STEERING_IN_PIN 9
#define AUX_IN_PIN      10
#define BLADE_IN_PIN    11

// These bit flags are set in updateFlagShared to indicate which
// channels have new signals
#define THROTTLE_FLAG   1 // 0b0001
#define STEERING_FLAG   2 // 0b0010
#define AUX_FLAG        4 // 0b0100
#define BLADE_FLAG      8 // 0b1000

// holds the update flags defined above
volatile uint8_t updateFlagShared;

//These will take a sample copy of these values from the ISR
// and store them local so that we can turn the interrupts back on ASAP.
volatile uint16_t ThrottleShared = 0;
volatile uint16_t SteeringShared = 0;
volatile uint16_t AuxShared      = 0;
volatile uint16_t BladeShared    = 0;


// These are used to record the rising edge of a pulse in the calcInput functions
// They do not need to be volatile as they are only used in the ISR. If we wanted
// to refer to these in loop and the ISR then they wod need to be declared volatile
uint32_t ThrottleStart;
uint32_t SteeringStart;
uint32_t AuxStart;
uint32_t BladeStart;


