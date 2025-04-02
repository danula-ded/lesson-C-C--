#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);
void int_divide(int a, int b);
void modulus(int a, int b);

void execute(void (*func)(float, float), float a, float b);

#endif