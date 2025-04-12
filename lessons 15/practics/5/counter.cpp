#include "counter.h"

int Counter::count = 0;

Counter::Counter() {
    count++;
}

Counter::~Counter() {
    count--;
}

int Counter::getCount() {
    return count;
} 