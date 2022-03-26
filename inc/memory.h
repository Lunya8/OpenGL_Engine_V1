#ifndef OPENGL_ENGINE_V1_MEMORY_H
#define OPENGL_ENGINE_V1_MEMORY_H

#include <malloc.h>
#include <stdlib.h>

void* gmalloc(size_t bytes);
void* gcalloc(size_t num, size_t size);
void* grealloc(void* ptr, size_t size);
void gfree(void* ptr);

#endif //OPENGL_ENGINE_V1_MEMORY_H
