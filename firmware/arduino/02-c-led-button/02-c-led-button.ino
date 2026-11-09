const int buttonPin = 7;   // pin tlačítka
const int ledPin = 11;      // pin LED

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // vstup s pull-up rezistorem
  pinMode(ledPin, OUTPUT);          // LED jako výstup
}

void loop() {
  int buttonState = digitalRead(buttonPin); // načtení stavu tlačítka

  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);  // stisknuto → rozsvítí LED
  } else {
    digitalWrite(ledPin, LOW);   // nestisknuto → zhasne
  }
}
