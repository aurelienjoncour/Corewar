/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Create memory
*/

#include "corewar.h"

int *create_memory(void)
{
    int *memory = malloc(sizeof(char) * MEM_SIZE);

    for (size_t i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    return memory;
}