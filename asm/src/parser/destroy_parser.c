/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_token.c
*/

#include "utils.h"
#include "asm/parser.h"

int destroy_parser(parser_t *this)
{
    int i = 0;

    for (i = 0; i < this->nb_lines; i++)
        if (this->cmds[i])
            destroy_directive(this->cmds[i]);
    free(this->cmds);
    free(this);
    return EXEC_SUCCESS;
}