const int ledPin = 9; 
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin,1);
  delay(1000);
  digitalWrite(ledPin,0);
  delay(1000);
}
