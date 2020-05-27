/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** file_operations.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int get_length_file(FILE *file)
{
    char *buffer = NULL;
    size_t n = 0;
    int nb_line = 0;

    if (!file)
        return 0;
    while (getline(&buffer, &n, file) != -1) {
        nb_line++;
        n = 0;
        free(buffer);
        buffer = NULL;
    }
    free(buffer);
    fseek(file, 0, SEEK_SET);
    return nb_line;
}

char **store_file(FILE *file, int length_file)
{
    char **lines = NULL, *buffer = NULL;
    size_t n = 0;
    int i = 0, length = 0;

    if (length_file == 0 || length_file == 1)
        return NULL;
    CHECK_MALLOC(length_file)
    lines = malloc(sizeof(char *) * (length_file + 1));
    CHECK_MALLOC(lines)
    CHECK_MALLOC(file)
    lines[length_file] = NULL;
    while ((length = getline(&buffer, &n, file)) != -1) {
        lines[i++] = clear_buffer(buffer, length);
        n = 0;
    }
    free(buffer);
    return lines;
}