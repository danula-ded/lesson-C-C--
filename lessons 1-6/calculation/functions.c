#include <stdio.h>
#include "functions.h"

void add(float a, float b) {
       printf("%.2f + %.2f = %.2f\n", a, b, a + b);
   }
   
   void subtract(float a, float b) {
       printf("                            %.2f - %.2f = %.2f\n", a, b, a - b);
   }
   
   void multiply(float a, float b) {
       printf("%.2f * %.2f = %.2f\n", a, b, a * b);
   }
   
   void divide(float a, float b) {
       if (b == 0.0) {
           printf("Ошибка: деление на ноль!\n");
           return;
       }
       printf("%.2f / %.2f = %.2f\n", a, b, a / b);
   }
   
   void int_divide(float a, float b) {
       if (b == 0.0) {
           printf("Ошибка: деление на ноль!\n");
           return;
       }
       printf("%.0f // %.0f = %.0f\n", a, b, a / b);
   }

void execute(void (*func)(float, float), float a, float b) {
    return func(a, b);
}