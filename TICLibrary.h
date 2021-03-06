/*
TIC_library.h - Created by Taeil Kim
Trust IoT Connction Library
*/
#ifndef TIC_h
#define TIC_h

#include <Arduino.h>
#include "ArduinoJson.h"
#include <SoftwareSerial.h>
#include <Wire.h>

class TICLibrary {
public:
  TICLibrary(int Tx, int Rx);
  void begin(void);
  void isValuedData(void);
  String getPath(void);
  String getParams(int pram1, String getB);
  bool dataStream(void);
  bool valuedData(void);
  SoftwareSerial TIConnect;
  void sendData(JsonObject& data);

private:
  int _Tx, _Rx = 0;
  String _inputdata = "";

};

#endif
