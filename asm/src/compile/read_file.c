/*
** EPITECH PROJECT, 2019
** 
** File description:
** DESCRIPTION
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

#define MAX_LINE 1000

static bool rec_read(char ***ret, int size, FILE *source_file)
{
    char *tmp = NULL;
    size_t val = 0;
    int read_size = getline(&tmp, &val, source_file);

    if (read_size > 0 && size < MAX_LINE) {
        if (!rec_read(ret, size + 1, source_file))
            return false;
    }
    else {
        free(tmp);
        *ret = malloc(sizeof(char *) * (size + 1));
        if (!(*ret))
            return false;
        (*ret)[size] = NULL;
        return true;
    }
    if (tmp[my_strlen(tmp) - 1] == '\n')
        tmp[my_strlen(tmp) - 1] = '\0';
    (*ret)[size] = tmp;
    return true;
}

char **read_file(FILE *source_file)
{
    char **ret;

    rec_read(&ret, 0, source_file);
    return ret;
}

void destroy_file(char **file)
{
    for (size_t i = 0; file[i]; i++)
        free(file[i]);
    free(file);
}