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
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element in the stack (or queue)
 * @next: Pointer to the next element in the stack (or queue)
 *
 * Description: Node structure for a doubly linked list used in stack and queue.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Represents an opcode and its corresponding function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Structure to store an opcode and its associated function.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void add(stack_t **stack, unsigned int line_number);

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void swap(stack_t **stack, unsigned int line_number);

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void push(stack_t **stack, unsigned int line_number);

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void pop(stack_t **stack, unsigned int line_number);

/**
 * pall - Prints all the elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void pall(stack_t **stack, unsigned int line_number);

/**
 * pint - Prints the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void pint(stack_t **stack, unsigned int line_number);

/**
 * nop - Does nothing
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void nop(stack_t **stack, unsigned int line_number);

/**
 * get_op - Reads opcode from a file and executes the associated function
 * @oc: File stream of the opcode file
 */
void get_op(FILE *oc);

/**
 * execute_op - Executes the given opcode function
 * @stack: Pointer to the top of the stack
 * @line: Line containing the opcode and arguments
 */
void execute_op(stack_t **stack, unsigned int line);

/**
 * add_node_end - Adds a new node at the end of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: Integer value to be stored in the new node
 * Return: Address of the new node, or NULL on failure
 */
stack_t *add_node_end(stack_t **head, const int n);

/**
 * freeList - Frees a doubly linked list
 * @head: Pointer to the head of the list
 */
void freeList(stack_t *head);

/**
 * add_node - Adds a new node at the beginning of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: Integer value to be stored in the new node
 * Return: Address of the new node, or NULL on failure
 */
stack_t *add_node(stack_t **head, const int n);

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 */
void push(stack_t **stack, unsigned int line_number);

extern char *op[];

#endif /* MONTY_H */
