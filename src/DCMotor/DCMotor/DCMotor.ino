
/*
 * The motor must be connected to one of the 3-pin connectors on the PWM hat (or similar device)
 * The function analogWrite( unsigned int pin, unsigned int speed ) will assume that the given pin
 *   number refers to the channel of the same number on the hat. Therefore, you should refer to the
 *   16 channels of a 16-channel PWM hat as [ 0 - 15 ]. In this case, we've set 0 as the MOTOR_PIN which
 *   means that channel 0 will be used on the hat. 
 */
const int MOTOR_PIN = 0;
const int MILLIS_PER_SECOND = 1000;
const int PWM_MAX_SPEED = 255;
const int PWM_MIN_SPEED = 0;

void setup()
{
    //analog write commands do not require pinModes to be set. They will be inferred by the function type!
}


void motorOnThenOff()
{
    int number_of_seconds = 3;

    //turn the motor on for 1 second
    Log( "Setting speed to max\n" );
    analogWrite( MOTOR_PIN, PWM_MAX_SPEED );
    delay( MILLIS_PER_SECOND * number_of_seconds );

    //turn the motor off for one second
    Log( "Setting speed to min\n" );
    analogWrite( MOTOR_PIN, PWM_MIN_SPEED );
    delay( MILLIS_PER_SECOND * number_of_seconds );
}


void motorAccelerateAndDecelerate()
{
    int speed;

    //increase speed at a moderate pace
    for( speed = 0; speed <= PWM_MAX_SPEED; ++speed )
    {
        Log( "Setting speed to " );
        Log( speed.ToString()->Begin() );
        Log( "\n" );

        analogWrite( MOTOR_PIN, speed );
        delay( 25 );
    }


    //decrease speed at a moderate pace
    for( speed = 252; speed >= PWM_MIN_SPEED; --speed )
    {
        Log( "Setting speed to " );
        Log( speed.ToString()->Begin() );
        Log( "\n" );

        analogWrite( MOTOR_PIN, speed );
        delay( 25 );
    }
}


void loop()
{
    motorOnThenOff();
    motorAccelerateAndDecelerate();

    //delay for a moment before restarting
    analogWrite( MOTOR_PIN, PWM_MIN_SPEED );
    delay( MILLIS_PER_SECOND );
}