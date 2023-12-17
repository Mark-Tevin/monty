#monty bytecode interpreter
working on implementation of Stacks, Queues - LIFO, FIFO to manipulate data.
This program is intended to read and execute bytecode instructions from various files.
#The following files are included in the folowing project
* switchmode.c file - this file has a func that implements the mode switching functionality to toggle btwn stack and queue modes
* main.c file - main function and file processing logic of the interpreter
* monty.h: Header file with function prototypes and definitions.
* linkedlist2.c: Implements linked list functions
* util_char.c: Contains utility functions for handling character strings.
* stackop1.c: Implements stack functions i.e push, pop, and swap.
* strcmp.c: Implements a custom string comparison function.
*
* math.c - arithmetic operations 
* monty: The compiled executable file.
* stackop2.c: Implements stack functions.
*
**linkedlist.c: Implements generic doubly linked list functions.
* instruction.c: implementations of specific bytecode instructions.

/*HOW TO USE THE INTERPRETER*/
1. compile source files using the c compiler
2. create bytecode file with instructionsi.c bytecodes/06.m .
3. Run the interpreter, passing the bytecode file as a command-line arg.


check the instruction.c file for more details 
