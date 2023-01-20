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
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"sub", sub},
				{"div", _div},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", pstr},
				{"rotl", rotl},
				{"rotr", rotr},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

