#include "monty.h"
/**
 * pall - prints the stack
 * @head: stack's head
 * @count: unused parameter
 * Return: Nothing
 */

void pall(stack_t **head, unsigned int count)
{
	stack_t *h = *head;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	(void) count;/*unused parameter*/
}
