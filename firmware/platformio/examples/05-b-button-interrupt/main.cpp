// 05-b-button-interrupt
// Example - Program reaguje na změnu stavu tlačítka pouze v přerušení.
#include <Arduino.h>

const int ledPin = 9;  // LED on D9

const int buttonPin = 2;
volatile bool ledState = false;
volatile unsigned long lastInterruptTime = 0; // Poslední čas přerušení (pro debounce)

void toggleLED() {
  unsigned long interruptTime = millis(); // Aktuální čas v milisekundách

  // Pokud od posledního přerušení uběhlo méně než 200 ms, přerušení ignorujeme
  if (interruptTime - lastInterruptTime > 200) { // Debounce interval 200 ms
    ledState = !ledState;           // Přepnutí stavu LED
    digitalWrite(ledPin, ledState); // Nastavení stavu LED
    lastInterruptTime = interruptTime; // Uložení času posledního přerušení
  }
}

void setup() {
  Serial.begin(9600); // Inicializace sériového monitoru
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);
}

void loop() {
  // Sériový výstup pro kontrolu stavu LED

}
