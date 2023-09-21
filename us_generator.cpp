//the header files included in this file are already included by default in the Arduino IDE environment; remove if they are not needed

#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

#define LM380_OUT_PIN 9;        
#define PULSE_DURATION_MS 1;
#define PULSE_INTERVAL_MS 1000;

void setup()
{
    pinMode(LM380_OUT_PIN, OUTPUT);
}

void loop()
{
    ultrasonicPulseGen();

    delay(PULSE_INTERVAL_MS);
}

void ultrasonicPulseGen()
{
    digitalWrite(LM380_OUT_PIN, HIGH);
    delay(PULSE_DURATION_MS);
    digitalWrite(LM380_OUT_PIN, LOW);
}
