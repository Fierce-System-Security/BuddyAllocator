EXE = test1
OBJS = functions1.o functions2.o

COMPILER = gcc
COMPILER_OPTS = -c -g -O0 -Wall -Werror -std=c99
LINKER = gcc


all: $(EXE) 

test1: test1.c buddy.o
	$(LINKER) test1.c buddy.o -o T1



buddy.o: buddy_allocator.c buddy_allocator.h
	$(COMPILER) $(COMPILER_OPTS) buddy_allocator.c -o buddy.o


clean:
	rm -f T1 *.o
