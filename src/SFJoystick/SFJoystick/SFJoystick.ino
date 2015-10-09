int X = 0;
int Y = 1;
int Z = GPIO_26;

void setup()
{
    pinMode( X, INPUT );
    pinMode( Y, INPUT );
    pinMode( Z, INPUT );
}

void loop()
{
    int value = analogRead( X );
    Log( "X: " );
    Log( value.ToString()->Begin() );

    value = analogRead( Y );
    Log( " | Y:" );
    Log( value.ToString()->Begin() );

    value = digitalRead( Z );
    Log( " | Z: " );
    Log( value.ToString()->Begin() );

    Log( L"\n" );

    delay( 100 );
}