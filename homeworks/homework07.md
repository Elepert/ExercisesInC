## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

When the program writes a new value into the program counter, the flow of execution goes to another section in the program. There is a new address so it points to new instructions for the program.

2) What is the fundamental problem caches are meant to solve?

For most programs, transfer of data in memory is what slows down a program, not executing instructions. Caching is meant to reduce the time it takes for the program to access the memory it needs.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average access time of a program with hit rate 50%?  How about 90%?

hit rate 50% => 0.5 * 1ns + 0.5 * 10ns = 5.5ns

hit rate 90% => 0.9 * 1ns + 0.1 * 10ns = 1.9ns

4) The book gives several examples of programming language features, like loops, that tend to improve locality in the access pattern of instructions and/or data.  Can you think of other examples? Or counter-examples that might decrease locality?

If you create a program that has many variables that are not reused often, then this creates poor locality. On the other hand a function that reuses a lot of the same variables or functions would have better locality.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

Saying that a program is "cache aware" implies that the algorithms were designed with the size of the cache, the block size, and other hardware characterstics in mind. Simply improving locality isn't enough because it doesn't necessarily take all of those factors into account.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

I found two CPUs with $21/MB (for 8MB) or $22,500/GiB and $18/MB (for 6MB) or $19,300/GiB. That's a difference of $3/MB or about $3200/GiB.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?



8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?



