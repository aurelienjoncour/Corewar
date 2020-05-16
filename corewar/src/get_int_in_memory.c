/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_int_in_memory
*/

#include "corewar.h"

unsigned int get_int_in_memory(unsigned char *memory, size_t adress)
{
    unsigned int var = 0;

    for (int i = 24; i >= 0; i -= 8) {
        var += memory[adress % MEM_SIZE] << i;
        adress++;
    }
    return var;
}

unsigned int get_short_in_memory(unsigned char *memory, size_t adress)
{
    unsigned int var = 0;

    for (int i = 8; i >= 0; i -= 8) {
        var += memory[adress % MEM_SIZE] << i;
        adress++;
    }
    return var;
}