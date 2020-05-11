/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Display memory
*/

#include "corewar.h"

static size_t nb_char(size_t nb)
{
    long unsigned int i = 1;
    size_t nb_char = 0;

    if (nb == 0)
        return 1;
    for (int p; nb >= i; p++)
        i = i * 16;
    i = i / 16;
    while (i > 0) {
        nb_char++;
        i = i / 16;
    }
    return nb_char;
}

static size_t max_size(void)
{
    size_t max = 0;
    size_t line = 1;

    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (line == 1)
            max = i;
        if (line % BIT_LINE == 0)
            line = 0;
        line++;
    }
    return nb_char(max);
}

void display_memory(unsigned char *memory)
{
    size_t line = 1;
    size_t max = max_size();

    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (line == 1)
            display_pointeur_tab(i, max);
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