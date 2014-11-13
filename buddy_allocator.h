#include <linux/list.h>

struct mem_buddy{
  unsigned long addr;
  unsigned long order;  
  unsigned long min_size;
  unsigned long number_blocks; 
  unsigned long bit_availability; 
  
  struct list_head *avail_blocks;
  };
  
struct mem_buddy *
mem_init(
unsigned long addr,
unsigned long order,
unsigned long min_size
);

malloc(
struct mem_buddy *mb,
unsigned long order
);

free(
struct mem_buddy *mb,
void *addr,
unsigned long order
);
