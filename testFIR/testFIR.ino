/*
  testLPF.ino
  test for low-pass filter
*/

#include "config_testFIR.h"

float x[SIZE_WINDOWS] = { 0 };
float y[SIZE_WINDOWS] = { 0 };
float val_hpfd;
float hz;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  queueue();
  x[0] = (float)analogRead(PIN_ANLG);
  fir();
  Serial.print("raw:");
  Serial.print(x[0]);
  Serial.print(",");
  Serial.print("LPfiltered:");
  Serial.println(y[0]);
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
  short k = 0;
  for (k = 0; k < SIZE_WINDOWS; ++k) {
    y[0] += coef[k] * x[k];
  }
}

float movavg(float z) {
  short c;
  float v = 0;
  for (c = 0; c <= SIZE_WINDOWS - 1; c++) {
    v += x[c];
  }
  return v / SIZE_WINDOWS;
}