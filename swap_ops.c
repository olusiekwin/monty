#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *seek, *swap;
int n;

if (!*stack || (((!(*stack)->prev)) && (!(*stack)->next)))
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
op[3] = "ERROR";
return;
}
for (seek = *stack; seek->prev; seek = seek->prev);
swap = seek->next;
n = seek->n;
seek->n = swap->n;
swap->n = n;
}
