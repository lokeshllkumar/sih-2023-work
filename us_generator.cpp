#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

// Define constants
const int LM380_OUT_PIN = 9;        // Digital pin connected to LM380 output
const int PULSE_DURATION_MS = 1;    // Duration of each pulse in milliseconds
const int PULSE_INTERVAL_MS = 1000; // Interval between pulses in milliseconds

void setup()
{
    // Set the LM380 output pin as an output
    pinMode(LM380_OUT_PIN, OUTPUT);
}

void loop()
{
    // Generate an ultrasound pulse
    ultrasonicPulse();

    // Wait for the specified interval before the next pulse
    delay(PULSE_INTERVAL_MS);
}

void ultrasonicPulse()
{
    // Generate a short pulse by turning the LM380 output pin high
    digitalWrite(LM380_OUT_PIN, HIGH);
    delay(PULSE_DURATION_MS);

    // Turn the LM380 output pin off to end the pulse
    digitalWrite(LM380_OUT_PIN, LOW);
}
