/*
 * prog_board2.ino
 *
 * Operating mode:
 * |TRIGGERED mode (external clock)
 * Data transfer:
 * |USB-SERIAL
 * Depend:
 * |Header file:
 * |"def_board.h" "conf.h"
 * |External hardware:
 * |FaBo shield (optional, to indicate status)
 *
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
  Serial.println("---START---");
#ifdef DEBUG
  Serial.println("[INFO] READY");
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
  unsigned int count = 0;
#ifdef DEBUG
  Serial.print("[INFO] Record size: ");
  Serial.println(size_records);
#endif
  unsigned long tm = millis();
  while (count <= size_records) {
    while (true) {
      if(digitalRead(PIN_TRIG)){ // wait for clock HIGH
        break;
      }
    }
    x = (float)analogRead(PIN_ANLG);
    printValue();  // print to file
    count++;
        while (true) {
      if(!digitalRead(PIN_TRIG)){ //wait for clock LOW
        break;
      }
    }
  }
  Serial.println("---END---");
  Serial.print("[INFO] ");
  Serial.print(millis() - tm);
  Serial.println("ms elapsed.");// measuring time + α(time to send END signal to computer)
}

// printValue(): Send raw ECG data to computer using serial connection.

void printValue() {  // must be called once at setup
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


// terminate(): Show "END" signal to tell user end of measuring.

void terminate() {
  while (1) {

  }
}
