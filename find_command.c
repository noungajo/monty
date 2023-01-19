#include "monty.h"

/**
 * find_command - Parse the line to find the given opcode
 * @line: Line grabbed from monty file
 * @stack: Double pointer pointing to top of stack/queue
 * @line_num: Line number in the file the line was on
 * Return: The name of the command found
 **/
char *find_command(char *line, stack_t **stack, unsigned int line_num)
{
	char *command, *push_arg;

	command = strtok(line, "\n\t\r ");
	if (command == NULL || command[0] == '#')
		command = "nop";
	if (strcmp(command, "push") == 0)
	{
		command = "nop";
		push_arg = strtok(NULL, "\n \t\r");
		if (int_check(push_arg) == 0)
		{
			if (ret_and_q.queue_val == 0)
				add_node(stack, atoi(push_arg));
			else
				add_node_end(stack, atoi(push_arg));
		}
		else
		{
			printf("L%u: usage: push integer\n", line_num);
			ret_and_q.opcode_return = 1;
			return (command);
		}
	}
	if (strcmp(command, "stack") == 0)
	{
		command = "nop";
		ret_and_q.queue_val = 0;
		return (command);
	}
	if (strcmp(command, "queue") == 0)
	{
		command = "nop";
		ret_and_q.queue_val = 1;
		return (command);
	}
	return (command);
}

/**
 * int_check - Check if the given argument to push is a valid integer or not
 * @push_arg: The string argument found after the push opcode
 * Return: 1 if it's not a valid integer, 0 if it is
 **/
int int_check(char *push_arg)
{
	int i;

	if (push_arg == NULL)
		return (1);
	i = 0;
	while (push_arg[i] != '\0')
	{
		if (isalpha(push_arg[i]))
			return (1);
		i++;
	}
	return (0);
}

/**
 * add_node - Add a node to the top of the list
 * @stack: Double pointer to the top of the stack
 * @push_value: The value to assign to the new node
 **/
void add_node(stack_t **stack, int push_value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		if (*stack != NULL)
			(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->n = push_value;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

/**
 * add_node_end - Add a node at the end of the list
 * @stack: Double pointer to the top of the stack
 * @push_value: The value to assign to the new node
 **/
void add_node_end(stack_t **stack, int push_value)
{
	stack_t *new_node;
	stack_t *walker;

	walker = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		while (walker != NULL && walker->next != NULL)
			walker = walker->next;
		new_node->n = push_value;
		new_node->next = NULL;
		new_node->prev = walker;
		if (walker != NULL)
			walker->next = new_node;
		else
			*stack = new_node;
	}
}
