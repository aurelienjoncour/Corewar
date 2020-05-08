/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** read_file
*/

#include "corewar.h"
#include "my.h"

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
    if (!ret)
        return NULL;
    edit_file(ret);
    return ret;
}

void destroy_file(char **file)
{
    for (size_t i = 0; file[i]; i++)
        free(file[i]);
    free(file);
}