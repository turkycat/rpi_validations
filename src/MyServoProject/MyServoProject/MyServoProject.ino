#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int delayAmount = 2000; // used for spacing out calls
int pin = 29; // the pin that the Servo is on

//void setup()
//{
//    myservo.attach( pin );  // attaches the servo on pin to the servo object
//}
//
//void loop()
//{
//    if( !myservo.attached() )
//    {
//        Log( "Servo is not attached\n" );
//        Log( "Servo is attaching\n" );
//        myservo.attach( pin );
//        if( myservo.attached() )
//        {
//            Log( "Servo is attached\n" );
//        }
//    }
//    else
//    {
//        Log( "Servo is attached\n" );
//    }
//
//    myservo.write( 0 ); // tells the servo to go to angle 0
//    Log( "ServoIndex: %d\n", myservo.read() );
//    Log( "ServoIndex in Microseconds: %d\n", myservo.readMicroseconds() );
//    delay( delayAmount );
//    myservo.write( 180 ); // tells the servo to go to angle 180
//    Log( "ServoIndex: %d\n", myservo.read() );
//    Log( "ServoIndex in Microseconds: %d\n", myservo.readMicroseconds() );
//    delay( delayAmount );
//
//    if( myservo.attached() )
//    {
//        Log( "Servo is attached\n" );
//        Log( "Servo is detaching\n" );
//        myservo.detach();
//        if( !myservo.attached() )
//        {
//            Log( "Servo is detached\n" );
//        }
//    }
//    else
//    {
//        Log( "Servo is not attached\n" );
//    }
//}

int pos = 0;    // variable to store the servo position 

void setup()
{
    myservo.attach( pin );  // attaches the servo on pin 9 to the servo object 
}

void loop()
{
    for( pos = 0; pos <= 180; pos += 1 ) // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
        myservo.write( pos );              // tell servo to go to position in variable 'pos' 
        delay( 30 );                       // waits 15ms for the servo to reach the position 
    }
    for( pos = 180; pos >= 0; pos -= 1 )     // goes from 180 degrees to 0 degrees 
    {
        myservo.write( pos );              // tell servo to go to position in variable 'pos' 
        delay( 30 );                       // waits 15ms for the servo to reach the position 
    }
}
