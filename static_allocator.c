

#include "static_allocator.h"


// Define static memory pool
static uint8_t memory_pool[POOL_SIZE];

// Define a pointer to the first block in the memory pool
static memory_block* first_block = (memory_block*)memory_pool;

void* allocate_block() {

    // Search for the first free block in the memory pool
    for (memory_block* block = first_block; block <= (memory_block*)(memory_pool + POOL_SIZE - (BLOCK_SIZE + 1)); block++) {
        if (!block->is_allocated) {
            // Mark the block as allocated and return a pointer to the block's data
            block->is_allocated = 1;
            return block->data;
        }
    }
    
    // If no free block was found, return NULL to indicate failure
    return NULL;
}

void free_block(void* ptr) {
    
    // Convert the pointer to a memory_block pointer by subtracting the offset of the data field
    memory_block* block = (memory_block*)((char*)ptr - 1);// 1 is shift to start of struct

    // Mark the block as free
    block->is_allocated = 0;
}


void free_all_blocks(){

    // set flag "is_allocated" false for all blocks
    for (memory_block* block = first_block; block < (memory_block*)(memory_pool + POOL_SIZE); block++) {
        block->is_allocated = 0;
    }

}