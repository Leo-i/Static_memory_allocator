#include <stdio.h>
#include <assert.h>

#include "static_allocator.h"


void test_allocation() {
    // Allocate a block and ensure the returned pointer is not NULL
    void* ptr = allocate_block();
    assert(ptr != NULL);

    // Allocate another block and ensure it has a different address than the first block
    void* ptr2 = allocate_block();
    assert(ptr2 != NULL);
    assert(ptr != ptr2);

    // Free the second block and allocate a third block, ensuring it has the same address as the second block
    free_block(ptr2);
    void* ptr3 = allocate_block();
    assert(ptr3 != NULL);
    assert(ptr2 == ptr3);

    // Attempt to allocate more blocks than are available 
    for (int i = 0; i < (POOL_SIZE / (BLOCK_SIZE + 1)) - 2; i++) {
        void* ptr3 = allocate_block();
        assert(ptr3 != NULL);
    }
    void* ptr4 = allocate_block();
    assert(ptr4 == NULL);

    //Free all blocks and ensure that new block has first block address
    free_all_blocks();
    ptr2 = allocate_block();
    assert(ptr2 != NULL);
    assert(ptr == ptr2);

    // Free single block and ensure it can be allocated again
    free_block(ptr2);
    ptr2 = allocate_block();
    assert(ptr2 != NULL);
    assert(ptr == ptr2);

    printf("Static memmory allocator: Test successfully passed \r\n");
}


int main() {
    
    test_allocation();
    
    return 0;
}
