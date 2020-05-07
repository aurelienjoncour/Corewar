/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <endian.h>
#include "my.h"
#include "op.h"
#include "constant.h"
#include "node.h"

#define MAX_LINE 1000

int usage(char *binary, int status);
void clean_line(char *line);
char *get_line(FILE *source_file);

int create_file(char *filepath);
int compile_champions(char *filename, FILE *source_file);

char *get_quote_str(char *line);
int get_comment(header_t *header, char *line);
int get_name(header_t *header, char *line);

int get_header(header_t *header, FILE *source_file);
int write_header(int fd, header_t *header);


token_t **get_instruction(FILE *source_file);
char **read_file(FILE *source_file);
void destroy_file(char **file);
void edit_file(char **file);
bool compile_file(char **file);

token_t *tokeniser(char *av);
void rm_useless_separator(token_t *token);
int error_syntax_line(token_t *token);
int error_params(token_t *token);
int find_index_op(char *mnemonique);
bool allow_char(char *script, char *allow_char);

#endif /* !COREWAR_H_ */
