/*
  india19.ino
  test for filter
*/

#include "config_india19.h"

float x[SIZE_WINDOWS] = { 0 };
float y[SIZE_WINDOWS] = { 0 };
float coef[SIZE_WINDOWS] = { 0 };


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sum;
  queueue();
  x[0] = (float)analogRead(PIN_ANLG);

  delay(1000 / RATE_SAMPLE);
}

void queueue() {
  // AULD 9 ... 0 LAST
  short c = 0;
  for (c = SIZE_WINDOWS - 1; c >= 1; --c) {
    x[c] = x[c - 1];
    y[c] = y[c - 1];
  }
  x[0] = 0;
  y[0] = 0;
}

void fir() {
  short i = 0;
  for (i = 0; i < SIZE_WINDOWS; ++i) {
    y[0] += coef[i] * x[i];
  }
}