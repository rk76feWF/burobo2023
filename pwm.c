#include <xc.h>
#include "user.h"

void OC1_setup(unsigned long);
void OC2_setup(unsigned long);
void OC3_setup(unsigned long);
void OC4_setup(unsigned long);
void OC5_setup(unsigned long);
void OC6_setup(unsigned long);
void OC7_setup(unsigned long);
void OC8_setup(unsigned long);

void PWM_setup(void)
{
    OC1_setup(50000);
    OC2_setup(50000);
    OC3_setup(50000);
    OC4_setup(50000);
    OC5_setup(50000);
    OC6_setup(50000);
    OC7_setup(50000);
    OC8_setup(50000);

    return;
}

void OC1_setup(unsigned long freq)
{
    OC1CON1 = 0b0001110000000110;
    OC1CON2 = 0b0000000000011111;

    _RP18R = 18; // LAN1 7pin
    OC1R = 0;
    OC1RS = (int)(FCY / freq);

    return;
}

void OC2_setup(unsigned long freq)
{
    OC2CON1 = 0b0001110000000110;
    OC2CON2 = 0b0000000000011111;

    _RP27R = 19; // LAN1 8pin
    OC2R = 0;
    OC2RS = (int)(FCY / freq);

    return;
}

void OC3_setup(unsigned long freq)
{
    OC3CON1 = 0b0001110000000110;
    OC3CON2 = 0b0000000000011111;

    _RP21R = 20; // LAN2 7pin
    OC3R = 0;
    OC3RS = (int)(FCY / freq);

    return;
}

void OC4_setup(unsigned long freq)
{
    OC4CON1 = 0b0001110000000110;
    OC4CON2 = 0b0000000000011111;

    _RP26R = 21; // LAN2 8pin
    OC4R = 0;
    OC4RS = (int)(FCY / freq);

    return;
}

void OC5_setup(unsigned long freq)
{
    OC5CON1 = 0b0001110000000110;
    OC5CON2 = 0b0000000000011111;

    _RP25R = 22; // LAN3 7pin
    OC5R = 0;
    OC5RS = (int)(FCY / freq);

    return;
}

void OC6_setup(unsigned long freq)
{
    OC6CON1 = 0b0001110000000110;
    OC6CON2 = 0b0000000000011111;

    _RP20R = 23; // LAN3 8pin
    OC6R = 0;
    OC6RS = (int)(FCY / freq);

    return;
}

void OC7_setup(unsigned long freq)
{
    OC7CON1 = 0b0001110000000110;
    OC7CON2 = 0b0000000000011111;

    _RP23R = 24; // LAN4 7pin
    OC7R = 0;
    OC7RS = (int)(FCY / freq);

    return;
}

void OC8_setup(unsigned long freq)
{
    OC8CON1 = 0b0001110000000110;
    OC8CON2 = 0b0000000000011111;

    _RP22R = 25; // LAN4 8pin
    OC8R = 0;
    OC8RS = (int)(FCY / freq);

    return;
}
