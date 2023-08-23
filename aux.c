#include "monty.h"


/**
 * custom_split - Splits a string into an array of substrings
 * @str: The string to split
 * @sep: The separator
 * Return: An array of substrings
 */
char **custom_split(char *str, char *sep)
{
    char *token, **split_str;
    int i = 0;

    token = strtok(str, sep);
    split_str = (char **)custom_calloc(100, sizeof(char *));

    if (!split_str)
    {
        free(split_str);
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while (token)
    {
        split_str[i] = token;
        token = strtok(NULL, sep);
        i++;
    }
    
    return split_str;
}

/**
 * custom_calloc - Allocates memory for an array and initializes it to zero
 * @num_elements: Number of elements
 * @element_size: Size of each element
 * Return: Pointer to the allocated memory or NULL on failure
 */
void *custom_calloc(unsigned int num_elements, unsigned int element_size)
{
    unsigned int index = 0;
    char *ptr = NULL;

    if (num_elements == 0 || element_size == 0)
        return NULL;

    ptr = malloc(num_elements * element_size);
    if (!ptr)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    for (; index < (num_elements * element_size); index++)
        ptr[index] = 0;

    return ptr;
}

/**
 * custom_atoi - Converts a string to an integer
 * @str: The string to convert
 * @line_number: Line number in the file
 * Return: The converted integer
 */
int custom_atoi(char *str, unsigned int line_number)
{
    int num = 0, i = 0;
    unsigned int valid_nums = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        valid_nums++;
        i++;
    }

    if (valid_nums != strlen(str) - 1)
    {
        dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    return num;
}


/**
 * custom_free_stack - Frees a linked list
 * @head: Pointer to the head of the list
 */
void custom_free_stack(stack_t *head)
{
    stack_t *current;

    while (head)
    {
        current = head->next;
        free(head);
        head = current;
    }
}
