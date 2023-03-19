/*
 * File:   function.h
 * Author: rk76fewf
 *
 * Created on March 16, 2023, 3:30 AM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

void setup(void);

void UART_setup(void);
void prints(const char *, ...);

void timer_setup(void);

void PWM_setup(void);
void motor_setup(void);
int motor_set(int, double);
void motor_stop(void);
void polar_to_omni4_duty(ps3_t *, double *);
void move(ps3_t *ps3);

#endif /* FUNCTION_H */
