#include "monty.h"

/**
 * get_opcode_handler - Checks for a valid opcode in the line and returns its handler
 * Return: Pointer to the handler function
 */
void (*get_opcode_handler(void))(stack_t **, unsigned int)
{
    int opcode_index = 0, char_index;
    int is_valid_opcode, opcode_length;

    instruction_t opcode_list[] = {
        {"push", custom_push},
        {"pall", custom_pall},
        {"pint", custom_pint},
        {"pop", custom_pop},
        {"swap", custom_swap},
        {"add", custom_add},
        {"nop", custom_nop},
        {NULL, NULL}
    };
    
    /* Check each opcode for validity */
    while (opcode_list[opcode_index].opcode)
    {
        char_index = 0;
        is_valid_opcode = 1;
        opcode_length = strlen(opcode_list[opcode_index].opcode);
        
        while (char_index < opcode_length)
        {
            if (opcode_list[opcode_index].opcode[char_index] != custom_buffer[char_index])
            {
                is_valid_opcode = 0;
                break;
            }
            char_index++;
        }
        
        if (is_valid_opcode == 1 && (custom_buffer[char_index] == '\n'
            || custom_buffer[char_index] == ' ' || custom_buffer[char_index] == '\0'))
            break;
        
        opcode_index++;
    }
    
    return (opcode_list[opcode_index].handler);
}
