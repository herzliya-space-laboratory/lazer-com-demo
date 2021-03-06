#pragma once

enum PinState : unsigned int
{
    low = 0,
    high = 1,
};

enum PinMode : unsigned int
{
    input = 0,
    output = 1,
    input_pullup = 2
};

enum PINS : unsigned int
{
    pin0 = 0,
    pin1 = 1,
    pin2 = 2,
    pin3 = 3,
    pin4 = 4,
    pin5 = 5,
    pin6 = 6,
    pin7 = 7,
    pin8 = 8,
    pin9 = 9,
    pin10 = 10,
    pin11 = 11,
    pin12 = 12,
    pin13 = 13,
    LEDBuiltIn = 13,

    pinAIn0 = 14,
    pinAIn1 = 15,
    pinAIn2 = 16,
    pinAIn3 = 17,
    pinAIn4 = 18,
    pinAIn5 = 19,
};

void setPinMode(PINS pinToSet, PinMode modeToSet);
void digitalWriteTo(PINS pinToSet, PinState stateToSet);
int digitalReadFrome(PINS pinToRead);
int analogReadFrom(PINS pinToRead);
void analogWriteTo(PINS pinToSet, int valueToSet);
void delayMilliseconds(unsigned long ms);
void delayForMicroseconds(unsigned int us);
unsigned long GetMicros(void);
unsigned long Getmillis(void);

void initBoard(bool useSerial = false, int srialRate = 9600);

void logInfo(const char *msg, const char *file, int line);
float askForFloatData(int dataType);
int askForIntData(int dataType);

#define log(msg) logInfo(msg, __FILE__, __LINE__)