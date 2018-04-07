## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

They have their own stacks to prevent them from interfering with each others' function calls. They typically also don't call each others local variables.

2) What does the gcc flag `-lpthread` do?

It links to the Pthread library.

3) What does the argument of `pthread_exit` do?

The argument is given to the thread that the other thread is joining with. It's like a message one thread gives to another one.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

The thread joins the thread like the parent thread would. The parent thread waiting for its children is what normally happens.

5) What goes wrong if several threads try to increment a shared integer at the same time?

Since none of them wait for any of the other ones, they may read a value before it was incremented or increment the value one after the other several times before it's read. Basically if a thread increments the variable and then wants to print the value of it, there is no guarantee that the printed value will be the value of the variable at the time when they incremented it. 

6) What does it mean to "lock a mutex"?

A mutex ensures that only one thread can execute a block of code at a time. To lock the mutex means that if a thread runs, they block any other threads from running as well. It creates a queue of threads that only run once one thread has unlocked their mutex.

