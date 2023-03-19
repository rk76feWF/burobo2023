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

    // LAN3
    _TRISE0 = 0;
    _TRISE1 = 0;
    _TRISE2 = 0;
    _TRISE3 = 0;

    // LAN4
    _TRISD6 = 0;
    _TRISD7 = 0;
    _TRISF0 = 0;
    _TRISF1 = 0;

    return;
}

int motor_set(int number, double velocity)
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

    case 5:
        M5S1 = dir1;
        M5S2 = dir2;
        OC5R = fabs(velocity) * OC5RS;
        break;
    case 6:
        M6S1 = dir1;
        M6S2 = dir2;
        OC6R = fabs(velocity) * OC6RS;
        break;
    case 7:
        M7S1 = dir1;
        M7S2 = dir2;
        OC7R = fabs(velocity) * OC7RS;
        break;
    case 8:
        M8S1 = dir1;
        M8S2 = dir2;
        OC8R = fabs(velocity) * OC8RS;
        break;
    default:
        return -2;
    }

    return 0;
}

void motor_stop(void)
{
    motor_set(1, 0.0);
    motor_set(2, 0.0);
    motor_set(3, 0.0);
    motor_set(4, 0.0);
    motor_set(5, 0.0);
    motor_set(6, 0.0);
    motor_set(7, 0.0);
    motor_set(8, 0.0);

    return;
}
