#include <stepperMotor.h>
#include <boardInterface.h>
#include "arduinoSerial.h"


#define MOTOR_IN1 PINS::pin11
#define MOTOR_IN2 PINS::pin10
#define MOTOR_IN3 PINS::pin9
#define MOTOR_IN4 PINS::pin8

stepperMotor motor(MOTOR_IN1, MOTOR_IN2, MOTOR_IN3, MOTOR_IN4);

void setup() 
{
  setPinMode(PINS::LEDBuiltIn,  PinMode::output);
}

void loop() 
{
  digitalWriteTo(PINS::LEDBuiltIn, PinState::high);
  delayMilliseconds(50);
  digitalWriteTo(PINS::LEDBuiltIn, PinState::low);
  delayMilliseconds(50);
  
  arduinoSerial ardSerial = new arduinoSerial();
  char* buff;
  ardSerial.establishConnection(9600);
  ardSerial.readData(&buff);
  motor.spinToAngle((int)buff);
  ardSerial.sendData("sucssess");
}

int main()
{
  initBoard(true); // this is needed
  setup();
  

  for ( ;; )
    loop();
}