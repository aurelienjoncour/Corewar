/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

static char get_type(TYPE type)
{
    if (type == D_REG)
        return 1;
    if (type == D_DIR)
        return 2;
    if (type == D_IND)
        return 4;
    return 0;
}

static bool correct_params(op_t act, token_t *line)
{
    size_t param = 0;
    token_t *move = line;

    for (size_t i = 0; move; i++) {
        if (move->type >= D_REG) {
            if ((get_type(move->type) & act.type[param]) == 0)
                return false;
            param++;
        }
        move = move->next;
    }
    return true;
}

static char get_line_size(token_t *line)
{
    size_t i;
    size_t nb = 0;
    token_t *move = line;

    for (i = 0; move; i++) {
        if (move->type >= D_REG)
            nb++;
        move = move->next;
    }
    return nb;
}

bool correct_line(token_t *line)
{
    char size = get_line_size(line);
    int pos = 0;

    if (!line->next->next)
        return true;
    if (line->next->id == ID_LABEL)
        pos = find_index_op(line->next->next->next->token);
    else
        pos = find_index_op(line->token);
    if (op_tab[pos].nbr_args != size)
        return false;
    if (correct_params(op_tab[pos], line))
        return false;
    return true;
}