#ifndef FUNCTION_H
#define FUNCTION_H

void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);
void int_divide(float a, float b);

void execute(void (*func)(float, float), float a, float b);

#endif