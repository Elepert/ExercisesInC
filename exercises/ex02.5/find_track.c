/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{

    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// function grabbed from the regerror() documentation 
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/regerror.html
// generates error message based on compilation result
char *get_regerror (int errcode, regex_t *compiled)
{
  size_t length = regerror(errcode, compiled, NULL, 0);
  char *buffer = malloc(length);
  (void) regerror (errcode, compiled, buffer, length);
  return buffer;
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    int rv;
	regex_t exp;

	// compile message
	rv = regcomp(&exp, pattern, REG_EXTENDED);

	// check for compilation error
	if (rv != 0){
		printf("%s\n", get_regerror(rv, &exp));
		exit(1);
	}
	regmatch_t matches[1];

	// checks against each track
	for (int i=0; i<NUM_TRACKS;i++){
		
		if (regexec(&exp, tracks[i], 1, matches, 0) == 0){
			printf("Track %i: '%s'\n", i, tracks[i]);
		}
	}
	regfree(&exp);
}



// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    find_track(search_for);
    //search_for = ;
    find_track_regex(search_for);

    return 0;
}
