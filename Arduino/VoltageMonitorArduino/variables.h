// This defines the address of this arduino on the I2C bus
#define SLAVE_ADDRESS 0x03

// Define the pins for the two battery connections
#define POWER_PIN_1 A0 // 12V Battery
#define POWER_PIN_2 A1 // 24V Battery

// Holds the I/O data from the I2C connection.
volatile int dataReceived = 0;
volatile int dataQueued = 0;

// The variables that are used in the voltage reading function.
char voltage[50];
int state = 0;
byte power1 = 0;
byte power2 = 0;
