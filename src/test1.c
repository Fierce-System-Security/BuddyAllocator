#include <stdio.h>
#include <stdlib.h>
#include "buddy_allocator.h"



int main()
{
    int i;
    /* init the buddy allocator using 2^20 size and smallest of 2 */
    int x = nk_mem_init(20,2);

    int *iptr = nk_malloc(sizeof(int));

    if(iptr == NULL)
    {
        printf("Failed to malloc");
        exit(-1);
    }

#if 0
    for (i = 0; i < 10; i++) {
        int *ptr = nk_malloc(sizeof(int));

        if (ptr == NULL)
        {
            printf("Memory failed to allocate!\n");
            return 1;
        }

        *ptr = 4;
        //nk_free(ptr);
    }
#endif

    printf("Success: Malloc Base: %p, int: %d\n", iptr, *iptr);	
    return 0;
}
