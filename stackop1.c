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
void push(stack_t **stack, unsigned int count)
{
	stack_t *new_node = NULL;

	if (!state->arg || !isInt(state->arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		clear_state();
		exit(EXIT_FAILURE);
	}

	if (state->mode == MOD_STK)
		new_node = add_dnodeint(stack, atoi(state->arg));
	else
		new_node = add_dnodeint_end(stack, atoi(state->arg));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	state->size++;
}
