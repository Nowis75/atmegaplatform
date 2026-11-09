// 02-e-logic-function
// Example - implementace funkce F = C + B
#include <Arduino.h>

// Definice vstupů a výstupů
#define A_PIN 5  // Vstup A
#define B_PIN 6  // Vstup B
#define C_PIN 7  // Vstup C
#define F_PIN 9  // Výstup F

void setup() {
    // Nastavení vstupů
    pinMode(A_PIN, INPUT);
    pinMode(B_PIN, INPUT);
    pinMode(C_PIN, INPUT);

    // Nastavení výstupu
    pinMode(F_PIN, OUTPUT);
}

void loop() {
    // Čtení vstupních hodnot
    int A = digitalRead(A_PIN);
    int B = digitalRead(B_PIN);
    int C = digitalRead(C_PIN);

     // Implementace minimalizované funkce 
    //int F = C || B;                             // F = C + B
    //int F = B || (A && C);                      // F = B + AC
    int F = ((!A && !C) || !C || (B && !A));      // F = A'C' + C' + BA'   

    // Nastavení výstupu
    digitalWrite(F_PIN, F);
}
