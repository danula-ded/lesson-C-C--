#include "factorial_cache.h"

unsigned long long FactorialCache::getFactorial(int n) {
    if (n < 0) return 0; // Обработка отрицательных чисел
    
    // Поиск в кэше
    auto it = cache.find(n);
    if (it != cache.end()) {
        cacheHits++;
        return it->second;
    }
    
    // Вычисление нового значения
    cacheMisses++;
    unsigned long long result = calculateFactorial(n);
    cache[n] = result;
    return result;
}

unsigned long long FactorialCache::calculateFactorial(int n) {
    if (n <= 1) return 1;
    return n * getFactorial(n - 1);
} 