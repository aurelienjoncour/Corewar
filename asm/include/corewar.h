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

#endif /* !COREWAR_H_ */
