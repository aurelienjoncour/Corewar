/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static size_t my_put_pointeur(size_t nb)
{
    char base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                    'C', 'D', 'E', 'F'};
    int temp;
    long unsigned int i = 1;
    size_t nb_char = 0;

    if (nb == 0) {
        my_putstr("0");
        return 1;
    }
    for (int p; nb >= i; p++)
        i = i * 16;
    i = i / 16;
    while (i > 0) {
        temp = nb / i % 16;
        my_putchar(base[temp]);
        nb_char++;
        i = i / 16;
    }
    return nb_char;
}

void display_pointeur_tab(size_t i, size_t max)
{
    size_t move = max - my_put_pointeur((size_t) i);

    for (size_t u = 0; u < move; u++)
        my_putchar(SPACE);
    my_putstr(" : ");
}