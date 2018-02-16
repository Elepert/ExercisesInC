## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/Elepert/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

We need 6 bits.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 characters can be represented.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

Memory is volatile so when a computer is turned off, the memory is lost. Storage is on HDDs or SSDs and are for long term usage. Storage is also bigger than memory.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB is in binary units and GB is in decimal units. A GB is .14% smaller than a GiB.

5) How does the virtual memory system help isolate processes from each other?

A virtual memory system uses virtual address spaces that is then translated into physical memory. From the perspective of the program, it has access to all of its virtual memory while in the background, another process using a different virtual address space thinks the same thing. In reality, the VAs are being translated into physical memory around each other, but the processes don't have to worry about that, they think they're isolated.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

Since the stack grows down and the heap grows up in addresses, it makes sense to keep them far away so there's no overlap.

7) What Python data structure would you use to represent a sparse array?

Probably a dictionary.

8) What is a context switch?

A context switch allows an operating system to stop a process, save its state, and start a new process.
