/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add_node
*/

#include "corewar.h"

void add_node(token_t *node, token_t *node_add)
{
    token_t *old_next = node->next;

    node->next = node_add;
    node_add->prev = node;
    if (node_add != NULL)
        node_add->next = old_next;
    if (old_next != NULL)
        old_next->prev = node_add;
}