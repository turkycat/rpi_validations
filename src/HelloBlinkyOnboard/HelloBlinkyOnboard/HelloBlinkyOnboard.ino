
// The Arduino Wiring application template is documented at 
// http://go.microsoft.com/fwlink/?LinkID=533884&clcid=0x409

#if defined(_M_IX86) || defined(_M_X64) // MBM
int pin = GPIO_5; // Or any other pin available on MBM
#elif defined (_M_ARM) // RPI2
int pin = LED_BUILTIN;
#endif


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
