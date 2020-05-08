/*
** EPITECH PROJECT, 2020
** asm
** File description:
** compile_champions
*/

#include "corewar.h"

static int end_func(token_t **array, int fd_compiled, int ret)
{
    free_node_array(array);
    close(fd_compiled);
    return ret;
}

int compile_champions(char *filename, FILE *source_file)
{
    int fd_compiled = 0;
    header_t header = {0};
    token_t **instruction_line = NULL;

    if (get_header(&header, source_file) == EXIT_ERROR)
        return EXIT_ERROR;
    instruction_line = get_instruction(source_file);
    if (instruction_line == NULL)
        return EXIT_ERROR;
    fd_compiled = create_file(filename);
    if (fd_compiled == -1)
        return EXIT_ERROR;
    if (write_header(fd_compiled, &header, instruction_line) == EXIT_ERROR) {
        close(fd_compiled);
        return EXIT_ERROR;
    }
    if (write_instruction(fd_compiled, instruction_line) == EXIT_ERROR)
        return end_func(instruction_line, fd_compiled, EXIT_ERROR);
    return end_func(instruction_line, fd_compiled, EXIT_SUCCESS);
}