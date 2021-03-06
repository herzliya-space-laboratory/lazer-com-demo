#include "stepperMotor.h"

#define stepsInCycle 2048
#define calcDeltaAngle(dir, start, end) \
        (-1 * !dir + dir) * \
        ((int)end - (int)start)

void stepperMotor::spinToAngle( unsigned short angle )
{
    if( angle == this->angle || angle > 360) return;

    bool dir = angle > this->angle;
    unsigned short deltaAngle = calcDeltaAngle(dir, this->angle, angle);

    unsigned short steps = (unsigned short)((float)deltaAngle / 360 * stepsInCycle);
    moveSteps(dir, steps);

    this->angle = angle;
}


void stepperMotor::moveSteps(bool dir, unsigned short steps) {
    while ( steps-- <=  stepsInCycle) {
        moveOneStep(dir); 
        delayMilliseconds(2);
    }
}

void stepperMotor::moveOneStep(bool dir) {
    activePhases = 
        dir * ( 
            (activePhases == 0x08) * 0x01 + 
            ((activePhases != 0x08) * activePhases << 1 )) + 
        !dir * ( 
            (activePhases == 0x01) * 0x08 + 
            ((activePhases != 0x01) * activePhases >> 1) );

    digitalWriteTo(in1, (activePhases & 0x01) ? PinState::high: PinState::low);
    digitalWriteTo(in2, (activePhases & 0x02) ? PinState::high: PinState::low);
    digitalWriteTo(in3, (activePhases & 0x04) ? PinState::high: PinState::low);
    digitalWriteTo(in4, (activePhases & 0x08) ? PinState::high: PinState::low);
}