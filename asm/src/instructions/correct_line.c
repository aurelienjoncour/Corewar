/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"

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
    return true;
}