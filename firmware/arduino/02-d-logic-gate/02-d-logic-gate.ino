  
#define A_PIN 5
#define B_PIN 6
#define C_PIN 7
#define F_PIN 9

void setup() {
  pinMode(A_PIN, INPUT_PULLUP);
  pinMode(B_PIN, INPUT_PULLUP);
  pinMode(C_PIN, INPUT_PULLUP);
  pinMode(F_PIN, OUTPUT);
}

void loop() {
  // Čtení vstupů (po stisku jsou LOW)
  int A = !digitalRead(A_PIN);
  int B = !digitalRead(B_PIN);
  int C = !digitalRead(C_PIN);

  // Logická funkce F = C + B
  int F = C || B;

  digitalWrite(F_PIN, F);
}
