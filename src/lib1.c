#include <stdlib.h>
#include <math.h>

#include "contracts.h"

int PrimeCount(int A, int B) {
    if (A < 1 || B < A){
        return -1;
    }

    int div_count = 0;
    int result = 0;

    for (int i = A; i <= B; i++) {
        if (i == 1) continue;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                div_count++;
            }
        }
        if (div_count == 0) result++;
        div_count = 0;
    }

    return result;
}

float Square(float A, float B) {
    return A * B;
}