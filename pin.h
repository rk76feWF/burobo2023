/*
 * File:   pin.h
 * Author: rk76fewf
 *
 * Created on March 16, 2023, 2:29 AM
 */

#ifndef PIN_H
#define PIN_H

// LED2
#define LED2 _LATB13
#define LED2_SetLow() LED2 = 0
#define LED2_SetHigh() LED2 = 1
#define LED2_Toggle() LED2 ^= 1

// LED3
#define LED3 _LATB12
#define LED3_SetLow() LED3 = 0
#define LED3_SetHigh() LED3 = 1
#define LED3_Toggle() LED3 ^= 1

// LAN1
#define M1S1 _LATA2
#define M1S2 _LATA3
#define M2S1 _LATB5
#define M2S2 _LATA4
// LAN2
#define M3S1 _LATA1
#define M3S2 _LATB2
#define M4S1 _LATB13
#define M4S2 _LATB3

#endif /* PIN_H */
