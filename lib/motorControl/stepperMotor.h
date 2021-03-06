#include <boardInterface.h>

class stepperMotor
{
    public:
        stepperMotor( PINS in1, PINS in2, PINS in3, PINS in4 ):
            in1(in1), in2(in2), in3(in3), in4(in4)

        {
            setPinMode(in1,  PinMode::output);
            setPinMode(in2,  PinMode::output);
            setPinMode(in3,  PinMode::output);
            setPinMode(in4,  PinMode::output);
        }

        void spinToAngle( unsigned short angle );

    private:
        PINS in1; 
        PINS in2; 
        PINS in3; 
        PINS in4; 
        unsigned short angle = 0;
        unsigned char activePhases = 0x01;
        void moveOneStep(bool dir);
        void moveSteps(bool dir, unsigned short steps);

};