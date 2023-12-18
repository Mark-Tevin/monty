#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Address of the stack
 * @count: Line number of the current processing input
 *
 * Description: This function prints all elements in the stack using the
 *              the display function, and does not modify the stack.
 */
void pall(stack_t **stack, unsigned int count)
{
	display_listint(*stack);
	count += 0;
}
