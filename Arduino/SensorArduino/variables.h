// This defines the address of this arduino on the I2C bus
#define SLAVE_ADDRESS 0x06

// Define the input pins
#define BUMPER_RIGHT 2
#define BUMPER_LEFT 3
#define BUMPER_FRONT 4
#define BOUNDRY_WIRE A7
#define COLLAR_POWER 6

// Define the update flag bits
#define BUMPER_ONE_FLAG 1   // 0b0001
#define BUMPER_TWO_FLAG 2   // 0b0010
#define BUMPER_THREE_FLAG 4 // 0b0100
#define BOUNDRY_WIRE_FLAG 8 // 0b1000

// Define output pin
#define PI_INTERRUPT 5

// Define the senesor update flag.
volatile uint8_t sensorUpdateFlag;

// holds the update flags defined above
volatile uint8_t updateFlagShared;

//These will take a sample copy of these values from the ISR
// and store them local so that we can turn the interrupts back on ASAP.
volatile uint16_t BumperOneShared;
volatile uint16_t BumperTwoShared;
volatile uint16_t BumperThreeShared;
volatile uint16_t BoundryWireShared;

// These are used to record the rising edge of a pulse in the calcInput functions
// They do not need to be volatile as they are only used in the ISR. If we wanted
// to refer to these in loop and the ISR then they wod need to be declared volatile
uint32_t BumperOneStart;
uint32_t BumperTwoStart;
uint32_t BumperThreeStart;
uint32_t BoundryWireStart;




