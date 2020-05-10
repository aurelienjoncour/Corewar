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
#include "write_t.h"

int usage(char *binary, int status);
char *clean_line(char *line);
char *get_line(FILE *source_file);

int create_file(char *filepath);
int compile_champions(char *filename, FILE *source_file);

char *get_quote_str(char *line);
int get_comment(header_t *header, char *line);
int get_name(header_t *header, char *line);

int get_header(header_t *header, FILE *source_file);
int write_header(int fd, header_t *header, token_t **array);


token_t **get_instruction(FILE *source_file);

token_t *tokeniser(char *av);
void rm_useless_separator(token_t *token);
int error_syntax_line(token_t *token);
int error_params(token_t *token);
int find_index_op(char *mnemonique);
bool allow_char(char *script, char *allow_char);

void get_prog_size(header_t *header, token_t **token);
int get_line_size(token_t *token);
unsigned char get_description_params(token_t *token);
unsigned int get_adress_label(char *label, token_t **array, int index);
unsigned short get_adress_label_short(char *label, token_t **array, int index);
int write_instruction(int fd, token_t **array);
bool is_index_type(char *mnemonique);
bool correct_line(token_t *line);
bool error_label(token_t **array);

#endif /* !COREWAR_H_ */
