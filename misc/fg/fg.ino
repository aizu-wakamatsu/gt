#define RATE 250.0
#define PIN A0

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN, HIGH);
  delay(1000.0/RATE);
  digitalWrite(PIN, LOW);
  delay(1000.0/RATE);
}
