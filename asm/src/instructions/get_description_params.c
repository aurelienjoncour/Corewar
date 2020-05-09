/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_description_params
*/

#include "corewar.h"

static const char one = 1;
static const char two = 2;
static const char three = 3;

unsigned char get_description_params(token_t *token)
{
    unsigned char byte = 0;
    int shift = 6;

    for (token_t *tmp = token; tmp != NULL; tmp = tmp->next) {
        if (tmp->type >= D_REG) {
            if (tmp->type == D_REG) {
                byte += (one << shift);
            }
            if (tmp->type == D_IND) {
                byte += (three << shift);
            }
            if (tmp->type == D_DIR) {
                byte += (two << shift);
            }
            shift -= 2;
        }
    }
    return byte;
}