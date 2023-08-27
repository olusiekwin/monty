#include "monty.h"

/**
* add - performs the add opcode
* @stack: doubly linked list containing the stack
* @line_number: line number the opcode came from
*/

void add(stack_t **stack, unsigned int line_number)
{
stack_t *seek, *hide;

if (!*stack || (((!(*stack)->prev)) && (!(*stack)->next)))
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
op[3] = "ERROR";
return;
}
for (hide = *stack; hide->prev; hide = hide->prev)
;
seek = hide->next;
if (hide == *stack)
*stack = seek;
seek->n = hide->n + seek->n;
seek->prev = NULL;
free(hide);
}
