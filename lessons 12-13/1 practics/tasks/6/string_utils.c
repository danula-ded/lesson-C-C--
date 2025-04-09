#include "string_utils.h"

int string_length(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void string_concat(char* dest, const char* src) {
    while (*dest) dest++;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
