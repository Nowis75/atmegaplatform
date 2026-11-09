// 03-c-serial-thermostat
// Example - Nastavte požadovanou teplotu pomocí příkazu (např. SET 25) a Arduino bude simulovat termostat.
#include <Arduino.h>

String inString;
int setTemperature = 20; // Výchozí teplota

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read();
    if (inChar == '\n') {
      inString.trim();

      if (inString.startsWith("SET ")) {
        setTemperature = inString.substring(4).toInt();
        Serial.print("Nastavená teplota: ");
        Serial.println(setTemperature);
      } else {
        Serial.println("Neplatný příkaz. Použijte 'SET <teplota>'");
      }

      inString = "";
    } else {
      inString += inChar;
    }
  }

  // Simulace měření teploty (např. ze senzoru)
  int currentTemperature = random(15, 30);
  Serial.print("Aktuální teplota: ");
  Serial.println(currentTemperature);

  if (currentTemperature > setTemperature) {
    Serial.println("Teplota je příliš vysoká. Chlazení...");
  } else if (currentTemperature < setTemperature) {
    Serial.println("Teplota je příliš nízká. Topení...");
  } else {
    Serial.println("Teplota je stabilní.");
  }

  delay(3000); // Simulace zpoždění měření
}
