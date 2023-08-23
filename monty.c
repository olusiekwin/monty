#include "monty.h"

/**
 * main - Entry point of the program
 * @argument_count: Number of command-line arguments
 * @arguments: Array of command-line arguments
 * Return: Integer representing program exit status
 */
int main(int argument_count, char **arguments)
{
    if (argument_count != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: %s file\n", arguments[0]);
        exit(EXIT_FAILURE);
    }

    process_input(arguments[1]);
    
    return (EXIT_SUCCESS);
}
