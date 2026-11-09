// 03-f-serial-char-led
// Example - LED rizena znakem ze seriove linky (1 = zapnuto, jiny znak = vypnuto).
#include <Arduino.h>

const int ledPin = 9;  // LED on D9

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  char c;

  if ( Serial.available() > 0) {
    c = Serial.read();

    Serial.print  ( "Char = ");
    Serial.println(c);

    if(c=='1'){
      digitalWrite(ledPin,1);
    }else{
      digitalWrite(ledPin,0);
    }

  }
}
