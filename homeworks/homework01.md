## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.
Dynamic types are common in interpreted languages, but rare in compiled ones. For example, in Python, we don't need to declare the types of variables we create, but in C we do.

2) Name two advantages of static typing over dynamic typing.
Static typing saves runtime because type errors are found at compile time rather than at runtime. It also allows for those kinds of errors to be found in code that hasn't been run before. Another advantage, is that static typing saves space because the names of variables aren't stored, rather the value of them are stored at their address. 

3) Give an example of a static semantic error.
Calling a function that requires an int argument, but passing in a string argument. 

4) What are two reasons you might want to turn off code optimization?
It makes debugging easier and lowers compilation time.

5) When you run `gcc` with `-S`, why might the results look different on different computers?
Different computers might have different architectures or assembly languages. Since -S creates a result that is in semi assembly language, it will be particular to the computer running it.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?
The checks for these errors are made at differents stages in the compilation process. Each stage has a different way of presenting errors.

7) What is a segmentation fault?
This occurs when attempting to read or write at an incorrect location in memory.
