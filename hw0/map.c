#include <stdio.h>
#include <stdlib.h>

/* A statically allocated variable */
int foo;

extern int recur(int i);


/* A statically allocated, pre-initialized variable */
volatile int stuff = 7;

int main(int argc, char *argv[]) {
    /* A stack allocated variable */
    volatile int i = 0;

    /* Dynamically allocate some stuff */
    volatile char *buf1 = malloc(100);
    /* ... and some more stuff */
    volatile char *buf2 = malloc(100);

    printf("_main @ %p\n",main);
    printf("recur @ %p\n",recur);
    printf("_main_stack: %p\n",&i);
    printf("static data %p\n",&foo);
    printf("Heap: malloc 1: %p\n",buf1);
    printf("Heap: malloc 2: %p \n",buf2);
    recur(3);
    return 0;
}
