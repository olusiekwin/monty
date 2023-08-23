#include "monty.h"

/**
 * custom_push - Adds a new node at the top of the stack
 * @stack: A pointer to the stack
 * @line_number: Line number in the file
 */
void custom_push(stack_t **stack, unsigned int line_number)
{
    char **split_buffer;
    int value;
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    split_buffer = _split(custom_buffer, " ");
    value = _atoi(split_buffer[1], line_number);

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;
    
    *stack = new_node;
    
    free(split_buffer);
}

/**
 * custom_pop - Removes the top node of the stack
 * @stack: A pointer to the stack
 * @line_number: Line number in the file
 */
void custom_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *node_to_delete = *stack;

    if (!*stack || !stack)
    {
        dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->next)
    {
        *stack = node_to_delete->next;
        (*stack)->prev = NULL;
        free(node_to_delete);
    }
    else
    {
        free(*stack);
        *stack = NULL;
    }
}

/**
 * custom_swap - Swaps the top two nodes of the stack
 * @stack: A pointer to the stack
 * @line_number: Line number in the file
 */
void custom_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;
    stack_t *aux = *stack;

    if (!*stack || !stack || !head->next)
    {
        dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    head = head->next;
    head->prev = NULL;

    aux->next = head->next;
    head->next = aux;
    (head->next)->prev = head;

    *stack = head;
}

/**
 * custom_add - Adds the top two nodes of the stack
 * @stack: A pointer to the stack
 * @line_number: Line number in the file
 */
void custom_add(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;

    if (!*stack || !stack || !head->next)
    {
        dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Update the value in the second node */
    (head->next)->n += head->n;

    /* Remove the first node */
    custom_pop(&head, line_number);

    /* Update the stack */
    *stack = head;
}
