/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    corewar_t corewar = {0};

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage(av[0], EXIT_SUCCESS);
    if (init_corewar(&corewar))
        return EXIT_ERROR;
    if (get_argument(ac, av, &corewar) == EXIT_ERROR) {
        destroy_corewar(&corewar);
        return EXIT_ERROR;
    }
    if (init_champions(&corewar))
        return EXIT_ERROR;
    //display_memory(corewar.memory);
    sort_champions(&corewar);
    destroy_corewar(&corewar);
    return EXIT_SUCCESS;
}