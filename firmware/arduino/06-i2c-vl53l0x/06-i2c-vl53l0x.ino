#include <Wire.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);
  Serial.println(F("Test senzoru VL53L0X"));

  // Inicializace I²C a senzoru
  if (!lox.begin()) {
    Serial.println(F("Nepodarilo se inicializovat VL53L0X!"));
    while (1);
  }
  Serial.println(F("Senzor VL53L0X nalezen."));
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  // Měření vzdálenosti
  lox.rangingTest(&measure, false);  // false = nevypisuje debug info

  if (measure.RangeStatus != 4) {  // 4 = chyba
    Serial.print(F("Vzdalenost: "));
    Serial.print(measure.RangeMilliMeter);
    Serial.println(F(" mm"));
  } else {
    Serial.println(F("Mereni mimo rozsah"));
  }

  delay(500);
}
