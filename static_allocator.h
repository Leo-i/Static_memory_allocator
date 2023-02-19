
#ifndef _STATIC_ALLOCATOR
#define _STATIC_ALLOCATOR

#include <stdint.h>

// Define the block size and pool size as constants
// BLOCK_SIZE and POOL_SIZE in bytes
#define BLOCK_SIZE  7
#define POOL_SIZE   100

// Define a struct of memory block
typedef struct  {
    uint8_t is_allocated;
    uint8_t data[BLOCK_SIZE];
} memory_block;

void* allocate_block();
void free_block(void* ptr);
void free_all_blocks();

#endif
