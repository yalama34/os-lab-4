#include <stddef.h>

#include "lib_manager.h"
#include "os_api.h"

static void *descriptor = NULL;
static int current_lib = 0;

static int (*prime_count)(int, int) = NULL;
static float (*square)(float, float) = NULL;

#ifdef _WIN32
static const char *paths[] = {
    "./lib1.dll",
    "./lib2.dll"
};
#else
static const char *paths[] = {
    "./lib1.so",
    "./lib2.so"
};
#endif

int init_library() {
    descriptor = lib_open(paths[current_lib]);
    if (descriptor == NULL) {
        return -1;
    } 

    prime_count = (int(*)(int, int))get_address(descriptor, "PrimeCount");
    square = (float(*)(float, float))get_address(descriptor, "Square");

    if (prime_count == NULL || square == NULL) {
        lib_close(descriptor);
        descriptor = NULL;
        prime_count = NULL;
        square = NULL;
        return -1;
    } 

    return 0;
}

int switch_library(void){
    if (close_library() != 0){
        return -1;
    }

    current_lib = 1 - current_lib;
    return init_library();
}

int close_library() {
    if (descriptor == NULL){
        return 0;
    }

    if (lib_close(descriptor) != 0) {
        return -1;
    }

    descriptor = NULL;
    prime_count = NULL;
    square = NULL;

    return 0;
}

int call_prime_count(int A, int B) {
    return prime_count(A, B);
}

float call_square(float A, float B) {
    return square(A, B);
}