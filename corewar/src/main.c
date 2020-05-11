/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "corewar.h"
#include "struct.h"

int main(int ac, char **av)
{
    unsigned char *memory = NULL;
    data_read_t file = {0};

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage(av[0], EXIT_SUCCESS);
    memory = create_memory();
    file = read_file(av[1]);
    write_data_on_mem(memory, 0, &file);
    display_memory(memory);
    return EXIT_SUCCESS;
}