
// The Arduino Wiring application template is documented at http://go.microsoft.com/fwlink/?LinkID=533884&clcid=0x409
int pin = 29;

void setup()
{
    // put your setup code here, to run once:

    pinMode(pin, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:

    digitalWrite(pin, LOW);
    delay(500);
    digitalWrite(pin, HIGH);
    delay(500);
}
