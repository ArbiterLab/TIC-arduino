#include <Arduino.h>
#include <SoftwareSerial>
#include "TIC_library.h"

TICLibrary::begin(void) {
  SoftwareSerial TIConnect(_Tx, _Rx);
  TIConnect.begin(9600);
}

TICLibrary::TICLibrary(int Tx, int Rx) {
  _Tx = Tx;
  _Rx = Rx;
}

TICLibrary::dataStream(void) {
  if (TIConnect.available()) {
    while(TIConnect.available()) {
      char bufferChar = (char)TIConnect.read();
      _inputdata += bufferChar;
      delay(5);
    }
    if(!_inputdata.equals("")) {
      _jsonObject = _jsonBuffer.parseObject(_inputdata);
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

TICLibrary::getJsonObject(void) { //TODO :Test
  return _jsonBuffer;
}

TICLibrary::isValuedData(void) {
  if(_jsonObject["path"].asString().indexOf("path") > 0) { //TODO: null 작동하는지 확인
    return 1;
  } else {
    TIConnect.write("is not standard data");
    return 0;
  }
}

TICLibrary::getPath(void) {
  return _jsonObject["path"].asString();
}

TICLibrary::getParams(void) {
  return _jsonObject["location"].asString();
}
