// 07-analog-ntc
// Example - Použití NTC termistoru (např. vodotěsné sondy 10kΩ 1% 3950) s ATmega328P.
#include <Arduino.h>

// Definice pinu pro NTC termistor
#define NTC_PIN A0

// Konstanty pro NTC termistor (10kΩ, B = 3950)
const float R_fixed = 10000.0;  // Pevný rezistor (10 kΩ)
const float T0 = 298.15;        // Referenční teplota (25 °C v Kelvinech)
const float R0 = 10000.0;       // Odpor termistoru při 25 °C (10 kΩ)
const float beta = 3950.0;      // Beta koeficient termistoru

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Čtení ADC
    int rawValue = analogRead(NTC_PIN);

    // Převod ADC na napětí
    float Vout = (rawValue / 1023.0) * 5.0;

    // Výpočet odporu NTC
    float R_ntc = (R_fixed * Vout) / (5.0 - Vout);

    // Výpočet teploty pomocí zjednodušené Steinhart-Hartovy rovnice
    float tempK = 1.0 / (1.0 / T0 + (1.0 / beta) * log(R_ntc / R0));
    float tempC = tempK - 273.15;

    // Výpis hodnot do sériového monitoru
    Serial.print("Napětí: ");
    Serial.print(Vout);
    Serial.println(" V");

    Serial.print("Odpor NTC: ");
    Serial.print(R_ntc);
    Serial.println(" ohm");

    Serial.print("Teplota: ");
    Serial.print(tempC);
    Serial.println(" °C");

    delay(1000);  // Aktualizace každou sekundu
}
