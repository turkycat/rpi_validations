---
layout: default
title: Stepper Motor
lang: en-US
---

# Stepper Motor
Learn how to create a simple app that controls a stepper motor. The app runs the motor in default forward mode, default reverse mode and small-step forward mode in a loop.

# Required Components
* [Sparkfun Stepper Motor - 68 oz.in](https://www.sparkfun.com/products/10846)
* [Sparkfun Big Easy Driver](https://www.sparkfun.com/products/12859)

# Hooking up Components
1. Start by hooking up the Raspberry Pi 2 to the Big Easy Driver.
   1. Connect the ENABLE pin on the driver to pin 12 (GPIO 18) on the Pi.
   2. Connect the MS1, MS2 and MS3 pins on the driver to pins 36, 38 and 40 respectively. (GPIO 16, GPIO 20 and GPIO 21)
   3. Connect the STEP pin on the driver to pin 10 (GPIO 15) on the Pi.
   4. Connect the DIR pin on the driver to pin 8 (GPIO 14) on the Pi.
   5. Finally, connect the GND pin on the driver to pin 39 on the Pi.
2. Next connect the motor to the driver. The Black and Green cables connect to the pins marked 'A' on the driver and the Red and Blue cables connect to the pins marked 'B' on the driver.
3. Hook up a 12V/2A power source to the driver by connecting the positive lead to the pin marked M+ and the negative lead to the pin marked GND.

# Code
```
// The Arduino Wiring application template is documented at 
// http://go.microsoft.com/fwlink/?LinkID=533884&clcid=0x409

UCHAR stp = GPIO_15;
UCHAR dir = GPIO_14;
UCHAR MS1 = GPIO_16;
UCHAR MS2 = GPIO_20;
UCHAR MS3 = GPIO_21;
UCHAR EN = GPIO_18;

//Declare variables for functions
int x;

void setup() {
	pinMode(stp, OUTPUT);
	pinMode(dir, OUTPUT);
	pinMode(MS1, OUTPUT);
	pinMode(MS2, OUTPUT);
	pinMode(MS3, OUTPUT);
	pinMode(EN, OUTPUT);
	digitalWrite(EN, LOW); //Pull enable pin low to set FETs active and allow motor control
}

//Main loop
void loop() {
	//Step Forward Default
	digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
	digitalWrite(MS1, LOW);
	digitalWrite(MS2, LOW);
	digitalWrite(MS3, LOW);
	for (x = 1; x<1000; x++)  //Loop the forward stepping enough times for motion to be visible
	{
		digitalWrite(stp, HIGH); //Trigger one step forward
		delay(1);
		digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
		delay(1);
	}
	delay(1000);
	
	//Step Reverse Default
	digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
	digitalWrite(MS1, LOW);
	digitalWrite(MS2, LOW);
	digitalWrite(MS3, LOW);
	for (x = 1; x<1000; x++)  //Loop the stepping enough times for motion to be visible
	{
		digitalWrite(stp, HIGH); //Trigger one step
		delay(1);
		digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
		delay(1);
	}
	delay(1000);

	//Small Step Mode
	digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
	digitalWrite(MS1, HIGH); //Pull MS1,MS2, and MS3 high to set logic to 1/16th microstep resolution
	digitalWrite(MS2, HIGH);
	digitalWrite(MS3, HIGH);
	for (x = 1; x<1000; x++)  //Loop the forward stepping enough times for motion to be visible
	{
		digitalWrite(stp, HIGH); //Trigger one step forward
		delay(1);
		digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
		delay(1);
	}
	delay(1000);
}
```

