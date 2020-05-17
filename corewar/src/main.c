/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "corewar.h"

int init(int ac, char **av, corewar_t *corewar)
{
    if (init_corewar(corewar))
        return EXIT_ERROR;
    if (get_argument(ac, av, corewar) == EXIT_ERROR) {
        destroy_corewar(corewar);
        return EXIT_ERROR;
    }
    if (init_champions(corewar))
        return EXIT_ERROR;
    corewar->array = sort_champions(corewar);
    if (corewar->array == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    int ret = 0;
    corewar_t corewar = {0};

    if (ac == 1)
        return EXIT_ERROR;
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage(av[0], EXIT_SUCCESS);
    if (init(ac, av, &corewar) == EXIT_ERROR)
        return EXIT_ERROR;
    ret = loop(&corewar);
    destroy_corewar(&corewar);
    return ret;
}