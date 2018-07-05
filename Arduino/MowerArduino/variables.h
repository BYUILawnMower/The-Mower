// This defines the address of this arduino on the I2C bus
#define SLAVE_ADDRESS specify_address_here

// Holds the I/O data from the I2C connection.
volatile int dataReceived = 0;
volatile int dataQueued = 0;
