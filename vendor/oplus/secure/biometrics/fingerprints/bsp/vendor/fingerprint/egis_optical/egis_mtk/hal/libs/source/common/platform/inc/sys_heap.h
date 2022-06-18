#ifndef __SYS__HEAP_H__
#define __SYS__HEAP_H__
#include <stddef.h>

void* sys_alloc(size_t count, size_t size);
void* sys_realloc(void* data, size_t size);
void sys_free(void* data);
#endif
