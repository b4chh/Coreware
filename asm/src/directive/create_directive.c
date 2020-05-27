/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_directive.c
*/

#include "utils.h"
#include "asm/parser.h"
#include "asm/operations.h"

directive_t *create_directive(op_t op)
{
    directive_t *this = malloc(sizeof(directive_t));

    CHECK_MALLOC(this)
    this->instruction = op;
    this->nb_args = op.nb_args;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        this->args[i] = NULL;
    return this;
}
