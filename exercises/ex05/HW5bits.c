
#include <stdio.h>

char upper(char s){ 
	return s ^ 32; 
}

int twelve(){
	unsigned long x = 1<<32;
	int final;
	x = x-1;
  
	final = (12^x)+1;
	printf("%d\n", final);
	return 0;
}

int main(){
  twelve();
  printf("%c\n", upper('r'));
}