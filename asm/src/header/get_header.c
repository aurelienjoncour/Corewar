/*
** EPITECH PROJECT, 2020
** asm
** File description:
** get_header
*/

#include "corewar.h"

static bool error_quote(char *line)
{
    size_t nb_quote = 0;

    for (size_t i = 0; line[i] != '\0'; i++)
        if (line[i] == '\"')
            nb_quote++;
    if (nb_quote != 2)
        return true;
    return false;
}

char *get_quote_str(char *line)
{
    int index = 0;
    size_t quote[2] = {0};

    if (error_quote(line))
        return NULL;
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\"') {
            quote[index] = i;
            index++;
        }
    }
    if (my_strlen(line+quote[1]) != 1)
        return NULL;
    line[quote[1]] = '\0';
    line += quote[0] + 1;
    return line;
}

int get_header(header_t *header, FILE *source_file, char **line)
{
    int ret = 0;

    *line = get_line(source_file);
    if (*line == NULL)
        return EXIT_ERROR;
    if (get_name(header, *line) == EXIT_ERROR) {
        free(*line);
        return EXIT_ERROR;
    }
    free(*line);
    *line = get_line(source_file);
    if (*line == NULL)
        return EXIT_ERROR;
    ret = get_comment(header, *line);
    if (ret != EXIT_SUCCESS)
        return ret;
    free(*line);
    *line = NULL;
    return EXIT_SUCCESS;
}