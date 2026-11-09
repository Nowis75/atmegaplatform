// 04-c-eeprom-counter
// Example - Tento příklad implementuje počítadlo stisknutí tlačítka, které ukládá aktuální počet stisknutí do EEPROM. Počet stisknutí se zobrazuje v sériovém monitoru a uchovává se i po vypnutí napájení.
#include <Arduino.h>

#include <EEPROM.h>

// Definice pinů
#define BUTTON_PIN 5
#define RESET_BUTTON_PIN 6

// Proměnné
int buttonCounter = 0;  // Počítadlo stisknutí tlačítka
bool buttonState = false;  // Aktuální stav tlačítka
bool lastButtonState = false;  // Předchozí stav tlačítka

void setup() {
    // Nastavení pinu tlačítka
    pinMode(BUTTON_PIN, INPUT);
    pinMode(RESET_BUTTON_PIN, INPUT);

    // Inicializace sériové komunikace
    Serial.begin(9600);

    // Načtení počítadla z EEPROM
    buttonCounter = EEPROM.read(0);

    // Výpis aktuální hodnoty počítadla
    Serial.print("Počet stisknutí tlačítka: ");
    Serial.println(buttonCounter);
}

void loop() {
    // Čtení stavu tlačítka
    buttonState = digitalRead(BUTTON_PIN);

    // Detekce změny stavu tlačítka (předchází opakovanému zvýšení počtu)
    if (buttonState == HIGH && lastButtonState == LOW) {
        delay(50);  // Odstranění zákmitů tlačítka

        // Zvýšení počítadla
        buttonCounter++;

        // Uložení počítadla do EEPROM
        EEPROM.write(0, buttonCounter);

        // Výpis počtu stisknutí do sériového monitoru
        Serial.print("Počet stisknutí tlačítka: ");
        Serial.println(buttonCounter);
    }

    // Aktualizace předchozího stavu tlačítka
    lastButtonState = buttonState;

    if (digitalRead(RESET_BUTTON_PIN) == HIGH) {
      buttonCounter = 0;
      EEPROM.write(0, buttonCounter);
      Serial.println("Počítadlo resetováno.");
    }
}
