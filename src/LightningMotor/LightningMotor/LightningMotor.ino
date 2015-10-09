
/*
Stepper Motor Control - one revolution

This program drives a unipolar or bipolar stepper motor.
The motor is attached to digital pins 8 - 11 of the Arduino.

The motor should revolve one revolution in one direction, then
one revolution in the other direction.


Created 11 Mar. 2007
Modified 30 Nov. 2009
by Tom Igoe

*/

#include <Stepper.h>


/*

Example sketch 10

SPINNING A MOTOR

Use a transistor to spin a motor at different speeds.
We'll also show you how to input data from the serial port
(see the serialSpeed() function below).

Motors are the basis for thousands of things in our daily lives,
and the Arduino can control them. Here we'll use pulse-width
modulation (PWM) to vary the speed of a motor.

The Arduino pins are strong enough to light small LEDs (up to
40 milliAmps), but they're not strong enough to run motors and
other power-hungry parts. (This motor needs 50-100mA).
Because the motor needs more current than an Arduino pin can
provide, we'll use a transistor to do the heavy lifting.
A transistor is a solid-state switch. When we give it a small
amount of current, it can switch a much larger current.
The transistors in your kit (2N2222) can switch up to 200mA.

You can turn a transistor on and off using the digitalWrite()
function, but you can also use the analogWrite() function to
vary the speed of the motor. The analogWrite() function pulses
a pin, varying the width of the pulse from 0% to 100%. We call
this technique "PWM", for "Pulse-Width Modulation".

One thing to keep in mind is that when you lower the speed of
a motor using PWM, you're also reducing the torque (strength)
of the motor. For PWM values below 50 or so, the motor won't have
enough torque to start spinning. It will start spinning when you
raise the speed a bit.

Hardware connections:

Transistor:

The transistor has three pins. Looking at the flat side with the
pins down, the order is COLLECTOR, BASE, EMITTER.

Connect the black wire on the motor to the
COLLECTOR pin on the transistor.

Connect the BASE pin through a 330 Ohm resistor to
digital pin 9.

Connect the EMITTER pin to GND.

Motor:

You've already connected the black wire on the motor to the
COLLECTOR pin on the transistor.

Connect the other (red) wire on the motor to 5V.

Flyback diode:

When the motor is spinning and suddenly turned off, the
magnetic field inside it collapses, generating a voltage spike.
This can damage the transistor. To prevent this, we use a
"flyback diode", which diverts the voltage spike away from
the transistor.

Connect the side of the diode with the band (cathode) to 5V
Connect the other side of the diode (anode) to the black wire
on the motor.

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/

// We'll be controlling the motor from pin 9.
// This must be one of the PWM-capable pins.

const int motorPin = 0;


void setup()
{
    // Set up the motor pin to be an output:

    pinMode( motorPin, OUTPUT );
}


// This function turns the motor on and off like the blinking LED.
// Try different values to affect the timing.

void motorOnThenOff()
{
    int onTime = 3000;  // milliseconds to turn the motor on
    int offTime = 3000; // milliseconds to turn the motor off

    digitalWrite( motorPin, HIGH ); // turn the motor on (full speed)
    delay( onTime );                // delay for onTime milliseconds
    digitalWrite( motorPin, LOW );  // turn the motor off
    delay( offTime );               // delay for offTime milliseconds
}


// This function alternates between two speeds.
// Try different values to affect the timing and speed.

void motorOnThenOffWithSpeed()
{
    int Speed1 = 200;  // between 0 (stopped) and 255 (full speed)
    int Time1 = 3000;  // milliseconds for speed 1

    int Speed2 = 50;   // between 0 (stopped) and 255 (full speed)
    int Time2 = 3000;  // milliseconds to turn the motor off

    analogWrite( motorPin, Speed1 );  // turns the motor On
    delay( Time1 );                   // delay for onTime milliseconds
    analogWrite( motorPin, Speed2 );  // turns the motor Off
    delay( Time2 );                   // delay for offTime milliseconds
}


// This function slowly accelerates the motor to full speed,
// then back down to zero.

void motorAcceleration()
{
    int speed;
    int delayTime = 20; // milliseconds between each speed step

                        // accelerate the motor

    for( speed = 0; speed <= 255; speed++ )
    {
        analogWrite( motorPin, speed );	// set the new speed
        delay( delayTime );           	// delay between speed steps
    }

    // decelerate the motor

    for( speed = 255; speed >= 0; speed-- )
    {
        analogWrite( motorPin, speed );	// set the new speed
        delay( delayTime );           	// delay between speed steps
    }
}


void motorAccelerateAndStop()
{
    //ramp up!
    for( int speed = 0; speed < 256; speed += 4 )
    {

        // We'll print out a message to let you know that the
        // number was received:

        Log( "Setting speed to " );
        Log( speed.ToString()->Begin() );

        // And finally, we'll set the speed of the motor!

        analogWrite( motorPin, speed );
        delay( 100 );
    }

    //turn the motor off
    analogWrite( motorPin, 0 );
    delay( 5000 );
}


void loop()
{
    // Here we've used comments to disable some of the examples.
    // To try different things, uncomment one of the following lines
    // and comment the other ones. See the functions below to learn
    // what they do and how they work.

    //motorOnThenOff();
    //motorOnThenOffWithSpeed();
    //motorAcceleration();
    motorAccelerateAndStop();

}