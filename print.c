#include "monty.h"

/**
 * custom_pall - Prints all nodes in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void custom_pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    while (*stack)
    {
        printf("%i\n", (*stack)->n);
        *stack = (*stack)->next;
    }
}

/**
 * custom_pint - Prints the value of the top node in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void custom_pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !stack)
    {
        dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%i\n", (*stack)->n);
}

/**
 * custom_nop - Does nothing
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void custom_nop(stack_t **stack, unsigned int line_number)
{
    (void)*stack;
    (void)line_number;
}
