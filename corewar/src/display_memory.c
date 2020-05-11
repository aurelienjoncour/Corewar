/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Display memory
*/

#include "corewar.h"

void display_memory(unsigned char *memory)
{
    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (memory[i] < 16)
            my_putstr("0");
        my_putnbr_base(memory[i], "0123456789ABCDEF");
        if ((i + 1) % 64 == 0)
            my_putstr("\n");
    }
}