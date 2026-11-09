// 03-e-serial-stopwatch
// Example - Po příkazu START začne Arduino měřit čas, po příkazu STOP vrátí časový rozdíl.
#include <Arduino.h>

unsigned long startTime = 0;
String inString;

void setup() {
  Serial.begin(9600);
  Serial.println("Zadejte příkaz: START nebo STOP.");
}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read();
    if (inChar == '\n') {
      inString.trim();

      if (inString == "START") {
        startTime = millis();
        Serial.println("Měření času zahájeno.");
      } else if (inString == "STOP") {
        if (startTime > 0) {
          unsigned long elapsedTime = millis() - startTime;
          Serial.print("Uplynulý čas: ");
          Serial.print(elapsedTime / 1000.0);
          Serial.println(" sekund.");
          startTime = 0; // Reset
        } else {
          Serial.println("Nejprve zadejte START.");
        }
      } else {
        Serial.println("Neplatný příkaz!");
      }

      inString = "";
    } else {
      inString += inChar;
    }
  }
}
