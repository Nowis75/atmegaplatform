// 04-a-eeprom-led-state
// Example - Při stisknutí tlačítka se uloží aktuální stav LED do EEPROM. Při restartu mikrokontroléru se tento stav načte a nastaví LED.
#include <Arduino.h>

#include <EEPROM.h>

// Definice pinů
#define BUTTON_PIN 5
#define LED_PIN 9

// Proměnná pro uchování stavu LED
bool ledState = false;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    // Načtení uloženého stavu LED z EEPROM
    ledState = EEPROM.read(0);  // Čtení z adresy 0
    digitalWrite(LED_PIN, ledState);  // Nastavení LED podle uloženého stavu
}

void loop() {
    // Kontrola stisknutí tlačítka
    if (digitalRead(BUTTON_PIN) == HIGH) {
        delay(200);  // Odstranění zákmitů tlačítka

        // Přepnutí stavu LED
        ledState = !ledState;  // Změna stavu
        digitalWrite(LED_PIN, ledState);  // Nastavení LED

        // Uložení stavu LED do EEPROM
        EEPROM.write(0, ledState);
    }
}
