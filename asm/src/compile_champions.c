/*
** EPITECH PROJECT, 2020
** asm
** File description:
** compile_champions
*/

#include "corewar.h"

static int end_func(char **file, int fd_compiled, int ret)
{
    
    destroy_file(file);
    close(fd_compiled);
    return ret;
}

int compile_champions(char *filename, FILE *source_file)
{
    int fd_compiled = 0;
    header_t header = {0};
    char **file;

    if (get_header(&header, source_file) == EXIT_ERROR)
        return EXIT_ERROR;
    fd_compiled = create_file(filename);
    if (fd_compiled == -1)
        return EXIT_ERROR;
    if (write_header(fd_compiled, &header) == EXIT_ERROR) {
        close(fd_compiled);
        return EXIT_ERROR;
    }
    file = read_file(source_file);
    if (!file)
        return EXIT_ERROR;
    //if (!compile_file(file))
    //    return end_func(file, fd_compiled, EXIT_ERROR);
    return end_func(file, fd_compiled, EXIT_SUCCESS);
}