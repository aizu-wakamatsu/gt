/*
  main.ino
*/

//#include <Arduino_FreeRTOS.h>

#include <SPI.h>
#include <SD.h>
#include "main.h"

File wfile;

// use if filter process on board
//float x[SIZE_WINDOWS] = { 0 };
//float y[SIZE_WINDOWS] = { 0 };

float x;

// interval
unsigned long otime = 0;

// buffer for write
//short v[4000] = {0};

void setup() {
  Serial.begin(9600);
  param_coef();
  begin_sd();
  wfile = SD.open(FILENAME, FILE_WRITE);
  if (!wfile) {
    fail();
  }
}

void loop() {
  //float sum;
  otime = millis();
  //x[0] = (float)analogRead(PIN_ANLG);
  //printValu();
  measure();
  if (digitalRead(PIN_SW) == HIGH) {
    end();
  }
  //delay(1000 / RATE_SAMPLE);
  //for (int i = 0 ; i < 2000 ; i++){
  //  v[i] = i;
  //}
}

void measure() {
  int size_records = SECS_MEASURES * RATE_SAMPLE;
  int delay_target = 1000 / SECS_MEASURES;
  int count = 0;
  while (count < size_records) {
    x = (float)analogRead(PIN_ANLG);
    printValu();
    while (millis_now < delay_target) {
    }
  }
}

void printValu() {
  static int c = 0;
  if (c == 0) {
    wfile.println("count,raw,filtered");
    c++;
  }
  // Serial.print("x:");
  // Serial.print(x[0]);
  // Serial.print(",y:");
  // Serial.println(y[0]);
  // wfile.print(c);
  // wfile.print(",");
  // //wfile.print((1.0/(float)RATE_SAMPLE)*((float)c-1.0));
  // wfile.print(",");
  // wfile.print(x[0]);
  // wfile.print(",");
  // wfile.println(y[0]);
  c++;
}

void begin_sd() {
  if (!SD.begin(4)) {
    fail();
  }
}

void fail() {
  while (1) {
    morse('F');
    morse(' ');
    delay(1000);
  }
}

void end() {
  wfile.close();
  while (1) {
    morse('E');
    morse('N');
    morse('D');
    morse(' ');
  }
}

void morse(char l) {
  if (l == 'D') {
    digitalWrite(PIN_LED, HIGH);
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
  }
  if (l == 'E') {
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == 'F') {
    digitalWrite(PIN_LED, HIGH);
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
  }
  if (l == 'N') {
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == 'S') {
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
  if (l == ' ') {
    delay(1000);
  }
  delay(1000);
}