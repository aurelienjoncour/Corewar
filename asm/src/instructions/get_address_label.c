/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_address_label
*/

#include "corewar.h"

static short get_params_size_short(TYPE type, bool index_params)
{
    if (type == D_REG)
        return 1;
    if ((type == D_DIR || type == D_IND) && index_params)
        return 2;
    if (type == D_DIR)
        return DIR_SIZE;
    if (type == D_IND)
        return IND_SIZE;
    return 0;
}

static short compute_size_short(token_t *tmp)
{
    short size = 1;
    int index = 0;
    bool index_params;

    index = find_index_op(tmp->token);
    if (op_tab[index].nbr_args != 1 || op_tab[index].code == 16)
        size++;
    index_params = is_index_type(tmp->token);
    while (tmp != NULL) {
        if (tmp->type >= D_REG)
            size += get_params_size_short(tmp->type, index_params);
        tmp = tmp->next;
    }
    return size;
}

static short get_line_size_short(token_t *token)
{
    token_t *tmp = token;

    if (tmp->next->id == ID_LABEL) {
        tmp = tmp->next;
        if (tmp->next != NULL) {
            tmp = tmp->next->next;
        } else {
            return 0;
        }
    }
    return compute_size_short(tmp);
}

unsigned short get_adress_label_short(char *label, token_t **array, int index)
{
    unsigned short adress = 0;

    for (size_t i = index; array[i] != NULL; i++) {
        if (array[i]->next->id == ID_LABEL &&
            !my_strcmp(array[i]->token, label)) {
            return adress;
        }
        adress += get_line_size_short(array[i]);
    }
    adress = 65535;
    for (ssize_t i = index - 1; i >= 0; i--) {
        if (array[i]->next->id == ID_LABEL &&
            !my_strcmp(array[i]->token, label)) {
            adress -= get_line_size_short(array[i]);
            return adress + 1;
        }
        adress -= get_line_size_short(array[i]);
    }
    return 0;
}

unsigned int get_adress_label(char *label, token_t **array, int index)
{
    unsigned int adress = 0;

    for (size_t i = index; array[i] != NULL; i++) {
        if (array[i]->next->id == ID_LABEL &&
            !my_strcmp(array[i]->token, label)) {
            return adress;
        }
        adress += get_line_size(array[i]);
    }
    adress = 4294967295;
    for (ssize_t i = index - 1; i >= 0; i--) {
        if (array[i]->next->id == ID_LABEL &&
            !my_strcmp(array[i]->token, label)) {
            adress -= get_line_size(array[i]);
            return adress + 1;
        }
        adress -= get_line_size(array[i]);
    }
    return 0;
}