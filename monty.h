#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @g: integer
 * @prev: points previous element of the stack (or queue)
 * @next: points the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int g;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and function
 * @opcode: opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and functions
 * for: stack, queues, [LIFO, FIFO]
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void add(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void push(stack_t **stack, unsigned int line);


void pop(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);


void nop(stack_t **stack, unsigned int line);
void get_ops(FILE *oc);
void exec_ops(stack_t **stack, unsigned int line);
stack_t *add_node_end(stack_t **head, const int g);
void freeList(stack_t *head);


stack_t *add_node(stack_t **head, const int g);
void push(stack_t **stack, unsigned int line);


extern char *ops[];


#endif /* MONTY_H */
