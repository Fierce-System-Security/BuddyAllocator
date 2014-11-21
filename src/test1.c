#include <stdio.h>
#include <stdlib.h>
#include "buddy.h"



int main()
{
  int i;
  mem_buddy	mb = mem_init(0, 20,2);
  
  for (i = 0; i < 10; i++) {
    int *ptr = malloc(&mb, sizeof(int));
    
    if (ptr == NULL)
    {
      printf("Memory failed to allocate!\n");
      return 1;
    }

    *ptr = 4;
    free(ptr);
  }

	printf("Success\n");	
	return 0;
}
