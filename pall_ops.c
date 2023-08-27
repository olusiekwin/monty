#include "monty.h"

/**
* pall - performs the pall opcode
* @stack: doubly linked list containing the stack
* @line_number: line number opcode
*/

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *seek, *head;
size_t nodes;

if (!*stack)
return;
head = *stack;
while (head->prev)
head = head->prev;
seek = head;
for (nodes = 0; seek != NULL; nodes++)
{
printf("%d\n", seek->n);
seek = seek->next;
}
return;
(void)line_number;
}
