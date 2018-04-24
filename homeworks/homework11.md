## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

`sem_t` behaves like a structure meaning that passing it as a parameter makes a copy for which the behavior can be unknown.

2) When you use a Semaphore as a mutex, what should its initial value be?

The initial value should be 1 to indicate that it is unlocked.

3) Can you think of another use for a Semaphore where you might use a different initial value?

An initial value of 0 could be useful because if you want a thread to wait for some other action to happen before that thread runs, an initially locked Semaphore would do that.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

It means that there are 3 open spots left in the queue which means that three producer threads can execute queue_push without blocking. 

5) What does it mean if `queue->space` is `-3`?

It means that three threads need to finish for any new producer threads to run queue_push.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

The semaphore keeps track of how many items are in the queue and will block consumers if the queue is empty.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

You can show this is true by implementing a Semaphore with condition variables and mutexes.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

If threads are waiting on a semaphore when a thread executes `signal` then one of those threads must be woken up.
