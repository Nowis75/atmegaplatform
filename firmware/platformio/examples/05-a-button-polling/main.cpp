// 05-a-button-polling
// Example - Bez přerušení (POLLING) program neustále konntroluje stav tlačítka. Nemůže vykonávat nic jiného.
#include <Arduino.h>

const int ledPin = 9;  // LED on D9

const int buttonPin = 5;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
