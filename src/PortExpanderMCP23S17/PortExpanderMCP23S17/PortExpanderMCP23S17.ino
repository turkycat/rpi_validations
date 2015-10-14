/*
MCP23S17 Class Example
Cort Buffington 2011

This example will use the methods in "bit mode", that is, writing/reading/setting
bit at a time. Also note that on the inputs, we use the internal pull-up
resistors and an SPST button to ground when the button is pushed. While this uses
simpler (less expensive) pushbuttons, it does invert the logic. This is a perfect
example of one of the more advanced features of the MCP23S17 where we can invert
the logic state of the input pins. So, when a button is closed, we read a logic
low state, but the chip will report it as a logic high.

In the example, we'll set up two chips, one as an input and one as an output. We
will read the input chip, then write the input pin states to the output chip. This
is a completely useless program in the real world, but it demonstrates the
abilities of this class well, and makes a simple example.

A few things are done less efficiently than possible to make the sketch easier to
follow. In the hardware setup I used to write this example, I set up 2 x 8 position
DIP switches on the input chip, and 16 LEDs on the output chip.

Be sure to see the companion example that demonstrates the same funcionality with
the methods being used in "word mode", which is significantly more efficient if you
need to read or write an entire word at one time.
*/

#include <SPI.h>              // We use this library, so it must be called here.
#include <MCP23S17.h>         // Here is the new class to make using the MCP23S17 easy.

uint8_t spi_cs = GPIO_8;        //pin 24 aka GPIO_8 is SPI CS 0
uint8_t hardware_address = 0;

MCP23S17 chip( &SPI, spi_cs, hardware_address );             // Instantiate an object called "chip" on an MCP23S17 device at address 1

void setup() {
    chip.begin();
    
    //chip.pinMode( 8, OUTPUT );
    chip.pinMode( 8, INPUT );
}

void loop() {
    //for( int i = 1; i <= 16; i++ ) {       // Step through each of the 16 pins on the I/O chips
    //    int value;                         // declare an integer to hold the value temporarily.
    //    value = chip.digitalRead( i );  // read the input chip in bit-mode, storing the result for bit "i" in "value"
    //    outputchip.digitalWrite( i, value ); // write the output chip in bit-mode, using our variable "value" as the argument for bit "i"
    //                                         // outputchip.digitalWrite(i, chip.digitalRead(i)) // this one line replaces everything above except the for loop, and is more efficient
    //}

    if( chip.digitalRead( 8 ) == LOW )
        Log( "Low" );
    else
        Log( "High" );

    /*chip.digitalWrite( 8, HIGH );
    delay( 500 );
    chip.digitalWrite( 8, LOW );*/
    delay( 500 );
}
