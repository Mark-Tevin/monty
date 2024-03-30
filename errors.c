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
