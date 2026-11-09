// 04-eeprom-led
// Stav LED se nastavuje znakem ze seriove linky ('1' = zapnuto, jiny znak = vypnuto)
// a uklada se do EEPROM, takze se po restartu obnovi.
#include <EEPROM.h>

const int ledPin = 9;   // LED on D9
char saveC;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  saveC = EEPROM.read(1);                 // nacteni posledniho ulozeneho znaku
  digitalWrite(ledPin, saveC == '1');     // obnoveni stavu LED po restartu
}

void loop() {
  char c;
  if (Serial.available() > 0) {
    c = Serial.read();
    if (c == '\n' || c == '\r') return;   // ignorovat konce radku
    Serial.print("Char = ");
    Serial.println(c);
    EEPROM.update(1, c);                  // zapis jen pri zmene (setri EEPROM)
    saveC = c;

    if (c == '1') {
      digitalWrite(ledPin, 1);
    } else {
      digitalWrite(ledPin, 0);
    }
  }
}
