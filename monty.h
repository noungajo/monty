#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct op_ret_queue_s - Return value of opcodes and if list is stack/queue
 * @opcode_return: Return value of the void opcode functions
 * @queue_val: 1 if list is a queue, 0 if it's a stack
 **/
typedef struct op_ret_queue_s
{
	int opcode_return;
	int queue_val;
} opret_q;

extern opret_q ret_and_q;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**void push(stack_t **stack, unsigned int line_num);**/
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);

void add_node(stack_t **stack, int push_value);
void add_node_end(stack_t **stack, int push_value);

char *find_command(char *line, stack_t **stack, unsigned int line_num);
int check_codes(char *command, stack_t **stack, size_t line_num);
int int_check(char *push_arg);
void free_and_exit(char *line, FILE *file, stack_t *stack);
void free_stack(stack_t *stack);
#endif
