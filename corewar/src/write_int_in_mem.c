/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Write integer in memory
*/

#include "corewar.h"

void write_int_in_mem(unsigned char *memory, size_t adress,
unsigned int number)
{
    unsigned char bytes[4] = {0};

    for (size_t i = 0; i < 4; i++) {
        bytes[i] += number >> (24 - i * 8);
        number -= bytes[i] << (24 - i * 8);
        memory[adress % MEM_SIZE] = bytes[i];
        adress++;
    }
}