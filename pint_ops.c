#include "monty.h"

/**
* pint - prints top moststack value
* @stack: the stack
* @line: line number
*/

void pint(stack_t **stack, unsigned int line)
{
stack_t *top;

if (!*stack)
{
fprintf(stderr, "L%u: can't pint, empty stack\n", line);
ops[3] = "ERROR";
return;
}
top = *stack;
while (top->prev)
top = top->prev;
printf("%i\n", top->g);
}
