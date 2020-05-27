/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** compile.c
*/

#include <asm/operations.h>
#include "utils.h"
#include "my.h"
#include "asm.h"

char *get_filename(char *location)
{
    char *new = NULL;
    char **split = m_str_split(location, '/');
    char **name_split = NULL;

    if (len_tab(split) == 1) {
        name_split = m_str_split(split[0], '.');
        new = m_strcat_dup(name_split[0], ".cor");
    } else {
        name_split = m_str_split(split[len_tab(split) - 1], '.');
        new = m_strcat_dup(name_split[0], ".cor");
    }
    splitstr_destroy(name_split);
    splitstr_destroy(split);
    return new;
}

int compile(tokenizer_t *tokenizer, char *location)
{
    FILE *compiled = NULL;
    char *filename = NULL;
    parser_t *parser = create_parser(tokenizer);

    CHECK_NULL(parser);
    CHECK_ERR(run_parser(parser))
    get_prog_size(parser);
    CHECK_NULL(filename = get_filename(location));
    compiled = fopen(filename, "w");
    CHECK_NULL(compiled)
    CHECK_ERR(encode_header(parser, compiled));
    CHECK_ERR(encode_bytes(parser, compiled));
    free(filename);
    destroy_parser(parser);
    fclose(compiled);
    return EXEC_SUCCESS;
}