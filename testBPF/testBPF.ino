#include "config_testBPF.h"

double val_raw[10];
double hz;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  queueue();
  val_raw[0] = (double)analogRead(PIN_ANLG);
  Serial.println(val_raw[0]);
  delay(10);
}

void queueue(){
  short c = 0;
  for(c = SIZE_WINDOWS - 1 ; c >= 1 ; --c){
    val_raw[c] = val_raw[c];
  }
}

