/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** nb_champion
*/

#include "corewar.h"

int nb_champions(champions_t **array)
{
    int nb = 0;

    if (array == NULL)
        return 0;
    for (; array[nb] != NULL && array[nb]->filepath != NULL; nb++);
    return nb;
}