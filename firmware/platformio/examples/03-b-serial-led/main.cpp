// 03-b-serial-led
// Example
// Advance example for control LED with communication by serial.
#include <Arduino.h>

const int ledPin = 9;  // LED on D9

String inString;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED je zpočátku vypnutá
}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read(); // Přečte jeden znak z Serialu

    // Pokud je znak Enter (nový řádek), zpracuje vstupní řetězec
    if (inChar == '\n') {
      inString.trim(); // Odstraní mezery a nové řádky na začátku a na konci řetězce

      Serial.print("Zadaný řetězec: ");
      Serial.println(inString);

      // Pokud je řetězec "RUN" (bez ohledu na velikost písmen), rozsvítí LED
      if (inString.equalsIgnoreCase("RUN")) {
        digitalWrite(ledPin, HIGH);
        Serial.println("LED rozsvícena");
      } else { // Jinak LED zhasne
        digitalWrite(ledPin, LOW);
        Serial.println("LED zhasnuta");
      }

      inString = ""; // Vyčistí vstupní řetězec pro další použití
    } else {
      inString += inChar; // Přidá znak do vstupního řetězce
    }
  }
}
