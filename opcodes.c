#include "monty.h"

/**
 * pall - Print all values in the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	(void) line_num;
	walker = *stack;
	if (walker == NULL)
		return;
	while (walker)
	{
		printf("%d\n", walker->n);
		walker = walker->next;
	}
	
}

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
// 	if (bus.lifi == 0)
// 		add_node(head, n);
// 	else
// 		add_node_end(head, n);
}

/**
 * pop - Remove the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *kill_node, *walker;

	walker = *stack;
	if (walker == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		kill_node = walker;
		*stack = walker->next;
		if (walker != NULL)
			walker->prev = NULL;
		free(kill_node);
	}
}

/**
 * swap - Put the second element on top of the stack, put the top element
 * in the second position
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;
	int tmp;

	walker = *stack;
	if (walker == NULL || walker->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp = walker->n;
		walker->n = walker->next->n;
		walker->next->n = tmp;
	}
}

/**
 * pint - Print the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		printf("%d\n", (*stack)->n);
	}
}
