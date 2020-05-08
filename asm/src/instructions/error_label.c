/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** error_label
*/

#include "corewar.h"

static char **get_list_label(token_t **array)
{
    size_t index = 0;
    char **list = malloc(sizeof(char *) * 2);

    if (list == NULL)
        return NULL;
    list[0] = NULL;
    list[1] = NULL;
    for (size_t i = 0; array[i] != NULL; i++) {
        if (array[i]->next->id == ID_LABEL) {
            list[index] = my_strdup(array[i]->token);
            if (list[index] == NULL)
                return NULL;
            list = realloc_word_array(list);
            index++;
        }
    }
    return list;
}

static bool find_label_on_list(char **list, char *label)
{
    for (size_t i = 0; list[i] != NULL; i++) {
        if (!my_strcmp(label, list[i]))
            return true;
    }
    return false;
}

static bool check_label(token_t *token, char **list)
{
    for (token_t *tmp = token; tmp != NULL; tmp = tmp->next) {
        if (tmp->type > D_REG && tmp->prev->id == ID_LABEL &&
            !find_label_on_list(list, tmp->token)) {
            return false;
        }
    }
    return true;
}

bool error_label(token_t **array)
{
    char **list = get_list_label(array);

    if (list == NULL)
        return true;
    for (size_t i = 0; array[i] != NULL; i++) {
        if (!check_label(array[i], list))
            return true;
    }
    free_word_array(list);
    return false;
}