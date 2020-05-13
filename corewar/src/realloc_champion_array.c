/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** realloc_champion_array
*/

#include "corewar.h"

champions_t **realloc_champion_array(champions_t **array)
{
    int size = nb_champions(array);
    champions_t **new_array = malloc(sizeof(champions_t *) * (size + 2));

    if (new_array == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        new_array[i] = array[i];
    new_array[size] = NULL;
    new_array[size + 1] = NULL;
    free(array);
    return new_array;
}