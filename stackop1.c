#include "monty.h"

int isInt(const char *s);
/**
 * isInt - ensures that the inserted string represents a valid integer
 * @s: The input string
 * Return: 1 if it is a valid integer, 0 otherwise
 */
int isInt(const char *s);
{
	if (*s == NULL || *s == 0)
		return (0);

	if (*s == '+' || *s == '-')
		s++;

	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		s++;
	}
	return (1);
}

/**
 * push - pushes element to the stack/queue
 * @stack: Address of the stack
 * @count: Line number of the current processing input
 *
 * Description: This function pushes an element to the stack if the argument is
 * a valid integer.
 */

