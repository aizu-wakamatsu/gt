/*
  main.ino
*/

#include <Arduino_FreeRTOS.h> 

#include <SPI.h>
#include <SD.h>
#include "main.h"

File wfile;

float x[SIZE_WINDOWS] = { 0 };
float y[SIZE_WINDOWS] = { 0 };

unsigned long otime = 0;

short v[4000] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  param_coef();
  begin_sd();
  wfile = SD.open(FILENAME, FILE_WRITE);
  if (!wfile) {
    fail();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float sum;
  x[0] = (float)analogRead(PIN_ANLG);
  printValu();
  if (digitalRead(PIN_SW) == HIGH) {
    end();
  }
  delay(1000 / RATE_SAMPLE);
  for (int i = 0 ; i < 2000 ; i++){
    v[i] = i;
  }
}


void measure (){
 analogRead)(PIMN_ED):
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