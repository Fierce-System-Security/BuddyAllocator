#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* struct ?? 2 linked lists? binary tree?
 * Possible implementations: 2 linked lists - one to manage free page blocks 
 * and one to manage the pairs of buddies 
 */

typedef struct _metadata {
    void *ptr;
    size_t size;
   // int free;
    struct _metadata *next;
    //struct _metadata_entry_t *prev;
} metadata;


metadata * freelist_head = NULL;

//where do we store the metadata?  sbrk some memory for it?

/**
 * Allocate memory block
 *
 * Allocates a block of size bytes of memory, returning a pointer to the
 * beginning of the block. The content of the newly allocated block of
 * memory is not initialized, giving it indeterminate values.
 *
 * @param size
 *    Size of the memory block, in bytes.
 *
 * @return
 *    On success, a pointer to the memory block allocated by the function.
 *
 *    The type of this pointer is always void*, which can be cast to the
 *    desired type of data pointer in order to be dereferenceable.
 *
 *    If the function failed to allocate the requested block of memory,
 *    a null pointer is returned.
 *
 * @see http://www.cplusplus.com/reference/clibrary/cstdlib/malloc/
 */
 
void * alloc(size_t size)
{
	//get the actual size that we are going to alloc
	size_t realsize = next_power_2(size);

	//search through the list of free blocks
	metadata * p = freelist_head;
	metadata * temp = NULL;
	void *chosen = NULL;
	
	while(p!=NULL)
	{
		if(p->size==realsize)
		{
			//find 
			chosen = p->ptr;
			if(temp==NULL)
			{
				//the first item on the free list fullfills required size
				freelist_head = p->next;
			}
			else
			{
				//delete current block from the free list
				temp->next=p->next
			}
			return chosen;
		}
		temp=p;
		p=p->next;
	}
	
//	nothing in the freelist, or no required size is find
    if(p==NULL)
    {
    	//if it's nothing in the freelist
    	//should alloc a new big block for buddy ==> double the size of current buddy
    	
    	//otherwise should look for bigger free block and split them until required size
    	
    	//how to track the parent block?
    	
    	//use bst? or several linked lists with different size?
    }
} 
 
/*
	helper: next power of 2
	given the request size, return the power of 2 that is immediately bigger than size
	
	@param size
		given size of the memory block
		
	@return 
		the power of 2 that is immediately bigger than size
*/ 

size_t next_power_2(size_t size)
{
	int cursize =1;
	while(cursize<size)
		cursize*=2;
		
	return cursize;
	
	
	//should we use bitwise operation?
}
 
 
/*
	helper: split
	split the larger memory block into 2 buddy blocks
*/


/* 
 * helper: checks availability of block
 * 
 * Specifically looks at a block to see if it is free or has been
 * allocated
 *
 * @param mem_buddy *mb
 *  Pointer passing reference to specific memory block. The block will 
 *  be merged or allocated based on its availability
 * 
 * @return
 *  If the memory block is free, then true is returned. If the block has
 *  been allocated, then false. 
 */
 
 boolean availablity(void *block)
 {
 
 }
 
 /**
  *helper: finds buddy block 
  * 
  *@param mem_buddy *mb
  * Pointer passing reference to specific memory block.
  *@param size
  * Size of the memory block, in bytes
  *
  *@return
  * Return address of the buddy of the memory block
  */
  
  
/**
 * Free a block of memory
 * 
 * A block of memory previously allocated using a call to alloc(),
 * is deallocated, making it available again for
 * further allocations.
 *
 *
 * @param ptr
 *    Pointer to a memory block previously allocated with alloc(),
 *   to be deallocated.  If a null pointer is
 *    passed as argument, no action occurs.
 */ 
 
void free(void *ptr)
{
	if (!ptr)
		return;
}


/*
	helper: merge
	merge 2 free blocks together to make a bigger block
*/


/**
 * Initializes a buddy allocator object
 *
 * Required: addr (address of the base memory block), order (size of 
 * memory block), min_size (minimum size of block)
 *
 *@return
 * Pointer to initialized memory allocator
 * If this did not work, a null pointer is returned
 */
 
struct mem_buddy *mb
mem_init(unsigned long addr, unsigned long order, unsigned long min_size){
 
    struct mem_buddy *mb
    int i = 0;
    
    //Check that the minimum size of block is smaller than the order
    if(min_size > order){
    	return NULL;
    }
    
    mb = alloc(size_t(struct mem_buddy));    //allocates for the buddy allocator
    mb->addr = addr;
    mb->order = order;
    mb->min_size = min_size;
    
    //Allocate linkedlist for every order
    mp->avail_blocks = alloc(size_t(struct list_head));
   
    //Linked list for pairs of buddies
    
    //List should be empty in the beginning
    for(i=0; i <=order;i++){
    	INIT_LIST_HEAD(&mb->avail_blocks[i]); //Gets and initializes list head * of linkedlist
    }

	return mb;
}
    
