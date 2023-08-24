#include "monty.h"

/**
* pop - frees the node head.
* @stack: the stack.
* @line: line number.
*/

void pop(stack_t **stack, unsigned int line)
{
stack_t *last;

if (!*stack)
{
fprintf(stderr, "L%u: forbiden: can't pop an empty stack\n", line);
ops[3] = "ERROR";
return;
}
last = *stack;
while (last->prev)
last = last->prev;
if (last->next)
last->next->prev = NULL;
if (last == *stack)
{
if ((*stack)->next)
*stack = (*stack)->next;
else
*stack = NULL;
}
free(last);
}
