/*
Copyright (c) 2017 Arbiter Lab
See the file license.txt for copying permission.
maintainer - podcastm1 (Tommy Kim : laino@laino.ml)


TICLibrary.cpp - Created by Taeil Kim (Tommy Kim)
Trust IoT Connction Library
*/

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "TICLibrary.h"
#include "ArduinoJson.h"

#ifndef TIC_h
#define TIC_h

DynamicJsonBuffer _jsonBuffer;
String temp1 = "";

SoftwareSerial TIConnect(2, 3);// ->
//this method will be chaged please be careful
TICLibrary::TICLibrary(int Tx, int Rx) {
  _Tx = Tx;
  _Rx = Rx;
}

void TICLibrary::testData(void) {

}

void TICLibrary::begin(void) {
  TIConnect.begin(9600);
}

bool TICLibrary::dataStream(void) {
  if (TIConnect.available()) {
    while(TIConnect.available()) {
      char bufferChar = (char)TIConnect.read();
      _inputdata += bufferChar;
      delay(5);
    }
    if(!_inputdata.equals("")) {

      JsonObject& _jsonObject = _jsonBuffer.parseObject(_inputdata);
      temp1 = _inputdata;
      _inputdata = "";
      if (!_jsonObject.success()) {
        TIConnect.write("failed to parse json");
        return 0;
      }
      return 1;
    } else {
      TIConnect.write("no Recevied data");
      return 0;
    }
  } else {
    return 0;
  }
}

bool TICLibrary::valuedData(void) {
  return 1;
}

String TICLibrary::getPath(void) {
  JsonObject& _jsonObject = _jsonBuffer.parseObject(temp1);
  return _jsonObject["path"].asString();
}

String TICLibrary::getParams(int pram1, String getB) {
  JsonObject& _jsonObject = _jsonBuffer.parseObject(temp1);
  return _jsonObject["params"][pram1][getB].asString();
}

//this method will be duplicated
void TICLibrary::outputData(void) {
  JsonObject& _jsonObject = _jsonBuffer.parseObject(temp1);
  const char* output2 = _jsonObject["params"][0]["a"];
  Serial.println(output2);
}

#endif
