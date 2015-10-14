
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
