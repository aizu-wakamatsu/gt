/*
  testBPF.ino
  test for bandpass filter
*/

#include "config_testBPF.h"

float val_raw[SIZE_WINDOWS] = { 0 };
float val_lpfd;
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
  val_lpfd = lpf(val_raw[0]);
  val_hpfd = hpf(val_raw[0]);
  Serial.print("raw:");
  Serial.print(val_raw[0]);
  Serial.print(",");
  Serial.print("LPfiltered:");
  Serial.print(val_lpfd);
  Serial.print(",");
  Serial.print("HPfiltered:");
  Serial.print(val_hpfd);
  Serial.print(",");
  Serial.print("Mov Avg:");
  Serial.println(movavg(1));
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

float lpf(float z) {
  return powf((1.0 - powf(z, -6.0)), 2.0) / powf((1.0 - powf(z, -1.0)), 2.0);
}

float hpf(float z) {
  return (-1.0 + 32.0 * powf(z, -16.0)) + powf(z, -32.0) / (1.0 + powf(z, -1.0));
}

float movavg(float z) {
  short c;
  float v = 0;
  for (c = 0; c <= SIZE_WINDOWS - 1; c++) {
    v += val_raw[c];
  }
  return v / SIZE_WINDOWS;
}