#ifndef _BUDDY_ALLOCATOR_H_
#define _BUDDY_ALLOCATOR_H_

#include "list.h"

typedef unsigned long ul;
typedef unsigned long long ull;

struct block {
    unsigned long long link;
    unsigned long size;
    struct list_head list;
} block_t;

typedef struct mem_buddy{
    void * addr;
    unsigned long size;  
    unsigned long min_size;
    unsigned long number_blocks; 
    unsigned long * bit_availability; 
    struct list_head avail_blocks;
} mem_buddy_t;

int nk_mem_init(unsigned long size, unsigned long min_size);
void * nk_malloc(struct mem_buddy *mb, unsigned long size);
void nk_free( struct mem_buddy *mb, void *addr, unsigned long size);

#endif
