#include <dlfcn.h>

#include "os_api.h"

void *lib_open(const char *filename) {
    return dlopen(filename, RTLD_NOW);
}

void *get_address(void *descriptor, const char *query) {
    return dlsym(descriptor, query);
}

int lib_close(void *descriptor) {
    return dlclose(descriptor);
}