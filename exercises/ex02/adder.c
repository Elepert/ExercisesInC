
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_input(int *storage_array) {
	int i = 0;
	int data = 1;
	while(data) {
		if (feof(stdin)){
			printf("Hit EOF on stdin; exiting\n");
			data = 0;
		} else if (i == 11){
			printf("Too many inputs\n");
			return 1;

		} else {
			char temp[10];
			fgets(temp, 11, stdin);
	
			int str_length = strlen(temp);
			if (str_length > 10){
				printf("Input length exceeds buffer length\n");
				return 1;
			}
			int conver = atoi(temp);
			if (conver == 0) {
				printf("Cannot convert string to int\n");
				return 1;
			}
			storage_array[i+1] = conver;
			
			i++;
		}
		
	}
	storage_array[0] = i;
	return 0;
}

int main() {
	int array_length = 10;
	int storage_array[array_length+1];

	int done = get_input(storage_array);
	if (done == 1) {
		return 0;
	}
	int counter = 0;

	for (int i=1; i<storage_array[0]; i++) {
		counter += storage_array[i];
        printf("%d\n", storage_array[i]);
    }

	return 0;
}