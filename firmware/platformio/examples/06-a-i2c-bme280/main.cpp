// 06-a-i2c-bme280
// Example - Zde je příklad kódu pro práci s čidlem BME280 a mikrokontrolérem ATmega328P (například Arduino Uno). Čidlo BME280 komunikuje pomocí sběrnice I2C, takže potřebujeme použít knihovnu Wire.h a případně knihovnu od Adafruitu pro BME280.
#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Definice I2C adresy BME280 (výchozí 0x76 nebo 0x77)
#define BME280_I2C_ADDRESS 0x77

// Objekt čidla
Adafruit_BME280 bme;

void setup() {
    // Inicializace sériové komunikace
    Serial.begin(9600);
    Serial.println("Inicializace BME280...");

    // Inicializace BME280
    if (!bme.begin(BME280_I2C_ADDRESS)) {
        Serial.println("Čidlo BME280 nebylo nalezeno! Zkontrolujte připojení.");
        while (1);  // Zastavení programu
    }

    Serial.println("BME280 inicializováno úspěšně.");
}

void loop() {
    // Načtení hodnot z BME280
    float teplota = bme.readTemperature();   // Teplota v °C
    float vlhkost = bme.readHumidity();      // Relativní vlhkost v %
    float tlak = bme.readPressure() / 100.0; // Tlak v hPa

    // Výpis dat do sériového monitoru
    Serial.print("Teplota: ");
    Serial.print(teplota);
    Serial.println(" °C");

    Serial.print("Vlhkost: ");
    Serial.print(vlhkost);
    Serial.println(" %");

    Serial.print("Tlak: ");
    Serial.print(tlak);
    Serial.println(" hPa");

    Serial.println("---------------------");
    delay(2000);  // Aktualizace každé 2 sekundy
}
