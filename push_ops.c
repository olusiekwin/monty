#include "monty.h"

/**
* push - the push opcode
* @stack: the stack container as doubly linked list
* @line: line number opcode came
*/

void push(stack_t **stack, unsigned int line)
{
int g;

if (!ops[1])
{
fprintf(stderr, "L%u: usage: push integer\n", line);
ops[3] = "ERROR";
return;
}
for (g = 0; ops[1][g] != '\0'; g++)
{
if ((ops[1][g] == '-' && g == 0) || (ops[1][g] == '.'))
g++;
if (!isdigit(ops[1][g]))
{
fprintf(stderr, "L%u: usage: push integer\n", line);
ops[3] = "ERROR";
return;
}
}
g = atoi(ops[1]);
if (strcmp("queue", ops[2]) == 0)
{
if (add_node_end(stack, g) == NULL)
ops[3] = "ERROR";
return;
}
else
{
if (add_node(stack, g) == NULL)
{
ops[3] = "ERROR";
return; }
}
}

/**
* add_node - adds new node at the beginning of the linked list
* @head: double pointer to the beginning of linked list
* @g: value to add to the new node
* Return: pointer to the new node, [or NULL on failure]
*/

stack_t *add_node(stack_t **head, const int g)
{
stack_t *new;

if (head == NULL)
return (NULL);
new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);
new->g = g;
new->prev = NULL;
new->next = *head;
*head = new;
if (new->next != NULL)
(new->next)->prev = new;
return (new);
}

/**
* freeList - frees list
* @head: points the head of the linked list
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
* add_node_end - adds new node at the beginning of the linked list
* @head: double pointer to the first element of the linked list
* @g: value added to  new node
* Return: pointer to the new node, [or NULL on failure]
*/

stack_t *add_node_end(stack_t **head, const int g)
{
stack_t *new, *tmp;

if (head == NULL)
return (NULL);
new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);
new->g = g;
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
