/*
  testLPF.ino
  test for low-pass filter
*/

#include "config_testLPF.h"

float val_raw[SIZE_WINDOWS] = { 0 };
float val_lpfd[SIZE_WINDOWS] = { 0 };
float val_hpfd;
float hz;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  queueue();
  val_raw[0] = (float)analogRead(PIN_ANLG);
  val_lpfd[0] = lpf(val_raw[0]);
  Serial.print("raw:");
  Serial.print(val_raw[0]);
  Serial.print(",");
  Serial.print("LPfiltered:");
  Serial.print(val_lpfd[0]);
  delay(1000 / RATE_SAMPLE);
}]

void queueue() {
  // AULD 9 ... 0 LAST
  short c = 0;
  for (c = SIZE_WINDOWS - 1; c >= 1; --c) {
    val_raw[c] = val_raw[c - 1];
    val_lpfd[c] = val_lpfd[c - 1];
  }
  val_raw[0] = 0;
  val_lpfd[0] = 0;
}

float lpf(float z) {
  return (1 - c) * val_lpfd[1] + c * val_raw[0];
}


float movavg(float z) {
  short c;
  float v = 0;
  for (c = 0; c <= SIZE_WINDOWS - 1; c++) {
    v += val_raw[c];
  }
  return v / SIZE_WINDOWS;
}