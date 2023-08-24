#include "monty.h"

/**
* swap - Swaps the top two elements of the stack
* @stack: Pointer to the top of the stack
* @line_number: Line number in the Monty bytecode file
*/
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *top, *swap;
int g;

if (!*stack || (((!(*stack)->prev)) && (!(*stack)->next)))
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
ops[3] = "ERROR";
return;
}
for (top = *stack; top->prev; top = top->prev);
swap = top->next;
g = top->g;
top->g = swap->g;
swap->g = g;
}
