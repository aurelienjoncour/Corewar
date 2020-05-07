/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_prog_size
*/

#include "corewar.h"

static bool is_index_type(char *mnemonique)
{
    for (size_t i = 0; index_list[i] != NULL; i++) {
        if (!my_strcmp(index_list[i], mnemonique))
            return true;
    }
    return false;
}

static int get_params_size(TYPE type, bool index_params)
{
    if (type == D_REG)
        return 1;
    if ((type == D_DIR || type == D_IND) && index_params)
        return 2;
    if(type == D_DIR)
        return DIR_SIZE;
    if (type == D_IND)
        return IND_SIZE;
    return 0;
}

static int compute_size(token_t *tmp)
{
    int size = 1;
    int index = 0;
    bool index_params;

    index = find_index_op(tmp->token);
    if (op_tab[index].nbr_args != 1)
        size++;
    index_params = is_index_type(tmp->token);
    while (tmp != NULL) {
        if (tmp->type >= D_REG)
            size += get_params_size(tmp->type, index_params);
        tmp = tmp->next;
    }
    return size;
}

static int get_line_size(token_t *token)
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
    return compute_size(tmp);
}

void get_prog_size(header_t *header, token_t **token)
{
    for (size_t i = 0; token[i] != NULL; i++) {
        header->prog_size += get_line_size(token[i]);
    }
}