/*
 * we'll set this channel number to match the channel we've plugged our potentiometer's
 * wiper pin into. In this case, channel 0 (C0). If you use a different channel,
 * you'll need to update this number.
 */
int channel = 0;

void setup()
{
    /*
     * it is not necessary to set the channel to input, as the analogRead command must
     * assume the 'pin number' it is given refers to a channel on the ADC chip.
     */
}

void loop()
{
    //read the value from the ADC channel
    int value = analogRead( channel );

    //report the value to the output console
    Log( L"Analog value: " );
    Log( value.ToString()->Begin() );
    Log( "\n" );

    //delay for 500ms
    delay( 500 );
}
