int pin = 0;

void setup()
{
    /*
     * it is not necessary to set the pin to input,
     * as the analogRead command must assume this pin is attached to an ADC chip
     */
}

void loop()
{
    int value = analogRead( pin );
    Log( L"Analog value: " );
    Log( value.ToString()->Begin() );
    Log( "\n" );
    delay( 500 );
}
