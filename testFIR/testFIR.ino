/*
  testLPF.ino
  test for low-pass filter
*/

#include "config_testFIR.h"

double x[SIZE_WINDOWS] = { 0 };
double y[SIZE_WINDOWS] = { 0 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  set_param_fir_0l25();
}

void loop() {
  // put your main code here, to run repeatedly:
  queueue();
  x[0] = (double)analogRead(PIN_ANLG);
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