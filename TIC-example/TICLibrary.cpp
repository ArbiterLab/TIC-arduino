#include <Arduino.h>
#include <SoftwareSerial.h>
#include "TICLibrary.h"
#include "ArduinoJson.h"

#ifndef TIC_h
#define TIC_h

SoftwareSerial TIConnect(2, 3);
DynamicJsonBuffer _jsonBuffer;
String temp1 = "";

TICLibrary::TICLibrary(int Tx, int Rx) {
  _Tx = Tx;
  _Rx = Rx;
}

void TICLibrary::begin() {
  TIConnect.begin(9600);
}

bool TICLibrary::dataStream() {
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

String TICLibrary::getParams(void) {
  JsonObject& _jsonObject = _jsonBuffer.parseObject(temp1);
  return _jsonObject["params"].asString();
}

#endif
