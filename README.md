# Monty
> Custom command interpreter

Dealing with LIFO FIFO concepts and creating a very simple custom language

## Installing / Getting started

Compile code using gcc and run executable with a monty file (.m)

```shell
gcc *.c -o monty
./monty test.m
```

this will execute whatever is in the test.m file according to specific monty behaviors.

## Features

The monty language has a limited and specific amount of functions
* Monty is made up of either a stack or queue depending on the mode specified
* Adding, removing, and combining (with simple arithmetic to the first two members) are possible for specific members of the data structure
* Spaces between commands and anything after a valid command are ignored
* Lines starting with a # are also considered comments and ignored
* Any errors in commands will terminate the execution and print an error specifying what went wrong

* push some_int

adds element to data structure

* pall

prints all elements of data structure

* pint

prints the value at the top of the data structure

* pop

removes top element of the data structure

* swap

swaps the top two elements of the data structure

* nop

does nothing

* sub, div, mod, add, mul

does arithmetic on the values of the top two element and combines into
 one element

* pchar, pstr

print either the char of the top element value or the string of the whole data structure values

* rotl, rotr

rotl rotates the top of the structure to the bottom. rotr rotates the last to the front

* stack, queue

changes the behavior of the data structure to stack or queue

## Author

Christopher Choe
