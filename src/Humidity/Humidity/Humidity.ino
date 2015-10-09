/*
HTU21D Humidity Sensor Example Code
By: Nathan Seidle
SparkFun Electronics
Date: September 15th, 2013
License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

Uses the HTU21D library to display the current humidity and temperature

Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.

Hardware Connections (Breakoutboard to Arduino):
-VCC = 3.3V
-GND = GND
-SDA = A4 (use inline 10k resistor if your board is 5V)
-SCL = A5 (use inline 10k resistor if your board is 5V)

*/

#include <Wire.h>
#include "HTU21D.h"

//Create an instance of the object
HTU21D myHumidity;

void setup()
{
    Log( "HTU21D Example!" );

    myHumidity.begin();
}

void loop()
{
    float humd = myHumidity.readHumidity();
    float temp = myHumidity.readTemperature();

    Log( "Time:" );
    Log( millis().ToString()->Begin() );
    Log( " Temperature:" );
    Log( temp.ToString()->Begin() );
    Log( "C" );
    Log( " Humidity:" );
    Log( humd.ToString()->Begin() );
    //Log( "\\%" );
    Log( "\n" );

    delay( 1000 );
}