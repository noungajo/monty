#include "monty.h"

/**
 * rotl - Take the top element of the stack and put it on the bottom,
 * the second element of the stack becomes the top
 * @stack: Double pointer to the top of the stack
 * @line_num: The line that the command was found
 **/
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *walker, *first_node, *second_node;

	(void) line_num;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		walker = first_node = *stack;
		second_node = walker->next;
		while (walker->next != NULL)
		{
			walker = walker->next;
		}
		walker->next = first_node;
		first_node->prev = walker;
		first_node->next = NULL;
		second_node->prev = NULL;
		*stack = second_node;
	}
}

/**
 * rotr - The last element of the stack becomes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line that the command was found
 **/
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *last_node, *second_last_node;

	(void) line_num;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last_node = *stack;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		second_last_node = last_node->prev;
		second_last_node->next = NULL;
		last_node->next = *stack;
		last_node->prev = NULL;
		(*stack)->prev = last_node;
		*stack = last_node;
	}
}
