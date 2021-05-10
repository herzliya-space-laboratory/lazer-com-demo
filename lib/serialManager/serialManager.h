#pragma once

#define USE_ARDUNO
#ifdef USE_ARDUNO
    #include "ardunoFacade.h"
#endif


class serialManager{

    virtual int establishConnection(int datarate) = 0;
    
    virtual int sendData(char* data) = 0;

    virtual int readData(char** buffer) = 0;
};

