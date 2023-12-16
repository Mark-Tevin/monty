#include "monty.h"

int malloc_error(void);
int usage_error(void);
int no_int_error(unsigned int line_number);
int unknown_op_error(char *opcode, unsigned int line_number);


/**
 * usage_error - displays usage error message.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");

	return (EXIT_FAILURE);

/**
 * malloc_error - prints out malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc file\n");

	return (EXIT_FAILURE);

/**
 * unknown_op_error - shows unknown instrauction error messages.
 * @opcode: Opcode were error occured.
 * @line_number: line number in monty file where error occured.
 *
 * Return: (EXIT_FAILURE)
 */

int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);

	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints invalid monty_push argument error message
 *@line_number: Line number is monty bytecodes file where error occured
 *
 * Return: (EXIT_FAILURE)
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: Push integer\n", line _number);

	return (EXIT_FAILURE);
}
