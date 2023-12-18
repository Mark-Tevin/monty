#include "monty.h"

/**
 * delet_dnode_idx - Delete a node at specified index in a linked list
 * @head: Address of the head pointer.
 * @idx: Index of the node to be deleted.
 *
 * Return: 1 on success, -1 on failure.
 */
int delet_dnode_idx(stack_t **head, unsigned int idx)
{
	stack_t *ptr = NULL;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	for (i = 0, ptr = *head; i < index && ptr; i++, ptr = ptr->next)
		;

	if (!ptr)
		return (-1);

	if (ptr == *head)
		*head = ptr->next;
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	/* Free the memory allocated for the node */
	free(ptr);

	return (1);
}

