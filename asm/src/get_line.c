/*
** EPITECH PROJECT, 2020
** asm
** File description:
** get_line
*/

#include "corewar.h"

char *get_line(FILE *source_file)
{
    char *line = NULL;
    ssize_t nread = 0;
    size_t len = 0;

    while (true) {
        nread = getline(&line, &len, source_file);
        if (nread == -1)
            return NULL;
        line[nread - 1] = '\0';
        clean_line(line);
        if (my_strlen(line))
            break;
    }
    return line;
}