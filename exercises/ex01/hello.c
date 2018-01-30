#include <stdio.h>

int main() {
	// in un-optimized version
	// adding this line adds a "movl $5, %esi" line to the .s file
	int x = 5;
	// in un-optimized version
	// adding this line adds a "movl $4, %esi" line to the .s file
	int y = 4;
	// this creates a "hello world" flag under "L_.str"
    printf("Hello World");
    // in optimized version, this tells the program to forget
    // about the x variable so it will only save the y one
    printf("%d",y);
    return 0;
}