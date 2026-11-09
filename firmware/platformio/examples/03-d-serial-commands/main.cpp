// 03-d-serial-commands
// Example - Arduino reaguje na jednoduché příkazy k pohybu (FORWARD, BACKWARD, STOP).
#include <Arduino.h>

String inString;

void setup() {
  Serial.begin(9600);
  Serial.println("Zadejte příkaz: FORWARD, BACKWARD, STOP.");
}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read();
    if (inChar == '\n') {
      inString.trim();

      if (inString == "FORWARD") {
        Serial.println("Robot se pohybuje vpřed.");
      } else if (inString == "BACKWARD") {
        Serial.println("Robot se pohybuje vzad.");
      } else if (inString == "STOP") {
        Serial.println("Robot zastaven.");
      } else {
        Serial.println("Neplatný příkaz!");
      }

      inString = "";
    } else {
      inString += inChar;
    }
  }
}
