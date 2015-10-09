
// The Arduino Wiring application template is documented at 
// http://go.microsoft.com/fwlink/?LinkID=533884&clcid=0x409

#include "MyClass.h"

MyClass myClass;

void setup()
{
    pinMode( GPIO_5, OUTPUT );
}

void loop()
{
    // put your main code here, to run repeatedly:

    digitalWrite( GPIO_5, LOW );
    delay( 500 );
    digitalWrite( GPIO_5, HIGH );
    delay( 500 );
}
