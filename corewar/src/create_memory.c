/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Create memory
*/

#include "corewar.h"

unsigned char *create_memory(void)
{
    unsigned char *memory = malloc(sizeof(unsigned char) * MEM_SIZE);

    for (size_t i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    return memory;
}