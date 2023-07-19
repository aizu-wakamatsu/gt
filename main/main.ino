/*
  main.ino

  Error: .._.: fail to load SD card
*/

//#include <Arduino_FreeRTOS.h>

#define DEBUG

#include <SPI.h>
#include <SD.h>
#include "main.h"

File wfile;

// use if filter process on board
//float x[SIZE_WINDOWS] = { 0 };
//float y[SIZE_WINDOWS] = { 0 };

short x;

// interval
unsigned long otime = 0;

// buffer for write
//short v[4000] = {0};

void setup() {
#ifdef DEBUG
  Serial.println("BOOT SYSTEM 'D");
#endif
  Serial.begin(250000);
  //param_coef();
  begin_sd();
#ifdef DEBUG
  Serial.println("BEGIN SD 'D");
#endif
  wfile = SD.open(FILENAME, FILE_WRITE);
  if (!wfile) {
    fail();
  }
//otime = millis();
#ifdef DEBUG
  Serial.println("READY");
#endif
  start();
#ifdef DEBUG
  Serial.println("START MEASURE");
#endif
  measure();
#ifdef DEBUG
  Serial.println("END");
#endif
  end();
}

void loop() {
  //float sum;
  //x[0] = (float)analogRead(PIN_ANLG);
  //printValu();

  // if (digitalRead(PIN_SW) == HIGH) {
  //   end();
  // }
  //delay(1000 / RATE_SAMPLE);
  //for (int i = 0 ; i < 2000 ; i++){
  //  v[i] = i;
  //}
}

void measure() {
  int size_records = SECS_MEASURES * RATE_SAMPLE;  // total count of sample
  int delay_target = 1000 / RATE_SAMPLE;           // delay ms per sample
  int count = 0;
  int ms_delay = 0;
  while (count < size_records) {
    ms_delay = millis() + delay_target;
    x = (float)analogRead(PIN_ANLG);
    printValu();
    while (millis() < ms_delay) {
#ifdef DEBUG
      Serial.println(millis());
#endif
    }
    count++;
  }
}


void printValu() {  // must be called once at setup
  static int c = 0;
  if (c == 0) {
    wfile.println("x,y");
  }
  // Serial.print("x:");
  // Serial.print(x[0]);
  // Serial.print(",y:");
  // Serial.println(y[0]);

  wfile.print(c);
  wfile.print(",");
  wfile.println(x);
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

void start() {
  morse('S');
  morse('T');
  morse('A');
  morse('R');
  morse('T');
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
  if (l == 'A') {
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
  }
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
  if (l == 'R') {
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
  if (l == 'T') {
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == ' ') {
    delay(1000);
  }
  delay(1000);
}