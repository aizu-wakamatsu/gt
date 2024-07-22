/*
 * prog_board1.ino
 *
 * Operating mode:
 * |STANDALONE mode (internal clock)
 * Data transfer:
 * |USB-SERIAL
 * Depend:
 * |Header file:
 * |"def_board.h" "conf.h"
 *
 * 単独でサンプリングするときに使うコード
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
#ifdef DEBUG
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
}

// loop(): Send "END" signal.

void loop() {
#ifdef DEBUG
  Serial.println("[INFO] END OF PROGRAM -- NOTHING TO DO");
#endif
  terminate();
}

// measure(): Measure ECG data from ECG shield.

void measure() {
#ifdef DEBUG
  Serial.println("[INFO] Function measure()");
#endif
  unsigned int size_records = SEC_MEASURE * RATE_SAMPLE;  // total count of sample
  double delay_target = 1000.00 / RATE_SAMPLE;            // delay ms per sample
  unsigned int count = 1;
  unsigned long time_now = 0;
#ifdef DEBUG
  Serial.print("[INFO] Record size: ");
  Serial.println(size_records);
  Serial.print("[INFO] Time per sample: ");
  Serial.print(delay_target);
  Serial.println("ms");
#endif
  unsigned long time_start = millis();
  while (count <= size_records) {
    x = (float)analogRead(PIN_ANLG);
    printValue();  // print to file
    while (millis() < time_start + (int)delay_target * count) {
#ifdef DEBUG
      if (millis() % 100 == 0) {
        Serial.print("[INFO] System time: ");
        Serial.print(millis());
        Serial.println("msec");
      }
#endif
    }
    time_now = millis();
    count++;
  }
  Serial.println("---END---");
  Serial.print("[INFO] ");
  Serial.print(time_now - time_start);
  Serial.println("ms elapsed.");
}

// printValue(): Send raw ECG data to computer using serial connection.

void printValue() {
  // static unsigned int c = 0;
  // if (c == 0) {
  //   //Serial.println("x,y");
  //   c++;
  // } else {
#ifdef DEBUG
    Serial.print("[INFO] VALUE x:");
    Serial.print(c);
    Serial.print(", y:");
    Serial.println(x);
#endif
    //Serial.print(c);
    //Serial.print(",");
    Serial.println(x);
  //   c++;
  // }
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
