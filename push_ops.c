#include "monty.h"

/**
* push - performs the push opcode
* @stack: doubly linked list containing the stack
* @line_number: line number opcode came
*/

void push(stack_t **stack, unsigned int line_number)
{
int n;

if (!op[1])
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
op[3] = "ERROR";
return;
}
for (n = 0; op[1][n] != '\0'; n++)
{
if ((op[1][n] == '-' && n == 0) || (op[1][n] == '.'))
n++;
if (!isdigit(op[1][n]))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
op[3] = "ERROR";
return;
}
}
n = atoi(op[1]);
if (strcmp("queue", op[2]) == 0)
{
if (add_node_end(stack, n) == NULL)
op[3] = "ERROR";
return;
}
else
{
if (add_node(stack, n) == NULL)
{
op[3] = "ERROR";
return; }
}
}

/**
* add_node - add a new node at the beginning of the linked list
* @head: double pointer to the beginning of the linked list
* @n: value to add to the new node
* Return: pointer to the new node, or NULL on failure
*/

stack_t *add_node(stack_t **head, const int n)
{
stack_t *new;

if (head == NULL)
return (NULL);
new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);
new->n = n;
new->prev = NULL;
new->next = *head;
*head = new;
if (new->next != NULL)
(new->next)->prev = new;
return (new);
}

/**
* freeList - free list
* @head: pointer to the beginning of the linked list
*
* Return: void
*/

void freeList(stack_t *head)
{
stack_t *next;

while (head != NULL)
{
next = head->next;
free(head);
head = next;
}
}

/**
* add_node_end - add a new node at the beginning of the linked list
* @head: double pointer to the beginning of the linked list
* @n: value to add to the new node
* Return: pointer to the new node, or NULL on failure
*/

stack_t *add_node_end(stack_t **head, const int n)
{
stack_t *new, *tmp;

if (head == NULL)
return (NULL);
new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);
new->n = n;
new->next = NULL;
if (*head == NULL)
{
new->prev = NULL;
*head = new;
return (new);
}
tmp = *head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = new;
new->prev = tmp;

return (new);
}
