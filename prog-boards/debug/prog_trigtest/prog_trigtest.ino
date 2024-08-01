/*
 * prog_trigtest_u1.ino

 * triggered sampling test for measurement module 1

 * triggered by trigger

 * Depend: "def_board.h" "conf.h"

*/

// Define DEBUG here to send debug message to computer.
// #define DEBUG


#include "def_board.h"
#include "conf.h"

// raw value from sensor (0-1023)
unsigned short x;

// setup(): Initialise board for measurement.

void setup() {
  Serial.begin(RATE_BAUD);
  Serial.println("[INFO] UNIT NO: 1");
  Serial.println("---START---");
  start();
  measure();
}

// loop(): Do nothing. (called after measurement finished)

void loop() {
  terminate();
}

// measure(): Measure ECG data from ECG shield. (but this is not sent to host computer.)

void measure() {
  unsigned int size_records = SECS_MEASURES * RATE_SAMPLE;  // total count of sample
  double delay_target = 1000.00 / RATE_SAMPLE;              // delay ms per sample
  unsigned int count = 0;
  unsigned long ms_delay = 0;
  unsigned long tm = millis();
  while (count <= size_records) {
    while (true) {
      if (digitalRead(PIN_TRIG) == HIGH) {
        break;
      }
    }
    x = (float)analogRead(PIN_ANLG);
    printValu();  // print to file
    count++;
  }
  Serial.println("---END---");
  Serial.print("[INFO] ");  // display the total time elapsed to sample
  Serial.print(millis() - tm);
  Serial.println("ms elapsed.");
}

// printValu(): Send raw ECG data to computer using serial connection.

void printValu() {  // must be called once at setup
  static unsigned int c = 0;
  if (c == 0) {
    c++;
  } else if (c % 2 == 0) {  // count is even, send "O"
    Serial.println('O');
    c++;
  } else {
    Serial.println('X');  // count is odd, send "X"
    c++;
  }
}

// start(): Wait DELAY_STARTS seconds before measuring.

void start() {
  int waitss = DELAY_STARTS * RATE_SAMPLE;
  int count_delays = 0;
  for (count_delays = 0; count_delays <= waitss; count_delays++) {
    while (!digitalRead(PIN_TRIG)) {
    }
  }

  //delay(DELAY_STARTS * 1000 - 9000);  // take DELAY_STARTS seconds to send morse signal "START"
}

void terminate() {
  while (1) {
  }
}