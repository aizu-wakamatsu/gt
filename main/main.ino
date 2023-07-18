/*
  india19.ino
  test for filter
*/

#include <SPI.h>
#include <SD.h>
#include "config_india19.h"

File wfile;

float x[SIZE_WINDOWS] = { 0 };
float y[SIZE_WINDOWS] = { 0 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  param_coef();
  begin_sd();
  wfile = SD.open(FILENAME, FILE_WRITE);
  if (!wfile) {
    fail();
  }
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
  delay(200);
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
  delay(200);
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sum;
  queueue();
  x[0] = (float)analogRead(PIN_ANLG);
  fir();
  printValu();
  if (digitalRead(PIN_SW) == HIGH) {
    end();
  }
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

void printValu() {
  static int c = 0;
  if (c == 0) {
    wfile.println("count,time,raw,filtered");
    c++;
  }
  Serial.print("x:");
  Serial.print(x[0]);
  Serial.print(",y:");
  Serial.println(y[0]);
  wfile.print(c);
  wfile.print(",");
  //wfile.print((1.0/(float)RATE_SAMPLE)*((float)c-1.0));
  wfile.print(",");
  wfile.print(x[0]);
  wfile.print(",");
  wfile.println(y[0]);
  c++;
}

void begin_sd() {
  if (!SD.begin(4)) {
    fail();
  }
}

void fail() {
  while (1) {
    digitalWrite(PIN_LED, HIGH); // F
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
  }
}

void end() {
  wfile.close();
  while (1) {
    digitalWrite(PIN_LED, HIGH);  // E
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    digitalWrite(PIN_LED, HIGH);  // N
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    digitalWrite(PIN_LED, HIGH);  // D
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(2000);
  }
}