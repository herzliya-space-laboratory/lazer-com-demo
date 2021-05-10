#include "serialManager.h"

class arduinoSerial : serialManager{
    int establishConnection(int datarate);

    int readData(char** buff);

    int sendData(char* data);
};
