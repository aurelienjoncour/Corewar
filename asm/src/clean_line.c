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

void clean_line(char *line)
{
    remove_comment(line);
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\t') {
            line++;
        } else {
            break;
        }
    }
    if (!my_strlen(line))
        return;
    for (size_t i = my_strlen(line) - 1; i > 0; i--) {
        if (line[i] == ' ' || line[i] == '\t') {
            line[i] = '\0';
        } else {
            break;
        }
    }
}