#include "monty.h"
#include <string.h>

/**
 * state_init - Initializes the bus structure.
 */
void state_init(void)
{
	state = malloc(sizeof(bus_t)); /*Allocate memory for the bus_t structure*/

	if (!state)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);

		state->opcode = NULL;
		state->arg = NULL;
		state->stack = NULL;
		state->file = NULL;
		state->mode = MOD_STK;
		state->size = 0;
		state->count = 0;
/* Allocate memory for the buffer in the bus_t structure*/
		state->buffer = malloc(BUF_SIZE);
		if (!state->buffer)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(state);
			exit(EXIT_FAILURE);
		}
	}
}

/*
 * clear_state - frees allocated memory
 *
 */
void clear_state(void)
{
	free(state->buffer);
	free_dlistint(state->stack);
	if (state->file)
		fclose(state->file);
	free(state);
}



