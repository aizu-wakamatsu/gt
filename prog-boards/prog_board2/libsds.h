/* libsds.h
 * use with Seeed SD shield.
 * 
 * Depend: <SPI.h> <SD.h> "libblinkgpios.h"
*/

// #define DEBUG

const String FILENAME = "data";
const String FILEEXTS = ".csv";

#include <SPI.h>
#include <SD.h>

void open_file(void);
void fail(void);
extern void morse(char);

File wfile;

void begin_sd() {
  if (!SD.begin(PIN_CSSDS)) {
#ifdef DEBUG
    Serial.println("[WARN] FAILED TO BEGIN SD I/F");
#endif
    fail();
  }

  open_file();
}

void fail() {
  while (1) {
    morse('F');
    morse(' ');
    delay(1000);
  }
}

void open_file() {
  static short n = 0;
#ifdef DEBUG
  Serial.println("[INFO] Recursion count of open_file(): " + n);
#endif
  if (SD.exists(FILENAME + n + FILEEXTS)) {
    n++;
    open_file();
  } else {
    wfile = SD.open(FILENAME + n + FILEEXTS, FILE_WRITE);
    if (!wfile) {
#ifdef DEBUG
      Serial.println("[WARN] FILE CREATE FAILED: " + FILENAME + n + FILEEXTS);
#endif
      fail();
    }
#ifdef DEBUG
    Serial.println("[INFO] File created for write.");
    Serial.println("[INFO] FILENAME: " + FILENAME + n + FILEEXTS);
#endif
  }
}

void end_sd() {
  wfile.close();
#ifdef DEBUG
  Serial.println("[INFO] FILE CLOSED");
#endif
}