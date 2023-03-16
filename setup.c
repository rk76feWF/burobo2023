#include <xc.h>
#include "user.h"

void setup(void)
{
    OSCCON = 0x0000;
    CLKDIV = 0x0000;
    ANSB = 0x0000;
    ANSC = 0x0000;
    ANSD = 0x0000;
    ANSE = 0x0000;
    ANSF = 0x0000;
    ANSG = 0x0000;

    TRISB = 0xffff;
    TRISC = 0xffff;
    TRISD = 0xffff;
    TRISE = 0xffff;
    TRISF = 0xffff;
    TRISG = 0xffff;

    _TRISB13 = 0; // LED2
    _TRISB12 = 0; // LED3

    // UART_setup();
    // TIMER_setup();
    MOTOR_setup();
    // PWM_setup();

    return;
}
