/*
** EPITECH PROJECT, 2020
** sort_champions
** File description:
** sort champ
*/

#include "corewar.h"

bool verify_sort(champions_t **arr, int nb)
{
    int nb_champ = nb_champions(arr);
    int a = -1;

    if (nb_champ != nb)
        return false;
    for (int i = 0; arr[i]; i++) {
        if (a > arr[i]->prog_number)
            return false;
        a = arr[i]->prog_number;
    }
    return true;
}

static int find_min(corewar_t *cw, int save)
{
    int a = 0;
    int min = __INT_MAX__;

    for (int i = 0; cw->array[i]; i++) {
        if ((cw->array[i]->prog_number < min) &&
        (cw->array[i]->prog_number > save)) {
            min = cw->array[i]->prog_number;
            a = i;
        }
    }
    return a;
}

champions_t **sort_champions(corewar_t *cw)
{
    int nb_ch = nb_champions(cw->array);
    champions_t **sort_arr = malloc(sizeof(champions_t *) * (nb_ch + 1));
    int a = 0;
    int save = -1;

    for (int i = 0; i <= nb_ch; i++) {
        sort_arr[i] = NULL;
    }
    if (verify_sort(cw->array, nb_ch))
        return cw->array;
    for (int b = 0; (verify_sort(sort_arr, nb_ch) != true); b++) {
        a = find_min(cw, save);
        sort_arr[b] = cw->array[a];
        save = cw->array[a]->prog_number;
    }
    return sort_arr;
}