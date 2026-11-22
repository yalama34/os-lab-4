#ifndef OS_API_H
#define OS_API_H

void *lib_open(const char *filename);
void *get_address(void *descriptor, const char *query);
int lib_close(void *descriptor);

#endif