## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

The kernel's most basic task is to deal with interrupts which are events that stop the instruction cycle and makes the flow of execution enter a section of code called an "interrupt handler."

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The hardware saves the program counter so the kernel knows where to start again.

3) What is the difference between an interrupt and a context switch?

Interrupts interrupt a process and cause some action to occur. After the interrupt, the kernel can either resume that process or switch to another process which is called a context switch.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

If a process needs to read from the cache but the data isn't there the data may have to move from memory to cache. The process could be placed into block mode until the data is successfully transferred to the cache and switched to ready once the cache is updated.

5) Why might a scheduler want to give higher priority to an I/O bound process?

An I/O process is probably necessary for another process to run, that is, other processes are probably blocked waiting for the I/O process to complete. It also doesn't need much CPU time so it can probably run fast.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

Cook 8 slices on each side for 5 minutes. Then place the remaining 4 slices on the gridle and cook those for 5 minutes each side. The entire process takes 20 minutes.



