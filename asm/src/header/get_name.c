/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_name
*/

#include "corewar.h"

int get_name(header_t *header, char *line)
{
    char *between_quote = NULL;

    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
        return EXIT_FAILURE;
    line += my_strlen(NAME_CMD_STRING) + 1;
    between_quote = get_quote_str(line);
    if (between_quote == NULL || my_strlen(between_quote) > PROG_NAME_LENGTH)
        return EXIT_ERROR;
    my_strcpy(header->prog_name, between_quote);
    return EXIT_SUCCESS;
}