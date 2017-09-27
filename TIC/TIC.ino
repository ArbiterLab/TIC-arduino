#include <SoftwareSerial.h>

SoftwareSerial bleCon(2,3); // Rx, Tx

void setup() {
  bleCon.begin(9600);
  Serial.begin(9600);
}

void loop() {

}
