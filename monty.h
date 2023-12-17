#ifndef MONTY_H
#define MONTY_H

#define BUF_SIZE 4096
#define MOD_STK 0
#define MOD_QUE 1
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - Holds information on the current program state
 * @buffer: Input buffer
 * @opcode: Operation code
 * @arg: operation argument parameter
 * @stack: Stack of the structure
 * @file: File pointer
 * @mode: Mode (stack or queue)
 * @size: Size of the stack/queue
 * @count : Line number being processed
 *
 * Description: The structure contains info on the current state of the program.
 * It entails input_buffer, the opcode and args, the stack structure, process file,
 * the mode and the size of the stack or queue, and the line count.
 */
typedef struct bus_s
{
	char *buffer;
	char *opcode;
	char *arg;
	stack_t *stack;
	FILE *file;
	unsigned int mode;
	unsigned int size;
	unsigned int count;
} bus_t;


typedef void(*op_func)(stack_t**, unsigned int);
extern stack_t *head;

/*operation for files*/
void read_file(FILE *);
FILE *check(int argc, char *argv[])
int parse_line(char *buffer, int line_number, int format);
void len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Func prototype for the stack operation*/
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/*Utility Functions*/
void free_stack(stack_t *stack);
/*External variable*/
extern bus_t *state;
/* DLinked List Operation */
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);


/*string operation*/
int compare_strings(const char *s1, const char *s2);

/* Program Logic and Execution */
void state_init(void);
void clear_state(void);
void parse_line(char *line);
void (*get_func(char *opcode))(stack_t **stack, unsigned int count);
void execute_opcode(void);


#endif /* MONTY_H */
