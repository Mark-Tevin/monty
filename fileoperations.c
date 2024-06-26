#include "monty.h"

/**
 * open_file - Opens a specified file.
 * @file_path: The path to the file to be opened.
 * Return: void
 */
void open_file(char *file_path)
{
	FILE *fd = fopen(file_path, "r");

	if (file_path == NULL || fd == NULL)
		fprintf(stderr, "Error: Unable to open file %s\n", file_path);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads the file
 * @fd: file descriptor
 * Return: void
 */
void read_file(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
	{
		format = process_input(buffer, line_num, format);
	}
	free(buffer);
}

/**
* process_input - determines the correct function to call
* @line_number: line number
* @buffer: line in the file
* @format: storing format, if node is 0 enter as stack else queue
* Return: 0 if opcode is a stack while 1 if queue
*/

int process_input(char *buffer, int line_number, int format)
{
	char *instruction, *value;
	const char *delim = "\n";

	if (buffer == NULL)
		error(4);

	instruction = strtok(buffer, delim);
	if (instruction == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(instruction, "stack") == 0)
		return (0);
	if (strcmp(instruction, "queue") == 0)
		return (1);

	execute_instruct(instruction, value, line_number, format);
	return (format);
}

/**
 * execute_instruct - finds the appropriate function for opcodes
 * @value : opcode argument
 * @format:format
 * @line_number: line number
 * @opcode: poiner
 * Return: void
 */
void execute_instruct(char *opcode, char *value, int line_number, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			execute_func(func_list[i].f, opcode, value, line_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, line_number, opcode);
}

/**
 * execute_func - calls required function
 * @func: pointer to called func
 * @val: string rep of a numerical value
 * @line_num: instruction line number
 * @opcode: poiner
 * @format: Format specifier
 */
void execute_func(op_func func, char *opcode, char *val, int line_num, int format)
{
	stack_t *node;

	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, line_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			error(5, line_num);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, line_num);
		if (format == 1)
			add_to_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
