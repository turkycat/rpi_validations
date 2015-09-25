
// The Arduino Wiring application template is documented at http://go.microsoft.com/fwlink/?LinkID=533884&clcid=0x409

#include "SparkFunHTU21D.h"
#include "SparkFunMPL3115A2.h"

#include "arduino.h"

MPL3115A2 myPressure;
HTU21D myHumidity;

//Give me temperature in fahrenheit!
float readTempF()
{
    return( ( myPressure.readTemp() * 9.0 ) / 5.0 + 32.0 ); // Convert celsius to fahrenheit
}

void setup() {
    Log( L"WeatherShieldSample\n\n" );

    // initialize the digital pin as an output.
    Wire.begin();        // Join i2c bus

                         // Test Multiple slave addresses:
    Wire.beginTransmission( 0x40 );
    Wire.write( 0xE7 );  // Address of data to get
    Wire.endTransmission( false ); // Send data to I2C dev with option for a repeated start. THIS IS NECESSARY and not supported before Arduino V1.0.1!
    if( Wire.requestFrom( 0x40, 1 ) != 1 )
    {
        Log( L"Error reading from humidity sensor\n" );
    }

    byte status = Wire.read();
    Log( L"Humidity sensor status 0x%0x\n\n", status );

    myHumidity.begin();
    myPressure.begin();

    // Configure the sensor
    myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
    myPressure.setOversampleRate( 7 ); // Set Oversample to the recommended 128
    myPressure.enableEventFlags(); // Enable all three pressure and temp event flags
}

void loop()
{
    float pressure = myPressure.readPressure();
    Log( L"Pressure(Pa): %lf\n", pressure );
    float altitude = myPressure.readAltitudeFt();
    Log( L"altitude(Ft): %lf\n", altitude );
    float temperature = readTempF();
    Log( L"Temperature(F): %lf\n", temperature );
    float humidity = myHumidity.readHumidity();
    Log( L"Humidity(f): %lf\n\n", humidity );
}