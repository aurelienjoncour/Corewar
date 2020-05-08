/*
** EPITECH PROJECT, 2020
** asm
** File description:
** clean_line
*/

#include "corewar.h"

static void remove_comment(char *line)
{
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == COMMENT_CHAR) {
            line[i] = '\0';
            return;
        }
    }
}

static char *return_str(char *line, size_t shift)
{
    char *str = my_strdup(line+shift);

    free(line);
    return str;
}

char *clean_line(char *line)
{
    size_t shift = 0;

    remove_comment(line);
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\t') {
            shift++;
        } else {
            break;
        }
    }
    if (!my_strlen(line))
        return line;
    for (size_t i = my_strlen(line) - 1; i > 0; i--) {
        if (line[i] == ' ' || line[i] == '\t') {
            line[i] = '\0';
        } else {
            break;
        }
    }
    return return_str(line, shift);
}