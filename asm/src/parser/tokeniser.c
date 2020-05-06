/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tokeniser
*/

#include "corewar.h"

static char *add_one_char(char *str, char c)
{
    int size = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (size + 2));

    if (new_str == NULL)
        return NULL;
    my_strcpy(new_str, str);
    free(str);
    new_str[size] = c;
    new_str[size + 1] = '\0';
    return new_str;
}

static int is_special_id(char c)
{
    for (int i = 0; delimit[i].token != 0; i++) {
        if (delimit[i].token == c) {
            return i;
        }
    }
    return -1;
}

static token_t *init_node(char *av)
{
    token_t *start = NULL;
    char str[2] = {0};

    str[0] = av[0];
    start = create_node(str, ID_WIHOUT, D_NORMAL);
    return start;
}

static int add_special_token(int index, token_t *start, token_t *last)
{
    token_t *data = NULL;
    char str[2] = {0};

    str[0] = delimit[index].token;
    if (!my_strlen(last->token)) {
        last->token = add_one_char(last->token, delimit[index].token);
        last->id = delimit[index].id;
        last->type = delimit[index].type;
    } else {
        data = create_node(str, delimit[index].id, delimit[index].type);
        if (data == NULL)
            return EXIT_ERROR;
        add_node_at_the_end(start, data);
    }
    data = create_node(NULL, 0, 0);
    if (data == NULL)
        return EXIT_ERROR;
    add_node_at_the_end(start, data);
    return EXIT_SUCCESS;
}

token_t *tokeniser(char *av)
{
    int index = 0;
    token_t *start = init_node(av);
    token_t *last = NULL;

    if (start == NULL)
        return NULL;
    for (size_t i = 1; av[i] != '\0'; i++) {
        index = is_special_id(av[i]);
        last = get_last_token(start);
        if (index == -1) {
            last->token = add_one_char(last->token, av[i]);
            if (last->token == NULL)
                return NULL;
        } else {
            if (add_special_token(index, start, last) == EXIT_ERROR)
                return NULL;
        }
    }
    return start;
}