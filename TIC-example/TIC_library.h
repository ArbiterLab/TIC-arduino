/*
TIC_library.h - Created by Taeil Kim
Trust IoT Connction Library
 */

#ifndef TICLibrary_h
#define TICLibrary_h

#include <Arduino.h>
#include "ArduinoJson.h"
#include <SoftwareSerial.h>

class TICLibrary {
public:
  TICLibrary(int Tx, int Rx);
  void begin(void);
  void isValuedData(void);
  String getPath(void);
  String getParams(void);
  JsonObject& getJsonObject(void);
  bool dataStream(void);
  bool isValuedData(void);



private:
  DynamicJsonBuffer _jsonBuffer;
  JsonObject& _jsonObject;
  int _Tx, _Rx = 0;
  String _inputdata = "";

};

#endif
