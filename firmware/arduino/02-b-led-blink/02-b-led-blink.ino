// 02-b-led-blink
// Postupne blikani LED na D9, D10 a D11 s vypisem stavu na seriovou linku.
const int leds[] = {9, 10, 11};
int i = 0;

void setup() {
  Serial.begin(9600);
  for (int k = 0; k < 3; k++) pinMode(leds[k], OUTPUT);
}

void loop() {
  int pin = leds[i % 3];
  digitalWrite(pin, HIGH);
  Serial.print("LED on D");
  Serial.println(pin);
  delay(500);
  digitalWrite(pin, LOW);
  i++;
}
