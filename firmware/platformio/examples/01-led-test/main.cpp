// 01-led-test
// Example - Simple example LED. Test ATmega
#include <Arduino.h>

const int ledPin = 9;  // LED on D9

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin,1);
  delay(3000);
  digitalWrite(ledPin,0);
  delay(3000);
}
