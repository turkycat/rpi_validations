#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified( 12345 );

void displaySensorDetails( void )
{
    sensor_t sensor;
    accel.getSensor( &sensor );
    Log(  "------------------------------------"  ); Log( "\n" );
    Log( "Sensor:       " ); Log( sensor.name ); Log( "\n" );
    Log( "Driver Ver:   " ); Log( sensor.version.ToString()->Begin() ); Log( "\n" );
    Log( "Unique ID:    " ); Log( sensor.sensor_id.ToString()->Begin() ); Log( "\\n" );
    Log( "Max Value:    " ); Log( sensor.max_value.ToString()->Begin() ); Log(  " m/s^2"  ); Log( "\n" );
    Log( "Min Value:    " ); Log( sensor.min_value.ToString()->Begin() ); Log(  " m/s^2"  ); Log( "\n" );
    Log( "Resolution:   " ); Log( sensor.resolution.ToString()->Begin() ); Log(  " m/s^2"  ); Log( "\n" );
    Log(  "------------------------------------"  ); Log( "\n" );
    Log(  ""  ); Log( "\n" );
    delay( 500 );
}

void displayDataRate( void )
{
    Log( "Data Rate:    " );

    switch( accel.getDataRate() )
    {
    case ADXL345_DATARATE_3200_HZ:
        Log( "3200 " );
        break;
    case ADXL345_DATARATE_1600_HZ:
        Log( "1600 " );
        break;
    case ADXL345_DATARATE_800_HZ:
        Log( "800 " );
        break;
    case ADXL345_DATARATE_400_HZ:
        Log( "400 " );
        break;
    case ADXL345_DATARATE_200_HZ:
        Log( "200 " );
        break;
    case ADXL345_DATARATE_100_HZ:
        Log( "100 " );
        break;
    case ADXL345_DATARATE_50_HZ:
        Log( "50 " );
        break;
    case ADXL345_DATARATE_25_HZ:
        Log( "25 " );
        break;
    case ADXL345_DATARATE_12_5_HZ:
        Log( "12.5 " );
        break;
    case ADXL345_DATARATE_6_25HZ:
        Log( "6.25 " );
        break;
    case ADXL345_DATARATE_3_13_HZ:
        Log( "3.13 " );
        break;
    case ADXL345_DATARATE_1_56_HZ:
        Log( "1.56 " );
        break;
    case ADXL345_DATARATE_0_78_HZ:
        Log( "0.78 " );
        break;
    case ADXL345_DATARATE_0_39_HZ:
        Log( "0.39 " );
        break;
    case ADXL345_DATARATE_0_20_HZ:
        Log( "0.20 " );
        break;
    case ADXL345_DATARATE_0_10_HZ:
        Log( "0.10 " );
        break;
    default:
        Log( "???? " );
        break;
    }
    Log(  " Hz"  ); Log( "\n" );
}

void displayRange( void )
{
    Log( "Range:         +/- " );

    switch( accel.getRange() )
    {
    case ADXL345_RANGE_16_G:
        Log( "16 " );
        break;
    case ADXL345_RANGE_8_G:
        Log( "8 " );
        break;
    case ADXL345_RANGE_4_G:
        Log( "4 " );
        break;
    case ADXL345_RANGE_2_G:
        Log( "2 " );
        break;
    default:
        Log( "?? " );
        break;
    }
    Log(  " g"  ); Log( "\n" );
}

void setup( void )
{
    Log(  "Accelerometer Test" ); Log( "\n" );

    /* Initialise the sensor */
    if( !accel.begin() )
    {
        /* There was a problem detecting the ADXL345 ... check your connections */
        Log(  "Ooops, no ADXL345 detected ... Check your wiring!"  ); Log( "\\n" );
        while( 1 );
    }

    /* Set the range to whatever is appropriate for your project */
    accel.setRange( ADXL345_RANGE_16_G );
    // displaySetRange(ADXL345_RANGE_8_G);
    // displaySetRange(ADXL345_RANGE_4_G);
    // displaySetRange(ADXL345_RANGE_2_G);

    /* Display some basic information on this sensor */
    displaySensorDetails();

    /* Display additional settings (outside the scope of sensor_t) */
    displayDataRate();
    displayRange();
    Log( "\\n" );
}

void loop( void )
{
    /* Get a new sensor event */
    sensors_event_t event;
    accel.getEvent( &event );

    /* Display the results (acceleration is measured in m/s^2) */
    Log( "X: " ); Log( event.acceleration.x.ToString()->Begin() ); Log( "  " );
    Log( "Y: " ); Log( event.acceleration.y.ToString()->Begin() ); Log( "  " );
    Log( "Z: " ); Log( event.acceleration.z.ToString()->Begin() ); Log( "  " ); Log(  "m/s^2 "  ); Log( "\n" );
    delay( 500 );
}