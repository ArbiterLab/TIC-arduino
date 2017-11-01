#include "TIC_library.h"
#include "ArduinoJson.h"

void setup() {
  TIClibrary test(2,3);
  Serial.begin(9600);
}

void play() {
  Serial.println("asdf");
}

void stop() {
  Serial.println("asdfadsfsfdaf");
}

void loop() {
  if(test.dataStream()) {
    Serial.println("Data Recevied");
    if (isValuedData()) {
      if (getPath() == "/play") {
        if(getParams() == "/api/play") {
          play();
        } else if (getParams() == "/api/stop") {
          stop();
        }
      }
    }
  }
}
