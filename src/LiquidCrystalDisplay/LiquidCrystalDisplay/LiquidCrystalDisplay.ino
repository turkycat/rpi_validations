#include <LiquidCrystal.h>

int enablePin = GPIO_26;
int registerSelectPin = GPIO_20;
int dataPin11 = GPIO_2;
int dataPin12 = GPIO_3;
int dataPin13 = GPIO_4;
int dataPin14 = GPIO_5;

//create a pointer to an instance of LiquidCrystal, yet to be created
LiquidCrystal *lcd;

void setup() {
    //create the LiquidCrystal instance with the pins as set
    lcd = new LiquidCrystal( registerSelectPin, enablePin, dataPin11, dataPin12, dataPin13, dataPin14 );

    // set up the LCD's number of columns and rows:
    lcd->begin( 16, 2 );

    // Print a message to the LCD.
    lcd->print( "hello, world!" );
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd->setCursor( 0, 1 );

    // print the number of seconds since reset:
    lcd->print( millis() / 1000 );
}