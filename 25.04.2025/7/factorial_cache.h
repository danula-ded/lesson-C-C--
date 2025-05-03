#pragma once
#include <unordered_map>
#include <stdexcept>

class FactorialCache {
public:
    FactorialCache() : cacheHits(0), cacheMisses(0) {}
    
    unsigned long long getFactorial(int n) {
        if (n < 0) {
            throw std::invalid_argument("Factorial is not defined for negative numbers");
        }
        
        // Check if result is in cache
        auto it = cache.find(n);
        if (it != cache.end()) {
            cacheHits++;
            return it->second;
        }
        
        // Calculate factorial
        cacheMisses++;
        unsigned long long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        
        // Store in cache
        cache[n] = result;
        return result;
    }
    
    size_t getCacheHits() const { return cacheHits; }
    size_t getCacheMisses() const { return cacheMisses; }
    
private:
    std::unordered_map<int, unsigned long long> cache;
    size_t cacheHits;
    size_t cacheMisses;
}; 