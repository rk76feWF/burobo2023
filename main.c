#include <xc.h>
#include "config.h"
#include "user.h"

void setup(void);

int main(void)
{
    setup();
    while (1)
    {
        // LED_Toggle();
        prints("Hello World!\n");
        __delay_ms(500);
    }

    return 0;
}
