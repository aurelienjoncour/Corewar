/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include "corewar.h"
#include "struct.h"

int main(int ac, char **av)
{
    unsigned char *memory = NULL;
    data_read_t file = {0};
    corewar_t corewar = {0};

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage(av[0], EXIT_SUCCESS);
    corewar.nbr_cycle = -1;
    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++) {
        corewar.array[i].prog_number = -1;
        corewar.array[i].load_address = -1;
    }
    if (get_argument(ac, av, &corewar) == EXIT_ERROR)
        return EXIT_ERROR;
    memory = create_memory();
    file = read_file(av[1]);
    write_data_on_mem(memory, 0, &file);
    display_memory(memory);
    return EXIT_SUCCESS;
}