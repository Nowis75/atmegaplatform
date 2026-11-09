// 06-b-i2c-scanner
// Example - Vyhledani zarizeni na sbernici I2C (I2C scanner).
#include <Arduino.h>

#include <Wire.h>

void setup() {
    Serial.begin(9600);
    Wire.begin();
    Serial.println("Hledání zařízení na I2C sběrnici...");
    for (uint8_t address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0) {
            Serial.print("Zařízení nalezeno na adrese: 0x");
            Serial.println(address, HEX);
        }
    }
}

void loop() {
}
