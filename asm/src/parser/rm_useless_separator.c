/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** rm_useless_separator
*/

#include "corewar.h"

static void rm_whitespace(token_t *token)
{
    while (token->next != NULL) {
        if (token->id == ID_SPACE && token->next->id == ID_SPACE)
            rm_next_nodes(token);
        else {
            break;
        }
    }
    if (token->next != NULL)
        rm_whitespace(token->next);
}

static void clean_between_sep(token_t *token)
{
    while (token->next != NULL) {
        if (token->id == ID_SPACE && token->next->id == ID_SEPARATOR) {
            token = rm_node(token);
        } else {
            break;
        }
    }
    if (token->next != NULL)
        clean_between_sep(token->next);
}

static void clean_after_sep(token_t *token)
{
    while (token->next != NULL) {
        if (token->id == ID_SEPARATOR && token->next->id == ID_SPACE) {
            rm_next_nodes(token);
        } else {
            break;
        }
    }
    if (token->next != NULL)
        clean_after_sep(token->next);
}

void rm_useless_separator(token_t *token)
{
    token_t *last = get_last_token(token);

    if (token == NULL)
        return;
    if (!my_strlen(last->token)) {
        last->prev->next = NULL;
        free(last->token);
        free(last);
    }
    rm_whitespace(token);
    clean_between_sep(token);
    clean_after_sep(token);
}