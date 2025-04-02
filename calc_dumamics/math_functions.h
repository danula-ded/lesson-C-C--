#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

typedef void (*float_operation)(float, float);

void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);
void int_divide(int a, int b);
void modulus(int a, int b);
void power(float a, float b);
void compare(float a, float b);

void execute(void (*func)(float, float), float a, float b);
void execute_operations(float_operation ops[], int count, float a, float b);


#endif