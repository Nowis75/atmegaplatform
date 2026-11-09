// 04-b-eeprom-sos
// Example - Tento příklad demonstruje, jak uložit krátkou zprávu do EEPROM (například sekvenci pro SOS) a následně ji přehrát blikáním LED.
#include <Arduino.h>

#include <EEPROM.h>

// Definice pinů
#define BUTTON_PIN 5
#define LED_PIN 9

// SOS zpráva (tečky a čárky, 1 = LED zapnutá, 0 = LED vypnutá)
const uint8_t sosMessage[] = {1, 0, 1, 0, 1, 0,  // "S" - tečka, mezera
                              1, 1, 1, 0,       // "O" - čárka, mezera
                              1, 0, 1, 0, 1};   // "S" - tečka, mezera

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    // Uložení SOS zprávy do EEPROM (pokud tam ještě není)
    for (int i = 0; i < sizeof(sosMessage); i++) {
        if (EEPROM.read(i) != sosMessage[i]) {  // Ověření, zda je EEPROM prázdná
            EEPROM.write(i, sosMessage[i]);
        }
    }
}

void loop() {
    // Kontrola stisknutí tlačítka
    if (digitalRead(BUTTON_PIN) == HIGH) {
        delay(200);  // Odstranění zákmitů tlačítka

        // Načtení SOS zprávy z EEPROM
        uint8_t messageLength = sizeof(sosMessage);
        for (int i = 0; i < messageLength; i++) {
            uint8_t state = EEPROM.read(i);  // Čtení stavu (1 = zapnuto, 0 = vypnuto)

            // Nastavení LED
            digitalWrite(LED_PIN, state);
            delay(300);  // Délka tečky/čárky

            // Pauza mezi blikáními
            digitalWrite(LED_PIN, LOW);
            delay(300);  // Délka mezery
        }

        // Pauza po přehrání celé zprávy
        delay(1000);
    }
}
