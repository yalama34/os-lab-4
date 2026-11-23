#include <stdlib.h>
#include <stdbool.h>

#include "contracts.h"

int PrimeCount(int A, int B) {
    if (A < 1 || B < A){
        return -1;
    }

    bool *is_prime = malloc((B + 1) * sizeof(bool));
    if (is_prime == NULL) {
        return -1;
    }

    for (int i = 2; i < B + 1; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i <= B / i; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < B + 1; j += i) {
                is_prime[j] = false;
            } 
        } 
    }
    
    int result = 0;

    for (size_t i = A; i < B + 1; i++){
        if (is_prime[i]) result++;
    }

    free(is_prime);
    return result;
}

float Square(float A, float B) {
    if (A < 0 || B < 0) return -1;
    return (A * B) / 2;
}