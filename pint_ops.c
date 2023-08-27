#include "monty.h"

/**
* pint - prints the top of stack value
* @stack: the stack
* @line_number: line number
*/

void pint(stack_t **stack, unsigned int line_number)
{
stack_t *seek;

if (!*stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
op[3] = "ERROR";
return;
}
seek = *stack;
while (seek->prev)
seek = seek->prev;
printf("%i\n", seek->n);
}
