#include "config_testBPF.h"

double val_raw;
double hz;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val_raw = analogRead(PIN_ANLG);
  Serial.println(val_raw);
  delay(10);
}
