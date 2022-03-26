#include "memory.h"

void* gmalloc(size_t bytes) {
    void* buf = malloc(bytes);
    if (buf == NULL) {
        fprintf(stderr, "Failed to malloc %zu bytes!\n", bytes);
        exit(-1);
    }
    return buf;
}

void* gcalloc(size_t num, size_t size) {
    void* buf = calloc(num, size);
    if (buf == NULL) {
        fprintf(stderr, "Failed to calloc %zu regions of %zu bytes!\n", num, size);
        exit(-1);
    }
    return buf;
}

void* grealloc(void* ptr, size_t size) {
    void* buf = realloc(ptr, size);
    if (buf == NULL) {
        fprintf(stderr, "Failed to realloc %p to %zu bytes!\n", ptr, size);
        exit(-1);
    }
    return buf;
}
void gfree(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Cannot free NULL pointer!\n");
        exit(-1);
    }
    free(ptr);
}