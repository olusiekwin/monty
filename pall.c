#include "monty.h"

/**
* pall - Does the pall opcode
* @stack: stack containing the doubly linked list
* @line: line number opcode
*/

void pall(stack_t **stack, unsigned int line)
{
stack_t *top, *last;
size_t nodes;

if (!*stack)
return;
last = *stack;
while (last->prev)
last = last->prev;
top = last;
for (nodes = 0; top != NULL; nodes++)
{
printf("%d\n", top->g);
top = top->next;
}
return;
(void)line;
}
