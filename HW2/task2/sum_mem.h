#pragma once

#include <stdlib.h>

typedef struct list {
    void* address;
    size_t size;
    char comment[64];
    struct list* next;
} list;