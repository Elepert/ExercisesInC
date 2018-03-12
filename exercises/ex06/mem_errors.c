/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{   
    //we never use this variable
    //int never_allocated;
    
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int *array1 = malloc(100 * sizeof(int));
    
    int *array2 = malloc(100 * sizeof (int));

    // change the bounds of these arrays
    read_element(array1, 1);
    read_element(array1, 99);

    read_element(array2, 1);
    read_element(array2, 99);

    // do whatever to these variables before we free them
    *use_after_free = 17;
    *never_free = 17;

    // we never use never_allocated so there's no need to free it
    //free_anything(&never_allocated);


    free(use_after_free);
    free(never_free);
    free(free_twice);
    free(array1);
    free(array2);

    return 0;
}
