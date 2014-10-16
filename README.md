BuddyAllocator
==============

This project is focused on developing a simple memory allocator using the buddy allocator algorithm.

Basic description of the buddy allocator: 
  The buddy allocator works by dividing memory into partitions based on given memory requests. Each block of memory has a specific order, ranging from 0 to an upper limit. When a larger block of memory is split, it becomes two smaller equally-divided blocks, which are considered to be "buddies" of each other. 
  
Efficiency:
  Positive: Compaction of memory, freeing memory is a quick process
  Negative aspect: memory is wasted when the memory requested is larger than a small block but smaller in size than a larger block 
  
Process: 
To allocate -   
  Search for memory block of sufficient size
    If found, then allocated. DONE. 
    If not, make sufficient memory block size:
      Split larger memory block into a smaller block
      If limit is reached, then allocate. DONE.
      Go back and repeat process until sufficient block size is found. 
To free - 
  Free block of memory
  Is block next to it free as well? If so, merge the two
  Go back and repeat process until upper limit is reached or until a used neighboring block is found

Possible Implementations:
  Sometimes used with binary tree to represent used/unused split memory blocks
  Linked list - free page blocks
  Map - represents pair of buddies
    0 if pair of buddies is both empty or full, 1 if only one buddy is being used
