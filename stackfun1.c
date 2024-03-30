#include "monty.h"

/**
* print_stack - prints out the elements of a stack data structure.
* @stack_head: parameter, pointer to the top of the stack
* @line_num: unused line number
*/
void print_stack(stack_t **stack_head, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack_head == NULL)
		exit(EXIT_FAILURE);
	temp = *stack_head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
* pop_top - removes a node from stack
* @stack : pointer to pointer
* @line_num: line number
*/
void pop_top(stack_t **stack_head, unsigned int line_num)
{
	stack_t *temp;

	if (stack_head == NULL || *stack_head == NULL)
		more_error(7, line_num);

	temp = *stack_head;
	*stack_head = temp->next;
	if (*stack_head != NULL)
		(*stack_head)->prev = NULL;
	free(temp);
}

/*print stcak, poptop, printtop, */
