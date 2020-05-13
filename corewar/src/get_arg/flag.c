/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** flag
*/

#include "corewar.h"

int dump_flag(int *i, char **av, corewar_t *corewar, size_t *index)
{
    (void)index;
    *i = *i + 1;
    if (av[*i] == NULL)
        return EXIT_ERROR;
    if (allow_char(av[*i], "0123456789")) {
        return EXIT_ERROR;
    }
    if (corewar->nbr_cycle != -1)
        return EXIT_ERROR;
    corewar->nbr_cycle = my_getnbr(av[*i]);
    return EXIT_SUCCESS;
}

int number_flag(int *i, char **av, corewar_t *corewar, size_t *index)
{
    *i = *i + 1;
    if (av[*i] == NULL)
        return EXIT_ERROR;
    if (allow_char(av[*i], "1234") || my_strlen(av[*i]) != 1)
        return EXIT_ERROR;
    if (corewar->array[*index]->prog_number != -1)
        return EXIT_ERROR;
    corewar->array[*index]->prog_number = my_getnbr(av[*i]);
    return EXIT_SUCCESS;
}

int load_flag(int *i, char **av, corewar_t *corewar, size_t *index)
{
    *i = *i + 1;
    if (av[*i] == NULL)
        return EXIT_ERROR;
    if (allow_char(av[*i], "0123456789"))
        return EXIT_ERROR;
    if (corewar->array[*index]->load_address != -1)
        return EXIT_ERROR;
    corewar->array[*index]->load_address = my_getnbr(av[*i]);
    return EXIT_SUCCESS;
}

int champs_flag(int *i, char **av, corewar_t *corewar, size_t *index)
{
    char *str = NULL;

    if (*index > 3)
        return EXIT_ERROR;
    if (av[*i] == NULL)
        return EXIT_ERROR;
    str = my_strdup(av[*i]);
    if (str == NULL)
        return EXIT_ERROR;
    str = my_revstr(str);
    if (my_strncmp(str, "roc.", 4)) {
        free(str);
        return EXIT_ERROR;
    }
    free(str);
    corewar->array[*index]->filepath = my_strdup(av[*i]);
    if (corewar->array[*index]->filepath == NULL)
        return EXIT_ERROR;
    *index = *index + 1;
    return EXIT_SUCCESS;
}