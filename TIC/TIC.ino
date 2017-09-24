#include <SoftwareSerial.h>

SoftwareSerial bleCon(2,3); // Rx, Tx

void setup() {
  // put your setup code here, to run once:
  bleCon.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
