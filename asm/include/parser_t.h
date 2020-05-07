/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parser_t
*/

#ifndef PARSER_T_H_
#define PARSER_T_H_

typedef enum id {
    ID_WIHOUT,
    ID_SPACE,
    ID_DIR,
    ID_LABEL,
    ID_SEPARATOR,
}ID;

typedef enum type {
    D_NORMAL,
    D_GET,
    D_SEPARATOR,
    D_REG,
    D_DIR,
    D_IND,
}TYPE;

typedef struct parser_s{
    char token;
    TYPE type;
    ID id;
}parser_t;

typedef struct token_s{
    char *token;
    ID id;
    TYPE type;
    struct token_s *next;
    struct token_s *prev;
}token_t;

#endif /* !PARSER_T_H_ */
