/*
** EPITECH PROJECT, 2020
** write_on_memory
** File description:
** write_on_memory.c
*/

#include "corewar.h"

void write_data_on_mem(corewar_t *corewar, champions_t *champion)
{
    int adr = champion->load_address;
    int a = 0;

    adr = adr % MEM_SIZE;
    for (size_t i = adr; a < champion->head->prog_size; i++) {
        if (i >= MEM_SIZE)
            i = 0;
        corewar->memory[i] = champion->data[a];
        a++;
    }
}