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
	while (walker != NULL)
	{
		printf("%d\n", walker->n);
		walker = walker->next;
	}
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

