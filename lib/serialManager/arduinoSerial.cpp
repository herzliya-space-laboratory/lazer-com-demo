#include "arduinoSerial.h"
#include "Arduino.h"

int arduinoSerial::establishConnection(int datarate){
    Serial.begin(datarate);
    return 0;
}

int arduinoSerial::sendData(char* data){
    Serial.println(data);
    return 0;
}

int arduinoSerial::readData(char** data){
    data = Serial.readString();
    return 0;
}


