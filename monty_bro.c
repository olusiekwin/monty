#include "monty.h"

/**
 * process_input - modified program input processing function
 * @input_file: input file name
 */
void process_input(char *input_file)
{
    FILE *file_descriptor;
    size_t read_buffer_size = 0;
    void (*opcode_handler)(stack_t **, unsigned int);
    int current_line = 1;
    stack_t *stack_head;

    file_descriptor = fopen(input_file, "r+");
    if (!file_descriptor)
    {
        dprintf(STDERR_FILENO, "Error: Unable to open file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    stack_head = NULL;

    while (getline(&custom_buffer, &read_buffer_size, file_descriptor) != -1)
    {
        opcode_handler = get_opcode_handler();
        if (opcode_handler == NULL)
        {
            dprintf(STDERR_FILENO, "L%i: unknown instruction %s", current_line, custom_buffer);
            exit(EXIT_FAILURE);
        }
        
        opcode_handler(&stack_head, current_line);
        current_line++;
    }

    
    free(custom_buffer);
    free_stack(stack_head);
    fclose(file_descriptor);
}
