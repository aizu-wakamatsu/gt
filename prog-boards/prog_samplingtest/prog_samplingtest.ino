/*
 * prog_samplingtest

 * Depend: "def_board.h" "libblinkgpios.h" "conf.h"

*/

// Define DEBUG here to send debug message to computer.
// #define DEBUG


#include "def_board.h"
#include "libblinkgpios.h"
#include "conf.h"

// raw value from sensor (0-1023)
unsigned short x;

// setup(): Initialise board for measurement.

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(RATE_BAUD);
  delay(10000);
  Serial.println("---START---");
  measure();
}

// loop(): Send "END" signal.

void loop() {
  terminate();
}

// measure(): Measure ECG data from ECG shield.

void measure() {
  unsigned int size_records = SECS_MEASURES * RATE_SAMPLE;  // total count of sample
  double delay_target = 1000.00 / RATE_SAMPLE;              // delay ms per sample
  unsigned int count = 0;
  unsigned long ms_delay = 0;
  unsigned long tm = millis();
  while (size_records > count) {
    ms_delay = millis();
    x = (float)analogRead(PIN_ANLG);
    printValu();  // print to file
    while (millis() < tm + ++count) {
    }
    count++;
  }
}

// printValu(): Send raw ECG data to computer using serial connection.

void printValu() {  // must be called once at setup
  static unsigned int c = 0;
  if (c == 0) {
    c++;
  } else {
    Serial.println(x);
    c++;
  }
}

void terminate() {
  while (1) {
    // do nothing
  }
}