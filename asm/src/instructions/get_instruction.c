/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_instruction
*/

#include "corewar.h"

static token_t **interprate_file(token_t **instruction_line, char **file)
{
    size_t array = 2;
    size_t index = 0;

    for (size_t i = 0; file[i] != NULL; i++) {
        file[i] = clean_line(file[i]);
        if (!my_strlen(file[i]))
             continue;
        instruction_line[index] = tokeniser(file[i]);
        rm_useless_separator(instruction_line[index]);
        if (!instruction_line[index] ||
            error_syntax_line(instruction_line[index]) ||
            !correct_line(instruction_line[index]))
            return NULL;
        array++;
        instruction_line = realloc_node_array(instruction_line, array);
        if (instruction_line == NULL)
            return NULL;
        index++;
    }
    return instruction_line;
}

token_t **get_instruction(FILE *source_file)
{
    token_t **instruction_line = NULL;
    char **file = read_file(source_file);

    if (file == NULL)
        return NULL;
    instruction_line = malloc(sizeof(token_t *) * 2);
    if (instruction_line == NULL) {
        free_word_array(file);
        return NULL;
    }
    instruction_line[0] = NULL;
    instruction_line[1] = NULL;
    instruction_line = interprate_file(instruction_line, file);
    free_word_array(file);
    if (instruction_line == NULL /*|| error_label(instruction_line) == EXIT_ERROR*/) {
        free_node_array(instruction_line);
        return NULL;
    }
    return instruction_line;
}