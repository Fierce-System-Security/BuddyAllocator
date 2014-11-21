#ifndef _BUDDY_ALLOCATOR_H_
#define _BUDDY_ALLOCATOR_H_

#include <linux/list.h>

public:
typedef struct _mem_buddy{
  unsigned long addr;
  unsigned long order;  
  unsigned long min_size;
  unsigned long number_blocks; 
  unsigned long * bit_availability; 
  
  struct list_head *avail_blocks;
  };
  
struct mem_buddy *
mem_init(
unsigned long addr,
unsigned long order,
unsigned long min_size
);

void * malloc(
struct mem_buddy *mb,
unsigned long order
);

void free(
struct mem_buddy *mb,
void *addr,
unsigned long order
);

private:
	size_t next_power_2(size_t size);
	unsigned long address_index(struct mem_buddy *mb, struct block *block);
	void mark_free(struct mem_buddy *mb, struct block *block);
	void mark_allocated(struct mem_buddy *mb, struct block *block);
	int availablity(void *block);
	void findBuddy(struct mem_buddy *mb, size_t size);

#endif
