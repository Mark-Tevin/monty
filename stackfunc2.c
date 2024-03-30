#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to the top of the stack (unused).
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * add_nodes - Adds the top two elements of the stack
 * @stack: pointer to pointer
 * @line_number: integer for linenumber
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/*swap, nop, add nodes*/
