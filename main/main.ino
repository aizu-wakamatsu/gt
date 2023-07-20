/*
  main.ino

  Depend: "libsds.h" "libblinkgpios.h" "conf.h"

  Error: .._.(F): fail to load SD card
*/

//#include <Arduino_FreeRTOS.h>

// define DEBUG to send debug message to serial
// #define DEBUG

#include "def_board.h"
#include "libsds.h"
#include "libblinkgpios.h"
#include "conf.h"


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
  Serial.begin(RATE_BAUD);
  Serial.println("[INFO] HELLO");
#endif
  //param_coef();
  begin_sd();
#ifdef DEBUG
  Serial.println("[INFO] SD Card OK");
  Serial.println("[INFO] READY");
#endif
  start();
#ifdef DEBUG
  Serial.println("[INFO] Start measurement......NOW!");
#endif
  measure();
#ifdef DEBUG
  Serial.println("[INFO] Measurement finished.");
#endif
  end_sd();
}

void loop() {
#ifdef DEBUG
  Serial.println("[INFO] END OF PROGRAM -- NOTHING TO DO");
#endif
  terminate();
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
      if (millis() % 10 == 0) {
      Serial.print("[INFO] System time: ");
      Serial.print(millis());
      Serial.println("msec");
    }
#endif
  }
  count++;
}
}


void printValu() {  // must be called once at setup
  static int c = 0;
  if (c == 0) {
    wfile.println("x,y");
    c++;
  } else {
#ifdef DEBUG
    Serial.print("[INFO] VALUE x:");
    Serial.print(c);
    Serial.print(", y:");
    Serial.println(x);
#endif
    wfile.print(c);
    wfile.print(",");
    wfile.println(x);
    c++;
  }
}

void start() {
  morse('S');
  morse('T');
  morse('A');
  morse('R');
  morse('T');
}

void terminate() {
  while (1) {
    morse('E');
    morse('N');
    morse('D');
    morse(' ');
  }
}