#include <windows.h>

#include "os_api.h"

void *lib_open(const char *filename){
    return (void *)LoadLibraryA(filename);
}

void *get_address(void *descriptor, const char *query){
    return (void *)GetProcAddress((HMODULE)descriptor, query);
}

int lib_close(void *descriptor){
    return FreeLibrary((HMODULE)descriptor) ? 0 : -1;
}