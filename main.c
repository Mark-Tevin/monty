#include "monty.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char *line;
        size_t len = 0;
        unsigned int line_number = 0;
        stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	/* Open the Monty file */
	bus.file = fopen(argv[1], "r");
	if (bus.file == NULL)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, bus.file) != -1)
	{
		line_number++;
		line = clean_line(line);  /* Clean the line from leading/trailing spaces and comments */

		if (line[0] != '\0')
		{
			if (execute(line, &stack, line_number, bus.file) == EXIT_FAILURE)
			{
				fprintf(stderr, "Error on line %u\n", line_number);
				free_stack(stack);
				fclose(bus.file);
				free(line);
				return (EXIT_FAILURE);
			}
		}
	}
	 /* Clean up and close the file */
	free_stack(stack);
	fclose(bus.file);
	free(line);

	return (EXIT_SUCCESS);
}

