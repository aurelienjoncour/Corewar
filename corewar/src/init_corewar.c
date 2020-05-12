/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_corewar
*/

#include "corewar.h"

int init_corewar(corewar_t *corewar)
{
    corewar->nbr_cycle = -1;
    for (size_t i = 0; i < MAX_NB_CHAMPIONS; i++) {
        corewar->array[i].prog_number = -1;
        corewar->array[i].load_address = -1;
    }
    corewar->memory = create_memory();
    if (corewar->memory == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}