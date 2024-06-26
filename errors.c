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
	char *opcode;
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
			opcode = va_arg(args, char *);
			fprintf(stderr, "Line %d: Unknown instruction: %s\n", line_num, opcode);
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
	char *opcode;
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
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: Unable to execute '%s', short stack", line_num, opcode);
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

/**
* str_error - sorts out string related errors
* @error_code: The error codes are as follows:
* (10) - The number inside a node is outside the valid ASCII bounds.
* (11) - The stack is empty.
*/
void str_error(int error_code, ...)
{
	va_list args;
	int line_num;

	va_start(args, error_code);
	line_num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "Error: Can't print char, out of range%d\n", line_num);
			break;
		case 11:
			fprintf(stderr, "Error: Can't print char, stack is empty%d\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
