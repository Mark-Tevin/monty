#include "monty.h"

/**
 * error - Displays error messages based on error codes.
 * @error_code: The error code indicates the type of error.
 *              (1): No file or more than one file used.
 *              (2): The provided file cannot be opened.
 *              (3): The file contains invalid instructions.
 *              (4): The program is unable to allocate more memory space.
 *              (5): parameter passed to the "push" instruction is not an int.
 *              (6): The stack is empty when executing the "pint" operation.
 *              (7): The stack is empty when executing the "pop" operation.
 *              (8): Stack does not contain enough elements for the operation.
 */
void error(int error_code, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty [file]\n");
			break;
		case 2:
			fprintf(stderr, "Error: Failed to open file: %s\n", va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "Line %d: Unknown instruction: %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: Memory allocation failed\n");
			break;
		case 5:
			line_num = va_arg(args, int);
			fprintf(stderr, "Line %d: Usage: push integer\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * more_error- list of the other file handling error functions.
 * @error_code: The error code indicates the type of error.
 *              (6): The stack is empty when executing the "pint" operation.
 */
void more_error(int error_code, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "Line %d: Unable to execute 'pint', stack is empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "Line %d: Unable to execute 'pop', the stack is empty\n",
				va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: Unable to execute '%s', stack is short", line_num, op);
			break;
		case 9:
			fprintf(stderr, "Line %d: Division by zero error\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
