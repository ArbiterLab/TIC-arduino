/*
Copyright (c) 2017 Arbiter Lab
See the file license.txt for copying permission.
maintainer - podcastm1 (Tommy Kim : laino@laino.ml)


TIC-example.ino - Created by Taeil Kim (Tommy Kim)
Trust IoT Connction Library
*/

#include "TICLibrary.h"
#include "ArduinoJson.h"

TICLibrary test(2,3);

void setup() {

  test.begin();
  Serial.begin(9600);
}

void play() {
  Serial.println("play");
}

void stop1() {
  Serial.println("stop");
}

void loop() {
  if(test.dataStream()) {
    Serial.println("Data Recevied");
      if (test.getPath() == "/api/music") {
        if(test.getParams(0,"status") == "/play") {
          play();
        } else if (test.getParams(0,"status") == "/stop") {
          stop1();
        }
      }
  }
}
