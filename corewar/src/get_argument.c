/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_argument
*/

#include "corewar.h"

ssize_t find_flag(char *flag)
{
    for (size_t i = 0; flags[i].flag != NULL; i++) {
        if (!my_strncmp(flag, flags[i].flag, my_strlen(flags[i].flag)))
            return i;
    }
    return -1;
}

int get_argument(int ac, char **av, corewar_t *corewar)
{
    ssize_t retour = 0;
    int flag = 0;
    size_t index = 0;

    for (int i = 1; i < ac; i++) {
        flag = find_flag(av[i]);
        if (flag != -1) {
            retour = flags[flag].fct(&i, av, corewar, &index);
            if (retour == EXIT_ERROR) {
                return EXIT_ERROR;
            }
        } else {
            if (champs_flag(&i, av, corewar, &index) == EXIT_ERROR) {
                return EXIT_ERROR;
            }
        }
    }
    return EXIT_SUCCESS;
}
