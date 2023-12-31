/*
  india22.ino
  test for UKF
*/

#include "config_india22.h"

float val_raw[SIZE_WINDOWS] = { 0 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  queueue();
  val_raw[0] = (float)analogRead(PIN_ANLG);

  delay(1000 / RATE_SAMPLE);
}

void queueue() {
  // AULD 9 ... 0 LAST
  short c = 0;
  for (c = SIZE_WINDOWS - 1; c >= 1; --c) {
    val_raw[c] = val_raw[c - 1];
  }
  val_raw[0] = 0;
}