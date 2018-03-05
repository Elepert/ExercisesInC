## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/elepert/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

If we convert it to a 16-bit number with sign extension, we add 8 1s to the left of the 8 bits. We are now storing -128.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

See the "twelve" function in HW5bits.c in the ex05 folder.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

Exponents need to be signed, but using two's complement would make that difficult. By using a bias, we can take a binary number, convert it to an integer, apply the bias and get a signed integer.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

13 as an unsigned single precision floating point is 1.101 * 2^3 so -13 would be 1.0011 * 2^4. The number to the left of the period is the sign (1 for -). To the right of the period is 13 in binary, with each bit flipped and then adding 1. As an integer in base 10 we would interpret it as 16.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

See the "upper" function in HW5bits.c in the ex05 folder. I use the XOR operation on the character with 32 (6th bit).

