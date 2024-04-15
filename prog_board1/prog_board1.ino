/*
 * prog_board1.ino
 *
 * Operating mode:
 * |STANDALONE mode (internal clock)
 * Data transfer:
 * |USB-SERIAL
 * Depend:
 * |Header file:
 * |"def_board.h" "libblinkgpios.h" "conf.h"
 * |External hardware:
 * |FaBo shield (to indicate status)
 *
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
  morse('T');
  Serial.begin(RATE_BAUD);
  Serial.println("---START---");
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
  unsigned int size_records = SECS_MEASURES * RATE_SAMPLE;  // total count of sample
  double delay_target = 1000.00 / RATE_SAMPLE;              // delay ms per sample
  unsigned int count = 0;
  unsigned long ms_delay = 0;
#ifdef DEBUG
  Serial.print("[INFO] Record size: ");
  Serial.println(size_records);
  Serial.print("[INFO] Time per sample: ");
  Serial.print(delay_target);
  Serial.println("ms");
#endif
  unsigned long tm = millis();
  while (count <= size_records) {
    // ms_delay = millis() + delay_target;
    ms_delay = millis();
    x = (float)analogRead(PIN_ANLG);
    printValu();  // print to file
    while (millis() < tm+ ++count) {
#ifdef DEBUG
      if (millis() % 100 == 0) {
        Serial.print("[INFO] System time: ");
        Serial.print(millis());
        Serial.println("msec");
      }
#endif
    }
    count++;
  }
  Serial.println("---END---");
  Serial.print("[INFO] ");
  Serial.print(millis() - tm);
  Serial.println("ms elapsed.");
}

// printValu(): Send raw ECG data to computer using serial connection.

void printValu() {  // must be called once at setup
  static unsigned int c = 0;
  if (c == 0) {
    //Serial.println("x,y");
    c++;
  } else {
#ifdef DEBUG
    Serial.print("[INFO] VALUE x:");
    Serial.print(c);
    Serial.print(", y:");
    Serial.println(x);
#endif
    //Serial.print(c);
    //Serial.print(",");
    Serial.println(x);
    c++;
  }
}

// start(): Wait 10 seconds before measuring.

void start() {
  delay(DELAY_STARTS * 1000 - 9000);  // take 9 seconds to send morse signal "START"
  morse('S');
  morse('T');
  morse('A');
  morse('R');
  morse('T');
}

// terminate(): Show "END" signal to tell user end of measuring.

void terminate() {
  while (1) {
    morse('E');
    morse('N');
    morse('D');
    morse(' ');
  }
}