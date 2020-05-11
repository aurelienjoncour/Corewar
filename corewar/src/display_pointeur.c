/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "my.h"

void my_put_pointeur(size_t nb)
{
    char base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                    'C', 'D', 'E', 'F'};
    int temp;
    long unsigned int i = 1;

    if (nb == 0) {
        my_putstr("0");
        return;
    }
    for (int p; nb >= i; p++)
        i = i * 16;
    i = i / 16;
    while (i > 0) {
        temp = nb / i % 16;
        my_putchar(base[temp]);
        i = i / 16;
    }
    return;
}