// 05-c-timer-isr
// Example - Příklad s časovačem a ISR. LED bliká přesně každou sekundu pomocí přerušení časovače.
#include <Arduino.h>

const int ledPin = 9;  // LED on D9

void setup() {
  pinMode(ledPin, OUTPUT);

  // Nastavení časovače
  TCCR1A = 0; // Stop timer
  TCCR1B = 0;
  TCNT1 = 0;  // Reset čítače
  OCR1A = 15624; // Nastavení přerušení každých 1 sekundu při 16 MHz
  TCCR1B |= (1 << WGM12); // CTC režim
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024
  TIMSK1 |= (1 << OCIE1A); // Povolení přerušení časovače
  sei(); // Povolení globálních přerušení
}

void loop() {
  // Hlavní program může být prázdný
}

ISR(TIMER1_COMPA_vect) {
  digitalWrite(ledPin, !digitalRead(ledPin)); // Přepnutí LED
}
