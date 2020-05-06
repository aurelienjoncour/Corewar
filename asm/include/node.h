/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** node
*/

#ifndef NODE_H_
#define NODE_H_

#include "parser_t.h"

void add_node(token_t *node, token_t *node_add);
void connect_node(token_t *node_1, token_t *node_2);
token_t *create_node(char *token, ID id, TYPE type);
void destroy_list(token_t *ptr);
void display_list(token_t *start);
int rm_next_nodes(token_t *node);
int add_node_at_the_end(token_t *node_1, token_t *node_2);
token_t *get_last_token(token_t *token);

#endif /* !NODE_H_ */
