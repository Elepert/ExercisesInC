## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

A datastructure that is thread safe is one that can be accessed by multiple threads without any errors popping up or data being accessed at the wrong times.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

If we add n elements to the array then next_in and next_out will point to each other which will make the program think that it is empty. By never making them able to point to each other, we remove that problem.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

If either the push or pop threads interrupt each other in the middle of their processes, the queue will be inconsistent. For example, if the push thread adds an element, gets interrupted by the pop thread that removes that element, and the push thread then resumes, incrementing the queue, that increment is no longer accurate.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

If it didn't unlock the mutex, the condition for cond_wait could never be fulfilled. By unlocking the mutex before blocking, it allows another thread to run and fulfill the condition the first thread is waiting on. If it didn't, that condition could never be met and the thread would never unblock.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

We know the mutex is locked and that the condition is probably true. There could have been something that made the condition untrue between the condition being true being signaled and the locking of the mutex.

6) What happens if you signal a condition variable when there are no waiting threads?

The signal doesn't do anything.

7) Do you have to lock the mutex to signal a condition variable?

No. However, cond_wait will lock the mutex to check wheter the condition is true before continuing.

8) Does the condition have to be true when you signal a condition variable?

Signaling a condition variable means that it is true or that it might be.
