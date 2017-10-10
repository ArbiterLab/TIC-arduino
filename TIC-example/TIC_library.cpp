#include <Arduino.h>
#include <SoftwareSerial>
#include "TIC_library.h"

TICLibrary::TICLibrary(int Tx, int Rx) {
    SoftwareSerial TIConnect(Tx, Rx);
    TIConnect.begin(9600);
}
