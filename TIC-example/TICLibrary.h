/*
TIC_library.h - Created by Taeil Kim
Trust IoT Connction Library
 */

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
  bool dataStream(void);
  bool valuedData(void);



private:
  int _Tx, _Rx = 0;
  String _inputdata = "";

};