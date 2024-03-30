#include "monty.h"

/**
* print_stack - prints out the elements of a stack data structure.
* @stack: parameter, pointer to the top of the stack
* @line_number: unused line number
*/
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* print_top - prints the top node
* @stack : pointer to pointer
* @line_number: Integer representing line number
*/
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
* pop_top - removes a node from stack
* @stack: pointer to pointer
* @line_number: line number
*/

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_error(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/*print stcak, poptop, printtop, */
