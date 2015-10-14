#include <Wire.h>
#include "Adafruit_TCS34725.h"

// set to false if using a common cathode LED
#define commonAnode true

// our RGB -> eye-recognized gamma color
byte gammatable[256];

Adafruit_TCS34725 tcs = Adafruit_TCS34725( TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X );

void setup() {
    Log( "Color View Test!" ); Log( "\n" );

    if( tcs.begin() ) {
        Log( "Found sensor" ); Log( "\n" );
    }
    else {
        Log( "No TCS34725 found ... check your connections" ); Log( "\n" );
        while( 1 ); // halt!
    }

    // thanks PhilB for this gamma table!
    // it helps convert RGB colors to what humans see
    for( int i = 0; i<256; i++ ) {
        float x = i;
        x /= 255;
        x = pow( x, 2.5 );
        x *= 255;

        if( commonAnode ) {
            gammatable[i] = 255 - x;
        }
        else {
            gammatable[i] = x;
        }
        //Log( gammatable[i] ); Log( "\\n" );
    }
}


void loop() {
    uint16_t clear, red, green, blue;

    tcs.setInterrupt( false );      // turn on LED

    delay( 60 );  // takes 50ms to read 

    tcs.getRawData( &red, &green, &blue, &clear );

    tcs.setInterrupt( true );  // turn off LED

    Log( "C:\t" ); Log( clear.ToString()->Begin() );
    Log( "\tR:\t" ); Log( red.ToString()->Begin() );
    Log( "\tG:\t" ); Log( green.ToString()->Begin() );
    Log( "\tB:\t" ); Log( blue.ToString()->Begin() );

    // Figure out some basic hex code for visualization
    uint32_t sum = clear;
    float r, g, b;
    r = red; r /= sum;
    g = green; g /= sum;
    b = blue; b /= sum;
    r *= 256; g *= 256; b *= 256;
    Log( "\t" );
    Log( r.ToString()->Begin() ); Log( g.ToString()->Begin() ); Log( b.ToString()->Begin() );
    Log( "\n" );

    //Log((int)r ); Log(" "); Log((int)g);Log(" ");  Log( (int)b  ); Log( "\\n" );

    //analogWrite( redpin, gammatable[(int)r] );
    //analogWrite( greenpin, gammatable[(int)g] );
    //analogWrite( bluepin, gammatable[(int)b] );
}

