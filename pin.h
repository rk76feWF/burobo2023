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
#define M1S1 _LATB6
#define M1S2 _LATB7
#define M2S1 _LATB2
#define M2S2 _LATB4
// LAN2
#define M3S1 _LATE4
#define M3S2 _LATE5
#define M4S1 _LATE6
#define M4S2 _LATE7

// LAN3
#define M5S1 _LATE0
#define M5S2 _LATE1
#define M6S1 _LATE2
#define M6S2 _LATE3

// LAN4
#define M7S1 _LATD6
#define M7S2 _LATD7
#define M8S1 _LATF0
#define M8S2 _LATF1

#endif /* PIN_H */
