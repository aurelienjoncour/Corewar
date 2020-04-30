/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    int status = EXIT_SUCCESS;
    FILE *source_file = NULL;

    if (ac != 2)
        return usage(av[0], EXIT_ERROR);
    if (!my_strcmp(av[1], "-h"))
        return usage(av[0], EXIT_SUCCESS);
    source_file = fopen(av[1], "r");
    if (source_file == NULL)
        return EXIT_ERROR;
    status = compile_champions(av[1], source_file);
    fclose(source_file);
    return status;
}