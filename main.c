#include <xc.h>
#include "config.h"
#include "user.h"

extern ps3_t ps3;

int main(void)
{
    setup();

    while (1)
    {
        if (ps3.connected)
            move(&ps3);
        else
            motor_stop();
    }

    return -1;
}
