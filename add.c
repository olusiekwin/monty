#include "monty.h"

/**
* add - adds the opcode
* @stack: contains doubly linked list stack
* @line: line number the opcode was extracted
*/

void add(stack_t **stack, unsigned int line)
{
stack_t *top, *last;


if (!*stack || (((!(*stack)->prev)) && (!(*stack)->next)))
{
fprintf(stderr, "L%u: I can't add, short stack\n", line);
ops[3] = "ERROR";
return;
}

for (last = *stack; last->prev; last = last->prev)
;
top = last->next;
if (last == *stack)
*stack = top;
top->g = last->g + top->g;
top->prev = NULL;
free(last);
}
