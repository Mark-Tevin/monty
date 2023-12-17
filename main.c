#include "monty.h"

bus_t *state = NULL;

/**
 * main - entry point of Monty interpreter
 * @argc: argument count
 * @argv: argument strings array
 *
 * Return: 0 on success, exit with status code on failure
 */
int main(int argc, char **argv)
{
	char buffer[BUF_SIZE];
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	state_init();
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		clear_state();
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, BUF_SIZE, file))
	{
		parse_line(buffer);

		if (state->opcode)
		{
			if (state->opcode[0] != '#')
				execute_opcode();
		}

		state->opcode = NULL;
		state->arg = NULL;
	}

	fclose(file);
	clear_state();
	return (0);
}
