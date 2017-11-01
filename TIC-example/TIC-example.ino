#include "TICLibrary.h"
#include "ArduinoJson.h"

TICLibrary test(2,3);

void setup() {

  test.begin();
  Serial.begin(9600);
}

void play() {
  Serial.println("asdf");
}

void stop1() {
  Serial.println("asdfadsfsfdaf");
}

void loop() {
  if(test.dataStream()) {
    Serial.println("Data Recevied");
      if (test.getPath() == "/play") {
        Serial.println("test1");
        if(test.getParams() == "/api/play") {
          play();
        } else if (test.getParams() == "/api/stop") {
          stop1();
        }
      }
  }
}
