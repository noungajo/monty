#include "monty.h"

/**
 * pchar - Print out the element of the code as it's corresponding value
 * on the ASCII table
 * @stack: Double pointer to the top of the stack
 * @line_num: The line that the command was found in the file
 **/
void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
		{
			printf("L%u: can't pchar, value out of range\n", line_num);
			ret_and_q.opcode_return = 1;
		}
		if (ret_and_q.opcode_return == 0)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
	}
	else
	{
		printf("L%u: can't pchar, stack empty\n", line_num);
		ret_and_q.opcode_return = 1;
	}
}

/**
 * pstr - Print out every element of the stack as the corresponding character
 * on the ASCII table, stops if the value is 0, the stack is over, or the
 * value of the element is not in the ASCII table
 * @stack: Double pointer to the top of the stack
 * @line_num: The line that the command was found in the file
 **/
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *walker;

	(void) line_num;
	if (*stack != NULL)
	{
		walker = *stack;
		while (walker != NULL && walker->n > 0 && walker->n <= 127)
		{
			putchar(walker->n);
			walker = walker->next;
		}
	}
	putchar('\n');
}
