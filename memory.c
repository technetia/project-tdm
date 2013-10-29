#include "memory.h"

#define MEMORY_SIZE 65536

char MEMORY_BLOCK[MEMORY_SIZE];

void init_memory(void) {
    int i;
    for (i = 0; i < MEMORY_SIZE; i++) {
        MEMORY_BLOCK[i] = '\0';
    }
}

