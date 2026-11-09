int i=0;
 
void setup() {
   Serial.begin(9600);
}

void loop() {
  
  Serial.print("OK. ATMega 328p is ready ");
  Serial.println(i);
  i++;
  delay(1000);
}
