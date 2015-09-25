
// The Arduino Wiring application template is documented at http://go.microsoft.com/fwlink/?LinkID=533884&clcid=0x409

const int stripClock = 31;
const int stripData = 29;
const int stripLen = 48;

typedef struct _PIXEL_VALUES {
    BYTE Green;
    BYTE Red;
    BYTE Blue;
} PIXEL_VALUES, *PPIXEL_VALUES;

// Array of stored Pixel values
PIXEL_VALUES Pixels[stripLen];

// Custom Functions for working with the RGB Pixel Strip
void SetPixel( int pixel, BYTE Red, BYTE Green, BYTE Blue );
void ShiftPixel( int pixel );
void ShiftAllPixels();

void setup()
{
    // Set pins to outputs
    pinMode( stripClock, OUTPUT );
    pinMode( stripData, OUTPUT );
    digitalWrite( stripClock, LOW );
    digitalWrite( stripData, LOW );

    // Reset all the pixels
    for( int i = 0; i < stripLen; i++ )
    {
        SetPixel( i, 0, 0, 0 );
    }
    ShiftAllPixels();
}

void loop()
{
    int i;

    // Set the pixels to Red
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, ( i & 0x7F ), 0, 0 );
    }
    ShiftAllPixels();
    delay( 1000 );

    // Set the pixels to Green
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, 0, ( i & 0x7F ), 0 );
    }
    ShiftAllPixels();
    delay( 1000 );

    // Set the pixels to Blue
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, 0, 0, ( i & 0x7F ) );
    }
    ShiftAllPixels();
    delay( 1000 );

    // Set the pixels to White
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, ( i & 0x7F ), ( i & 0x7F ), ( i & 0x7F ) );
    }
    ShiftAllPixels();
    delay( 1000 );

    // Set the pixels to gradient from Yellow to Cyan
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, ( ( stripLen - i ) & 0x7F ), ( ( 128 + ( stripLen / 2 ) + i ) & 0x7F ), ( i & 0x7F ) );
    }
    ShiftAllPixels();
    delay( 1000 );

    // Set the pixels to random colors
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, (BYTE)random( 0, 40 ), (BYTE)random( 0, 40 ), (BYTE)random( 0, 40 ) );
    }
    ShiftAllPixels();
    delay( 1000 );

    // Turn the pixels off
    for( i = 0; i < stripLen; i++ )
    {
        SetPixel( i, 0, 0, 0 );
    }
    ShiftAllPixels();
    delay( 1000 );
}

// Sets the pixel color in our array
void SetPixel( int pixel, BYTE Red, BYTE Green, BYTE Blue )
{
    if( pixel < stripLen )
    {
        Pixels[pixel].Red = Red | 0x80;
        Pixels[pixel].Green = Green | 0x80;
        Pixels[pixel].Blue = Blue | 0x80;
    }
}

// Sends the color of a pixel to the strip
void ShiftPixel( int pixel )
{
    PPIXEL_VALUES PixelValues = &Pixels[pixel];
    BYTE bit;
    int i;

    for( i = 7; i >= 0; i-- )
    {
        bit = ( PixelValues->Green >> i ) & 0x01;
        digitalWrite( stripData, bit );
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
    for( i = 7; i >= 0; i-- )
    {
        bit = ( PixelValues->Red >> i ) & 0x01;
        digitalWrite( stripData, bit );
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
    for( i = 7; i >= 0; i-- )
    {
        bit = ( PixelValues->Blue >> i ) & 0x01;
        digitalWrite( stripData, bit );
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
}

// Sends all the pixel colors to the strip
void ShiftAllPixels()
{
    int i;

    digitalWrite( stripData, 0 );
    for( i = 0; i < 8; i++ )
    {
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
    for( i = 0; i < 8; i++ )
    {
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
    for( i = 0; i < 8; i++ )
    {
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }

    for( i = 0; i < stripLen; i++ )
    {
        ShiftPixel( i );
    }

    digitalWrite( stripData, 0 );
    for( i = 0; i < 8; i++ )
    {
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
    for( i = 0; i < 8; i++ )
    {
        digitalWrite( stripClock, HIGH );
        digitalWrite( stripClock, LOW );
    }
}