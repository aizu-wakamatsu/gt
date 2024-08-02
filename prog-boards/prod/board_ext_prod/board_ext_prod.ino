/*
 * prog_board2.ino
 *
 * Operating mode:
 * |TRIGGERED mode (external clock)
 * Data transfer:
 * | USB-SERIAL
 * Depend:
 * | Header file:
 * || "def_board.h" "conf.h"
 * | Shield:
 * || SEN0213 ECG Measuring module
 *
 * 複数台のボードで同時にサンプリングするときに使うコード
*/


#include "def_board.h"
#include "conf.h"

// raw value from sensor (0-1023)
unsigned short x;

// setup(): Initialise board and do measurement.

void setup() {
  Serial.begin(RATE_BAUD);
  Serial.println("---START---");
  measure();
}

// loop(): Terminate the program.

void loop() {
  terminate();
}

// measure(): Measure ECG data from ECG shield.

void measure() {
  unsigned int count = 1;
  unsigned long tm = 0;

  while (count <= size_records) {
    while (true) {
      if (digitalRead(PIN_TRIG)) {  // wait for clock HIGH
        break;
      }
    }
     if (count == 0) {
       tm = millis();
     }
    x = (float)analogRead(PIN_ANLG);
    printValue();  // print to file
    count++;
    while (true) {
      if (!digitalRead(PIN_TRIG)) {  //wait for clock LOW
        break;
      }
    }
  }
  Serial.println("---END---");
  Serial.print("[INFO] ");
  Serial.print(millis() - tm);
  Serial.println("ms elapsed.");  // measuring time + α(time to send END signal to computer)
}

// printValue(): Send raw ECG data to computer using serial connection.

void printValue() {
    Serial.println(x);
}


// terminate(): Show "END" signal to tell user end of measuring.

void terminate() {
  while (1) {
  }
}
