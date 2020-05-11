/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    int *memory = NULL;

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage(av[0], EXIT_SUCCESS);
    memory = create_memory();
    display_memory(memory);
    return EXIT_SUCCESS;
}