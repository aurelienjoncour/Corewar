/*
** EPITECH PROJECT, 2020
** asm
** File description:
** create_file
*/

#include "corewar.h"

static char *get_cor_filename(char *filepath)
{
    char *filename = my_strdup(filepath);
    char *str = my_revstr(filepath);

    if (filename == NULL)
        return NULL;
    if (!my_strncmp(str, "s.", 2))
        filename[my_strlen(filename) - 2] = '\0';
    filename = my_strcat(filename, ".cor");
    return filename;
}

int create_file(char *filepath)
{
    int fd = 0;
    char *filename = get_cor_filename(filepath);

    if (filepath == NULL)
        return -1;
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    free(filename);
    return fd;
}