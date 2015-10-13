
int analogPin = 0;

void setup()
{

}

void loop()
{
    int sensorValue = analogRead( analogPin );
    Log( "Microphone Sensor Value: " );
    Log( sensorValue.ToString()->Begin() );
    Log( "\n" );
}