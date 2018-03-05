/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void printaddress(){
	int variables = 5;
	printf ("Address of variables is %p\n", &variables);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *try = malloc(200);
    char *s = "Literal string";


    printf ("Address of p is %p\n", p);
    printf ("Address of try is %p\n", try);
    printf ("Address of s is %p\n", s);

    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    void *n1 = malloc(30);
    void *n2 = malloc(23);

    printf ("Address of n1 is %p\n", n1);
    printf ("Address of n2 is %p\n", n2);

    printaddress();
    return 0;
}
