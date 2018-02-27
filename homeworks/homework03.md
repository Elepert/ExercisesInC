## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.


### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

From the programmer's point of view, files are byte based while they are actually block based. When we complete operations on files and read/write from them, we get bytes in response. The OS actually has to access the memory block by block.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

The file position, location in memory, time it was last opened, and the size of the file are all things I think the OpenFileTableEntry stores.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Instead of accessing one byte at a time, the system will read an entire block at once, reducing the amounts of time the system needs to go back to read information. It will add a buffer between the system writing to a block. This buffer stores the data that will be written, so if the system edits that information many times in a short amount of time, there is only one write to the drive rather than multiple ones. Prefetching is when the system predicts which blocks the system will read next and loads them before the system explicitly requests them. Caching is when the system keeps a copy of a recently used block in memory which allows quick access to a block without actually having to load it.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

Buffering or caching can result in lost information if the data stored in either of these processes isn't processed and actually stored in memory before a crash happens. In this case, the information was probably in a buffer and hadn't yet been written to a file before the computer crashed.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

An inode allows us to jump to whichever block is of interest while the FAT forces us to go through the list of blocks until we get to the one we want. On the other hand, the FAT allows us to string as many blocks as we want (although because inodes point to so many blocks this doesn't necessarily ever really come into play).

6) What is overhead?  What is fragmentation?

Fragmentation refers to any unused blocks. Overhead refers to the fact that the allocators' data structures are small, leaving a lot of space for data.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It makes it easier for programming and allows it to be versatile because one program can be used for a variety of different cases as long as everything is seen as a file. It might be a bad idea because it could cause confusion or limit the ways data can be stored.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



