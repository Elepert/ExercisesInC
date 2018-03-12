## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

I'd expect "calloc" to be proportional because it needs to clear all the bytes in the allocated chunk. "malloc" takes constant time because it simply returns a pointer. "free" would also be constant because it's just moving pointers around. "realloc" is proportional because it copies data and moves it around.

2) For each of the following memory errors, give an example of something that might go wrong:

    a) Reading from unallocated memory.
    
        Instead of throwing an error, the program might just read whatever is at that location in memory. 
        This data will be gibberish for us and if the program interprets the data as the wrong type we can 
        get really wonky results.

    b) Writing to unallocated memory.
    
        Writing to unallocated memory can cause problems later on. Because the memory wasn't allocated 
        properly, you might be writing over something important and mess up data structures or data.

    c) Reading from a freed chunk.
    
        Reading from a freed chunk expecting to find the old data won't necessarily work because that space 
        might have been used for something else. There is no guarantee that the old information is still there.

    d) Writing to a freed chunk.
    
        Similarly to reading from a freed chunk, writing to it will work, however you could be overwriting 
        some other information or your new information could be overwritten later on.

    e) Failing to free a chunk that is no longer needed.
        
        For a large program this can cause problems when there is no longer any physical memory or space for 
        the system. This means that the next call to "malloc" will return NULL. 


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

Firefox, Gitkraken, and Sublime are the current processes using the most memory.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

Because of space overhead, the minimum chunk size of most systems is 16 bytes. This means that if we allocate a lot of small chunks, we're wasting a lot of space. To mitigate this, storing the data in an array and storing the array as one chunk would be more efficient space wise.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
