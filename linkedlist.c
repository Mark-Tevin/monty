#include "monty.h"
/**
 * display_listint - Prints all elements of a doubly linked list.
 * @head: Head of the doubly linked list.
 *
 * Return: Number of nodes in the list.
 */
size_t display_listint(const stack_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		printf("Node Value: %d\n", head->n);
		head = head->next;
	}

	return (count);
}

/**
 * insert_at_start - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to the pointer to the head node of the list.
 * @n: The data in  new node.
 *
 * Return: Address of the new node, or NULL on failure.
 */
stack_t *insert_at_start(stack_t **head, const int n)
{
	stack_t *newnode = NULL;

	if (head)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode)
		{
			newnode->n = n;
			newnode->prev = NULL;
			newnode->next = *head;
			if (*head)
				(*head)->prev = newnode;
			*head = newnode;
		}
	}

	return (newnode);
}

/**
 * addnode_end - Adds a new node at the end of a doubly linked list.
 * @head: Pointer to the head pointer of the list.
 * @n: Data for the new node.
 *
 * Return: Address of the new node, NULL on failure.
 */
stack_t *addnode_end(stack_t **head, const int n)
{
	stack_t *newnode = NULL;

	if (head)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode)
		{
			newnode->n = n;
			newnode->next = NULL;
			newnode->prev = *head;

			if (!*head)
			{
				*head = newnode;
				return (newnode);
			}
			while (newnode->prev->next)
				newnode->prev = newNode->prev->next;

			newnode->prev->next = newnode;
		}
	}

	return (newnode);
}

/**
 * fetch_at_index - Retrieves the node at a specified index.
 * @head: Pointer to head node of the doubly linked list.
 * @index: Index of the node to retrieve.
 * Return: Pointer to the node at the given index, else NULL 
 */
stack_t *fetch_at_index(stack_t *head, unsigned int index)
{
	unsigned int counter;

	for (counter = 0; counter < index && head; counter++)
	{
		head = head->next;
	}

	return (head);
}

/**
 *
 * deallocate_list - Frees a doubly linked list.
 * @head: Pointer to the head node of the list.
 */
void deallocate_list(stack_t *head)
{
	stack_t *h = head;
	stack_t *next;

	while (h)
	{
		next = h->next;
		free(h);
		h = next;
	}
}
