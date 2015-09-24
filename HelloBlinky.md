---
layout: default
title: Hello Blinky
permalink: /en-US/win10/samples/HelloBlinky.htm
lang: en-US
---

#Hello Blinky
Learn to Deploy and Debug an Arduino Wiring sketch to blink an LED!

##Code
{% highlight C++ %}

int led = 29;  // This is the pin the LED is attached to.

void setup()
{
  pinMode(led, OUTPUT); // Configure the pin for OUTPUT so you can turn on the LED.
}

// the loop routine runs over and over again forever:
void loop()
{
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  digitalWrite(led, HIGH);    // turn the LED on by making the voltage HIGH
  delay(1000);               // wait for a second
}
{% endhighlight %}

This code is included in the default template, and is included here for reference.

##Wire your RPi2 with an LED
LEDs are diodes which will emit light when powered. They are polarized - meaning they work only when plugged in correctly.
![LED Wiring]({{site.baseurl}}/images/rpi2_wiring/led_fritz.png)

##Build and deploy
Press F5 to build and deploy your project.

Refer to the PC setup page for more information.

##Result
You should see the light blinking. If it isn't blinking, try reversing the LED leads.

---

[&laquo; Return to Samples](SampleApps.htm){:role="button"}{:class="btn btn-default"}