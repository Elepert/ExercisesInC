/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

//global variable I use later to check global sharing
int sharingGlobal = 1;


// errno is an external global variable that contains
// error information
extern int errno;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i, int *sharingHeap, int sharingStack)
{
    sleep(i);

    /*// checks heap sharing. both children print 1 and then 2
    // rather than 1, 2, 2, 3 which shows that they don't share the heap
    printf("SharingHeap for child %d is %d\n", i, *sharingHeap);
    *sharingHeap += 1;
    printf("SharingHeap for child %d is now %d\n", i, *sharingHeap);


    // checks stack sharing. both children print 1 and then 2
    // rather than 1, 2, 2, 3 which shows that they don't share the stack
    printf("SharingStack for child %d is %d\n", i, sharingStack);
    sharingStack += 1;
    printf("SharingStack for child %d is now %d\n", i, sharingStack);


    // checks global sharing. both children print 1 and then 2
    // rather than 1, 2, 2, 3 which shows that they don't share the stack
    printf("SharingGlobal for child %d is %d\n", i, sharingGlobal);
    sharingGlobal += 1;
    printf("SharingGlobal for child %d is now %d\n", i, sharingGlobal);
    */


    printf("Hello from child %d.\n\n", i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    //this variable points to the heap
    int *sharingHeap = malloc(sizeof(int));
    //initialized to one, both children print one despite incrementing it above
    *sharingHeap = 1;

    //this variable is in the stack
    int sharingStack = 1;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i, sharingHeap, sharingStack);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}
