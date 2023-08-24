#include <stdio.h>
#include "monty.h"


/**
* main - main function for monty
* @argc: argument counter
* @argv: array argument strings
* Return: on success exit with failure
*/

int main(int argc, char **argv)
{

char *ops[] = {NULL, NULL, "stack", NULL};

FILE *opc;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

opc = fopen(argv[1], "r");

if (!opc)
{
fprintf(stderr, "Error: Can't open file\n");
exit(EXIT_FAILURE);
}

get_ops(opc);

if (fclose(opc) != 0)
exit(EXIT_FAILURE);
if (ops[3])
exit(EXIT_FAILURE);

return (EXIT_SUCCESS);
}

/**
* get_ops - checks line for opcodes
* @opc: file stream of the input file
*/

void get_ops(FILE *opc)
{
unsigned int line;
int check = 0, i = 0;
char *opcode = NULL;
size_t oplength = 0;
stack_t *stack = NULL;

for (line = 1; ; line++)
{
check = getline(&opcode, &oplength, opc);
if (check == EOF)
break;
if (check == 1)
continue;
for (i = 0; opcode[0] != '\0'; i++)
{
if (opcode[i] == '\n' || check == 1)
break;
if (opcode[i] == ' ' || opcode[i] == '\t')
check = 0;
else
check = 1;
}
if (check == 0)
continue;
ops[0] = strtok(opcode, " \n\t");
if (!ops[0])
ops[0] = strtok(NULL, " \t\n");
if (ops[0][0] == '#')
continue;
ops[1] = strtok(NULL, " \n\t");
exec_ops(&stack, line);
if (ops[3])
break;
}
if (stack)
freeList(stack);
if (opcode)
free(opcode);
}

/**
* exec_ops - checks and runs the opcode
* @line: line number the opcode was extracted
* @stack: doubly linked list of the stack
*/

void exec_ops(stack_t **stack, unsigned int line)
{
int i = 0, check = 0;

instruction_t flist[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{NULL, NULL}

};

for (i = 0; flist[i].opcode != NULL; i++)
{
if (strcmp(flist[i].opcode, ops[0]) == 0)
{
flist[i].f(stack, line);
if (ops[3])
return;
check = 1;
break;
}
}

if (check != 1)
{
fprintf(stderr, "L%u: instruction not found %s\n", line, ops[0]);
exit(EXIT_FAILURE);
ops[3] = "ERROR";
return;
}
}
