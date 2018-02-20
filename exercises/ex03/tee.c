/* Implementation of Tee for HW 3

Reflect: what worked, what slowed you down? What would you do differently next time?
Using the HFC book as a baseline worked really well. It helped me
get started. Figuring out how to write to a file in C took a bit.
Refreshing myself on input handling also took a bit. Next time I
would write out pseudocode and map out more what my plan is ahead of time.
I think I jumped from section to section a lot because I hadn't created a 
clear map of what I was going to do.

Compare your solution to this professional implementation or this one. What do you 
see in professional code that is not in your solution?
The professional solutions have a lot more erorr handling and checks in place.
They also implement more options.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char in;
	int add;
	char input[256];

	FILE *output;

	while ((in = getopt(argc, argv, "ai")) != EOF){
		switch(in){
			case 'a':
				add = 1;
				break;
			default:
				fprintf(stderr, "Unknown option: '%s'\n", optarg);
				exit(1);
		}
	}
	argc -= optind;
	argv += optind;
	if (argc < 2) {
		fprintf(stderr, "Specify an output file\n");
		return 1;
		exit(1);
	}
	while(fgets(input, 256, stdin)){
		
		for (int i = 0; i<argc; i++){

			if(!add){
				output = fopen(argv[i], "w");


			} else {
				output = fopen(argv[i], "a");
				
			}
			
			fputs(input, output);

			fclose(output);
		}
		fprintf(stdout, "%s", input);
	}

	return 0;
}