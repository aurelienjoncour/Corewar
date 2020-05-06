/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** rm_next_node
*/

#include "corewar.h"

int rm_next_nodes(token_t *node)
{
    token_t *node_del = node->next;
    token_t *new_next = NULL;

    if (node_del == NULL) {
        return EXIT_ERROR;
    }
    if (node_del->next != NULL) {
        new_next = node_del->next;
        new_next->prev = node;
    }
    free(node_del->token);
    free(node_del);
    node->next = new_next;
    return EXIT_SUCCESS;
}