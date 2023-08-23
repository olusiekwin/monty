#ifndef MONTY_H
#define MONTY_H

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


/* GLOBAL VARS */

char *custom_buffer;

/* STRUCTURES */

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @handler: Function to handle the opcode
 *
 * Description: Opcode and its associated handler function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*handler)(stack_t **stack, unsigned int);
} instruction_t;

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;



/* PROTOTYPES */

/* Main functions */
void process_input(char *input_file);
void (*get_opcode_handler(void))(stack_t **, unsigned int);

/* Print functions */
void custom_pall(stack_t **stack, unsigned int line_number);
void custom_pint(stack_t **stack, unsigned int line_number);
void custom_nop(stack_t **stack, unsigned int line_number);


/* Handle functions */
void custom_push(stack_t **stack, unsigned int line_number);
void custom_pop(stack_t **stack, unsigned int line_number);
void custom_swap(stack_t **stack, unsigned int line_number);
void custom_add(stack_t **stack, unsigned int line_number);

/* Aux functions */
void *custom_calloc(unsigned int num_elements, unsigned int element_size);
char **custom_split(char *str, char *sep);
int custom_atoi(char *str, unsigned int line_number);
void custom_free_stack(stack_t *head);

#endif
