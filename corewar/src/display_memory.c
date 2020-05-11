/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Display memory
*/

#include "corewar.h"

void display_memory(unsigned char *memory)
{
    size_t line = 1;

    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (line == 1) {
            my_put_pointeur((size_t) i);
            my_putstr(" : ");
        }
        if (memory[i] < 16)
            my_putstr("0");
        my_putnbr_base(memory[i], "0123456789ABCDEF");
        if (line % BIT_LINE == 0) {
            my_putchar('\n');
            line = 0;
        }
        else
            my_putchar(SPACE);
        line++;
    }
}