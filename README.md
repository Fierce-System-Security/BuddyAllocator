BuddyAllocator
==============

This project is focused on developing a simple memory allocator using the buddy allocator algorithm.

Basic description of the buddy allocator: 
  The buddy allocator works by dividing memory into partitions based on given memory requests. Each block of memory has a specific order, ranging from 0 to an upper limit. When a larger block of memory is split, it becomes two smaller equally-divided blocks, which are considered to be "buddies" of each other. 
  
Efficiency:
Positive aspects of this are the compaction of memory and the fact that freeing memory is a quick process. A negative aspect is that memory is wasted when the memory requested is larger than a small block but smaller in size than a larger block 
  
Process: 
To allocate, search for memory block of sufficient size. If found, then memory is allocated (DONE). If not, make sufficient memory block size by split larger memory block into a smaller block.
 If the limit is reached, then allocate (DONE). Otherwise, go back and repeat process until sufficient block size is found. 
To free, free block of memory. If the block next to it free as well, then the two should be merged. Go back and repeat this process until upper limit is reached or until a used neighboring block is found

Possible Implementations:
  Sometimes used with binary tree to represent used/unused split memory blocks;
  Linked list - free page blocks;
  Map - represents pair of buddies 
    (0 if pair of buddies is both empty or full, 1 if only one buddy is being used).
