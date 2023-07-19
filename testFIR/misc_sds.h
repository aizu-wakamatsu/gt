#include <SD.h>
#include <SPI.h>

File wfile;

void begin_sd() {
  if (!SD.begin(4)) {
    fail();
  }
}

void fail() {
  while (1) {
    digitalWrite(PIN_LED, HIGH);  // F
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
    delay(1000);
  }
}

void end() {
  wfile.close();
  while (1) {
    digitalWrite(PIN_LED, HIGH);  // E
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    digitalWrite(PIN_LED, HIGH);  // N
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    digitalWrite(PIN_LED, HIGH);  // D
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
    delay(2000);
  }
}

void led_start() {
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