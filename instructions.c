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

/**
 * get_func - Retrieves the operation function associated with the opcode.
 * @opcode: The opcode string.
 *
 * Return: Pointer to the corresponding function, NULL if opcode does not exist
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int count)
{
	instruction_t operation_table[] = {
		{"push", push},
		{"pint", pint},
		{"pchar", pchar},
		{"pstr", pstr},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pall", pall},
		{"stack", stack},
		{"queue", queue},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	instruction_t *instr = operation_table;

	while (instr->opcode)
	{
		if (!_strcmp(opcode, instr->opcode))
			return (instr->f);
		instr++;
	}

	return (NULL);
}

/**
 * parse_line - Parses a line of input into opcode and argument string.
 * @line: The line of input.
 *
 * Description: This function assigns the opcode and argument from the input line
 *              to the corresponding fields in the bus struct. If opcode is
 *              missing, it leaves the fields as NULL.
 */
void parse_line(char *line)
{
	state->count++;
	state->opcode = strtok(line, " \n\t");
	if (!state->opcode)
		return;
	state->arg = strtok(NULL, "\n\t");
}
