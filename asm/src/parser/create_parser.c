/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_parser.c
*/

#include "utils.h"
#include "asm/tokenizer.h"
#include "asm/parser.h"

parser_t *create_parser(tokenizer_t *tokenizer)
{
    int i = 0;
    parser_t *this = malloc(sizeof(parser_t));

    CHECK_MALLOC(this)
    this->tokens = tokenizer;
    this->index_token = 0;
    this->curr_line = 0;
    this->nb_lines = tokenizer->nb_lines;
    this->cmds = malloc(sizeof(directive_t *) * this->nb_lines);
    for (i = 0; i < this->nb_lines; i++)
        this->cmds[i] = NULL;
    return this;
}