#include "monty.h"

bus_t my_bus = {NULL, NULL, NULL, 0};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** check_input - checks existance of file and if it can be opened.
 * argc: argument count
 * @argv: argument vector.
 * Return: file struct
 */
FILE *check(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s|n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
/**
* main - monty interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *current_line;
	FILE *montyfile;
	size_t size = 0;
	ssize_t read_status = 1;
	stack_t *customstack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s montyfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	montyfile = fopen(argv[1], "r");
	my_bus.file = montyfile;

	if (!montyfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_status > 0)
	{
		current_line = NULL;
		read_status = getline(&current_line, &size, montyfile);
		my_bus.content = current;
		count++;

		if (read_status > 0)
		{
			execute(current_line, &customstack, count, montyfile);
		}

		free(current_line);
	}
	free_stack(customstack);
	fclose(montyfile);

	return (0);
}
