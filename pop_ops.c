#include "monty.h"

/**
* pop - frees the head node.
* @stack: the stack.
* @line_number: line number.
*/

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *hide;

if (!*stack)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
op[3] = "ERROR";
return;
}
hide = *stack;
while (hide->prev)
hide = hide->prev;
if (hide->next)
hide->next->prev = NULL;
if (hide == *stack)
{
if ((*stack)->next)
*stack = (*stack)->next;
else
*stack = NULL;
}
free(hide);
}
