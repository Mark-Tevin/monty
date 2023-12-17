#include "monty.h"

/**
 * stack - Switch the mode to stack (LIFO)
 * @stack: Address of the stack
 * @count: Line number
 */
void stack(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;

	state->mode = MOD_STK;
}
/**
 * queue - Switch the mode to queue (FIFO)
 * @stack: Address of the stack
 * @count : Line number
 */
void queue(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;

	state->mode = MOD_QUE;
}
