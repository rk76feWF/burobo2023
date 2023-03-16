#include <xc.h>
#include "user.h"
#include <math.h>

void MOTOR_setup(void)
{
    // LAN1
    _TRISB6 = 0;
    _TRISB7 = 0;
    _TRISB2 = 0;
    _TRISB4 = 0;

    // LAN2
    _TRISE4 = 0;
    _TRISE5 = 0;
    _TRISE6 = 0;
    _TRISE7 = 0;

    return;
}

int motor(int number, double velocity)
{
    bool dir1, dir2;

    // velocity: -1.0 ~ 1.0
    if (velocity > 1.0 || velocity < -1.0)
        return -1;

    // direction
    if (velocity > 0.0)
        dir1 = 1, dir2 = 0;
    else if (velocity == 0.0)
        dir1 = 0, dir2 = 0;
    else
        dir1 = 0, dir2 = 1;

    switch (number)
    {
    case 1:
        M1S1 = dir1;
        M1S2 = dir2;
        OC1R = fabs(velocity) * OC1RS;
        break;
    case 2:
        M2S1 = dir1;
        M2S2 = dir2;
        OC2R = fabs(velocity) * OC2RS;
        break;
    case 3:
        M3S1 = dir1;
        M3S2 = dir2;
        OC3R = fabs(velocity) * OC3RS;
        break;
    case 4:
        M4S1 = dir1;
        M4S2 = dir2;
        OC4R = fabs(velocity) * OC4RS;
        break;
    default:
        return -2;
    }

    return 0;
}
