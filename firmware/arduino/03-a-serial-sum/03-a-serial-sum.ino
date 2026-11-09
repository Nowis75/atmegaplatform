/* ======================================== */
/* Example - soucet dvou cisel odedelena mezerou (napr. 22 35) */

String inString;
void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read();
    if (inChar == '\n') {
      inString.trim();
      int spaceIndex = inString.indexOf(' ');
      if (spaceIndex != -1) {
        String num1 = inString.substring(0, spaceIndex);
        String num2 = inString.substring(spaceIndex + 1);

        int result = num1.toInt() + num2.toInt();
        Serial.print("Součet: ");
        Serial.println(result);
      } else {
        Serial.println("Neplatný vstup, použijte formát 'číslo číslo'.");
      }
      inString = "";
    } else {
      inString += inChar;
    }
  }
}
