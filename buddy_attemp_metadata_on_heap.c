
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>





/** Structure for each metadata entry. */
typedef struct _metadata_entry_t {
    void *ptr;
    size_t size;
    size_t min_size;
    struct _metadata_entry_t *next;
} metadata_entry_t;

metadata_entry_t *head = NULL;

//initialize
// maybe size_t is not big enough for the biggest buddy block?
void initialize( size_t wholesize, size_t minsize)
{
	// store all metadata on heap
	// would need to calculate how much more memory we need to store metadata
	head = sbrk(wholesize);
	
}


void *malloc(size_t size)
{
	/* See if we have free space of enough size. */
    metadata_entry_t *p = head;
    void *chosen = NULL;
    metadata_entry_t *temp = NULL;
    while(p!=NULL)
    { 
    	if(p->size>=size)
    	{//first fit
    		chosen=p->ptr;
    		if(temp==NULL)
    		{
    			head=p->next;
    		}
    		if(temp!=NULL)
    		{
    			temp->next=p->next;
    		}
    		/*if(p->size>(size+sizeof( metadata_entry_t)))
    		{//printf("should shrink\n");
    			metadata_entry_t *leftover = (metadata_entry_t *)(chosen+size);
    			//printf("leftover success\n");
    			leftover->size = p->size-size-sizeof( metadata_entry_t);
    			//printf("leftover size: %zu\n",leftover->size);
    			leftover->ptr = (void*)(chosen+size+sizeof( metadata_entry_t));
    			leftover->next=NULL;
    			free(leftover->ptr);
    			p->size = size;
    		}*/
    		
    		
    		return chosen;
    	}
    	temp=p;
    	p=p->next;
    }

    if(p==NULL)
    {
    	metadata_entry_t *here = sbrk(sizeof(metadata_entry_t));
    	here->size=size;

    	here->next=NULL;
    	chosen = sbrk(size);
    	here->ptr=chosen;
    	
    	return chosen;
    }
   
   /* if(p==NULL)
    {
    	p = sbrk(sizeof(metadata_entry_t));
    	p->size=size;
    	p->free=0;
    	p->next=NULL;
    	chosen = sbrk(size);
    	p->ptr=chosen;
    	temp->next=p;
    }*/
	return chosen;
}


void free(void *ptr)
{
	if (!ptr)
		return;

 metadata_entry_t *convert=( metadata_entry_t *) (ptr-sizeof(metadata_entry_t));

	metadata_entry_t *p = head;
   /* while (p!=NULL) {
        if (p->ptr == ptr) {
            p->free = 1;
            return;
        }
        p = p->next;
    }*///how to join this with adjacent empty memory?
    
    
    if(p==NULL)
    {
    	head=convert;
    }else
    {	
    	head=convert;
    	head->next=p;
    }
    p=head;
	metadata_entry_t *temp=p->next;
	while(p!=NULL&&temp!=NULL)
	{
		if((p->ptr+p->size==temp))
		{
		p->size+=(temp->size+sizeof(metadata_entry_t));
		p->next=temp->next;
		return;
		}
		else if(temp+temp->size==p)
		{
			temp->size+=(p->size+sizeof(metadata_entry_t));
			head = temp;
			return;
		}else return;
		return;
	}
	return;
}

