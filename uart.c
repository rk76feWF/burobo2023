#include <xc.h>
#include "user.h"

queue_t u1;

void U1_setup(long);
void U2_setup(long);

void UART_setup(void)
{
    U1_setup(38400);
    U2_setup(115200);

    return;
}

void U1_setup(long BRG)
{
    _TRISD11 = 0; // TX pin
    _TRISD0 = 1;  // RX pin
    _RP12R = 3;   // TX pin
    _U1RXR = 11;  // RX pin

    U1MODE = 0x0000;
    U1STA = 0x0000;
    U1MODEbits.BRGH = 1; // High speed
    U1BRG = (FCY / (4 * BRG)) - 1;

    _U1RXIE = 1; // Enable RX interrupt
    _U1RXIF = 0; // Clear RX interrupt flag
    _U1RXIP = 7; // Set RX interrupt priority

    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1;   // Enable TX

    return;
}

void U2_setup(long BRG)
{
    _TRISD8 = 0; // TX pin
    _TRISD9 = 1; // RX pin
    _RP2R = 5;   // TX pin
    _U2RXR = 4;  // RX pin

    U2MODE = 0x0000;
    U2STA = 0x0000;
    U2MODEbits.BRGH = 1; // High speed
    U2BRG = (FCY / (4 * BRG)) - 1;

    _U2RXIE = 1; // Enable RX interrupt
    _U2RXIF = 0; // Clear RX interrupt flag
    _U2RXIP = 7; // Set RX interrupt priority

    U2MODEbits.UARTEN = 1; // Enable UART
    U2STAbits.UTXEN = 1;   // Enable TX

    return;
}

void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
{
    enqueue(&u1, U1RXREG);
    TMR2 = 0x0000;

    _U1RXIF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
{
    U2TXREG = U2RXREG;

    _U2RXIF = 0;
}

void prints(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int length = vsnprintf(NULL, 0, format, args) + 1;
    char buffer[length];

    vsnprintf(buffer, length, format, args);

    for (int i = 0; i < length - 1; i++)
    {
        while (U2STAbits.TRMT == 0)
            ;
        U2TXREG = buffer[i];
    }

    va_end(args);
    return;
}
