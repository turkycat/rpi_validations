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
#include "MPL3115A2.h"

//Create an instance of the object
HTU21D myHumidity;
MPL3115A2 myPressure;

bool barometerMode = true;

void setup()
{
    Wire.begin();
    Log( "WeatherShield Example!" );

    myHumidity.begin();
    myPressure.begin();

    if( barometerMode )
    {
        myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
    }
    else
    {
        myPressure.setModeAltimeter(); // Measure altitude above sea level in meters
    }

    myPressure.setOversampleRate( 7 ); // Set Oversample to the recommended 128
    myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
}

void loop()
{
    /*
     * from HTU21D Sample - Humidity.ino 
     */
    float humd = myHumidity.readHumidity();
    float temp = myHumidity.readTemperature();

    Log( "Time:" );
    Log( millis().ToString()->Begin() );
    Log( " Temperature: " );
    Log( temp.ToString()->Begin() );
    Log( "C" );
    Log( " Humidity: " );
    Log( humd.ToString()->Begin() );

    if( barometerMode )
    {
        /*
         * From MPL3115A2 Sample - Pressure.ino
         * MODE MUST BE IN BAROMETER
         */

        float altitude = myPressure.readAltitude();
        Log( " Altitude(m): " );
        Log( altitude.ToString()->Begin() );

        altitude = myPressure.readAltitudeFt();
        Log( " Altitude(ft): " );
        Log( altitude.ToString()->Begin() );

        float pressure = myPressure.readPressure();
        Log( " Pressure(Pa): " );
        Log( pressure.ToString()->Begin() );

        float temperature = myPressure.readTemp();
        Log( " Temp(c): " );
        Log( temperature.ToString()->Begin() );

        temperature = myPressure.readTempF();
        Log( " Temp(f): " );
        Log( temp.ToString()->Begin() );


        /*
         * From MPL3115A2 Sample - BarometricHgInch.ino
         * MODE MUST BE IN BAROMETER
         */
        const int station_elevation_m = 1638; //Accurate for the roof on my house
                                              //1 pascal = 0.01 millibars
        pressure /= 100; //pressure is now in millibars

        float part1 = pressure - 0.3; //Part 1 of formula

        const float part2 = 8.42288 / 100000.0;
        float part3 = pow( ( pressure - 0.3 ), 0.190284 );
        float part4 = (float)station_elevation_m / part3;
        float part5 = ( 1.0 + ( part2 * part4 ) );
        float part6 = pow( part5, ( 1.0 / 0.190284 ) );
        float altimeter_setting_pressure_mb = part1 * part6; //Output is now in adjusted millibars
        float baroin = altimeter_setting_pressure_mb * 0.02953;

        Log( " Altimeter setting InHg: " );
        Log( baroin.ToString()->Begin() );
    }
    else    //altimeter mode
    {
        /*
         * From Altimeter.ino
         * MODE MUST BE IN ALTIMETER
         */
        float altitude = myPressure.readAltitude();
        Log("Altitude(m): ");
        Log( altitude.ToString()->Begin() );

        altitude = myPressure.readAltitudeFt();
        Log( " Altitude(ft): " );
        Log( altitude.ToString()->Begin() );

        float pressure = myPressure.readPressure();
        Log("Pressure(Pa): ");
        Log(pressure.ToString()->Begin() );

        float temperature = myPressure.readTemp();
        Log(" Temp(c): ");
        Log(temperature.ToString()->Begin() );

        temperature = myPressure.readTempF();
        Log( " Temp(f): " );
        Log( temperature.ToString()->Begin() );
    }

    Log( "\n" );

    delay( 1000 );
}