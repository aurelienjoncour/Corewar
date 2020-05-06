/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** create_node
*/

#include "corewar.h"

token_t *create_node(char *token, ID id, TYPE type)
{
    token_t *node = malloc(sizeof(token_t));

    if (node == NULL)
        return NULL;
    if (token == NULL) {
        node->token = malloc(sizeof(char));
        node->token[0] = '\0';
    } else {
        node->token = my_strdup(token);
    }
    if (node->token == NULL)
        return NULL;
    node->id = id;
    node->type = type;
    node->next = NULL;
    node->prev = NULL;
    return node;
}