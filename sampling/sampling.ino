/*
  sampling.ino
  test for rate samples stable
*/

#define PIN_ANLG A0

const short SIZE_WINDOWS = 11;
const short RATE_SAMPLE = 250;

double x[SIZE_WINDOWS] = { 0 };
double y[SIZE_WINDOWS] = { 0 };

double coef[SIZE_WINDOWS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  set_param_fir_0l25();
}

void loop() {
  // put your main code here, to run repeatedly:
  queueue();
  x[0] = (double)analogRead(PIN_ANLG);
  fir();
  Serial.print("raw:");
  Serial.print(x[0]);
  Serial.print(",");
  Serial.print("LPfiltered:");
  Serial.println(y[0]);
  delay(1000 / RATE_SAMPLE);
}

void set_param_fir_0l25() {  // f=0.25
  coef[0] = 6.366197723675814e-02;
  coef[1] = -1.949085916259688e-17;
  coef[2] = -1.061032953945969e-01;
  coef[3] = 1.949085916259688e-17;
  coef[4] = 3.183098861837907e-01;
  coef[5] = 5.000000000000000e-01;
  coef[6] = 3.183098861837907e-01;
  coef[7] = 1.949085916259688e-17;
  coef[8] = -1.061032953945969e-01;
  coef[9] = -1.949085916259688e-17;
  coef[10] = 6.366197723675814e-02;
}

void queueue() {
  // AULD 9 ... 0 LAST
  short c = 0;
  for (c = SIZE_WINDOWS - 1; c >= 1; --c) {
    x[c] = x[c - 1];
    y[c] = y[c - 1];
  }
  x[0] = 0;
  y[0] = 0;
}

void fir() {
  short k = 0;
  for (k = 0; k < SIZE_WINDOWS; ++k) {
    y[0] += coef[k] * x[k];
  }
}