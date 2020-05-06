/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parser_tab
*/

#include "corewar.h"

const parser_t delimit[] =
{
    {' ', D_NORMAL, ID_SPACE},
    {'\t', D_NORMAL, ID_TAB},
    {DIRECT_CHAR, D_GET, ID_DIR},
    {LABEL_CHAR, D_GET,ID_LABEL},
    {SEPARATOR_CHAR, D_SEPARATOR, ID_SEPARATOR},
    {0, ID_WIHOUT, ID_WIHOUT},
};