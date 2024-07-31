/*
 * board_int_prod.ino
 *
 * Operating mode:
 * | STANDALONE mode (internal clock)
 * Data transfer:
 * | USB-SERIAL
 * Depend:
 * | Header file:
 * || "def_board.h" "conf.h"
 * | Shield:
 * || SEN0213 ECG Measuring module
 *
 * 単独でサンプリングするときに使うコード
*/

#include "def_board.h"
#include "conf.h"

// raw value from sensor (0-1023)
unsigned short x;

// setup(): Initialise board and do measurement.

void setup() {
  Serial.begin(RATE_BAUD);
  start();
  measure();
}

// loop(): Terminate the program.

void loop() {
  terminate();
}

// measure(): Measure ECG data from ECG shield.

void measure() {
  unsigned int size_records = SEC_MEASURE * RATE_SAMPLE;  // times: total count of sample
  double delay_target = 1000.00 / RATE_SAMPLE;            // ms   : delay ms per sample
  unsigned int count = 1;                                 // times: counter variable
  unsigned long time_start = millis();                    // ms   : measuring start time from boot
  unsigned long time_end = 0;                             // ms   : measuring end time from boot

  while (count <= size_records) {
    x = (float)analogRead(PIN_ANLG);
    printValue();  // send to computer
    while (millis() < time_start + (int)delay_target * count) {
      // wait for next sample
    }
    time_end = millis();
    count++;
  }
  Serial.println("---END---");
  Serial.print("[INFO] ");
  Serial.print(time_end - time_start);
  Serial.println("ms elapsed.");
}

// printValue(): Send raw ECG data to computer using serial connection.

void printValue() {
    Serial.println(x);
}

// start(): Wait [DELAY_START] seconds before measuring.

void start() {
  delay(DELAY_START * 1000);
  Serial.println("---START---");
}

// terminate(): Do nothing.

void terminate() {
  while (1) {
  }
}
