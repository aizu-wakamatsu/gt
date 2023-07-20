/* libblinkgpios.h
 * use with LED.
 * 
*/

void morse(char l) {
  if (l == 'A') { // ·-
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == 'D') { // -··
    digitalWrite(PIN_LED, HIGH);
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
  }
  if (l == 'E') { // ·
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == 'F') { // ··-·
    digitalWrite(PIN_LED, HIGH);
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
  }
  if (l == 'N') { // -·
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(200);
    digitalWrite(PIN_LED, HIGH);
    delay(200);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == 'R') { // ·-·
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
  }
  if (l == 'S') { // ···
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
  if (l == 'T') { // -
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
  }
  if (l == ' ') { // <space>
    delay(1000);
  }
  delay(1000);
}