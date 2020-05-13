/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_instruction
*/

#include "corewar.h"

static token_t **interprate_file(token_t **instruction_line, FILE *source_file, char *line)
{
    size_t array = 2;

    for (size_t i = 0; line != NULL; i++) {
        instruction_line[i] = tokeniser(line);
        rm_useless_separator(instruction_line[i]);
        if (!instruction_line[i] ||
            error_syntax_line(instruction_line[i]) ||
            !correct_line(instruction_line[i])) {
            free(line);
            free_node_array(instruction_line);
            return NULL;
        }
        array++;
        instruction_line = realloc_node_array(instruction_line, array);
        if (instruction_line == NULL)
            return NULL;
        free(line);
        line = get_line(source_file);
    }
    return instruction_line;
}

token_t **get_instruction(FILE *source_file, char *line)
{
    token_t **instruction_line = malloc(sizeof(token_t *) * 2);

    if (instruction_line == NULL)
        return NULL;
    instruction_line[0] = NULL;
    instruction_line[1] = NULL;
    instruction_line = interprate_file(instruction_line, source_file, line);
    if (instruction_line == NULL || error_label(instruction_line)) {
        free_node_array(instruction_line);
        return NULL;
    }
    return instruction_line;
}