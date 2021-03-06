#include "Arduino.h"
#include "ardunoFacade.h"


void setPinMode(PINS pinToSet, PinMode modeToSet)
{
    pinMode(pinToSet, modeToSet);
}


void digitalWriteTo(PINS pinToSet, PinState stateToSet)
{
    digitalWrite(pinToSet, stateToSet);
}

int digitalReadFrome(PINS pinToRead)
{
    return digitalRead(pinToRead);
}

int analogReadFrom(PINS pinToRead)
{
    return analogRead(pinToRead);
}


void analogWriteTo(PINS pinToSet, int valueToSet)
{
    analogWrite(pinToSet, valueToSet);
}


unsigned long Getmillis(void)
{
    return millis();
}

unsigned long GetMicros(void)
{
    return micros();
}

void delayMilliseconds(unsigned long ms)
{
    delay(ms);
}


void delayForMicroseconds(unsigned int us)
{
    delayMicroseconds(us);    
}

void initBoard(bool useSerial, int srialRate){
    init();

    if(useSerial)
        Serial.begin(srialRate);
}

void logInfo(const char *msg, const char *file, int line)
{
    char buffer[256];
    sprintf(buffer, "( %s ): %s:%d", msg, file, line);

    Serial.println(buffer);
}


float askForFloatData(int dataType)
{
    
    Serial.write(dataType);
    return (float)Serial.read();
}

int askForIntData(int dataType)
{
    
    Serial.write(dataType);
    return (int)Serial.read();
}