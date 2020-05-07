/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_syntax_line
*/

#include "corewar.h"

static token_t *check_label(token_t *cursor)
{
    if (cursor->next == NULL) {
        printf("L13\n");
        return NULL;
    } else if (cursor->next->id == ID_LABEL) {
        if (allow_char(cursor->token, LABEL_CHARS))
            return NULL;
        if (cursor->next->next == NULL)
            return cursor->next;
        cursor = cursor->next->next;
        if (cursor->id != ID_SPACE)
            return NULL;
        cursor = cursor->next;
    }
    if (cursor == NULL)
        return NULL;
    return cursor;
}

int error_syntax_line(token_t *token)
{
    int index = 0;
    token_t *cursor = token;

    cursor = check_label(cursor);
    if (cursor == NULL)
        return EXIT_ERROR;
    if (cursor->id == ID_LABEL)
        return EXIT_SUCCESS;
    index = find_index_op(cursor->token);
    if (index == -1)
        return EXIT_ERROR;
    cursor = cursor->next;
    if (cursor == NULL ||
        (cursor->id != ID_SPACE && cursor->id != ID_SEPARATOR))
        return EXIT_ERROR;
    cursor = cursor->next;
    if (cursor == NULL)
        return EXIT_ERROR;
    return error_params(cursor);
}