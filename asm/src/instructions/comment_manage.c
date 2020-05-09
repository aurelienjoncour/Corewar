/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

static void rm_line(char **file, size_t y)
{
    free(file[y]);
    for (; file[y + 1]; y++)
        file[y] = file[y + 1];
    file[y] = NULL;
}

static bool is_empty(const char *src)
{
    for (size_t i = 0; src[i]; i++) {
        if (src[i] != ' ' && src[i] != '\n')
            return false;
    }
    return true;
}

static void comment_manage(char **file, const size_t y)
{
    for (size_t x = 0; file[y][x]; x++)
        if (file[y][x] == '#')
            file[y][x] = '\0';
}

static void clear_line(char *str)
{
    for (ssize_t i = my_strlen(str) - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            return;
        }
    }
}

void edit_file(char **file)
{
    for (size_t y = 0; file[y]; y++) {
        comment_manage(file, y);
        if (is_empty(file[y]))
            rm_line(file, y);
        if (!file[y])
            continue;
        clear_line(file[y]);
    }
}