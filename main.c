#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Loop through given file and run given opcode commands
 * @argc: The number of arguments passed to program
 * @argv: The strings passed to the program
 * Return: 1 if reaches end of the file, exit with EXIT_FAILURE
 * if any opcode fails
 **/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	size_t size = 0;
	unsigned int line_num = 0;
	stack_t *stack = NULL;
	ssize_t read = 1;

	if (argc != 2)
	{
		printf("usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		line = NULL;
		read = getline(&line, &size, file);
		bus.content = line;
		line_num++;
		if (read > 0)
		{
			execute(line, &stack, line_num, file);
		}
		free(line);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

/**
 * free_and_exit - Free all necessary memory and exit with EXIT_FAILURE
 * @line: The line found using getline()
 * @file: The file opened and being read from
 * @stack: The top of the stack list
 **/
void free_and_exit(char *line, FILE *file, stack_t *stack)
{
	free_stack(stack);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Free all nodes of the stack
 * @stack: Top of the stack list
 **/
void free_stack(stack_t *stack)
{
	stack_t *kill_node;

	while (stack != NULL)
	{
		kill_node = stack;
		stack = stack->next;
		free(kill_node);
	}
}
