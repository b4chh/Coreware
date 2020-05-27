/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_directive.c
*/

#include "utils.h"
#include "asm/parser.h"
#include "asm/operations.h"

int destroy_directive(directive_t *this)
{
    int i = 0;

    for (i = 0; i < this->nb_args; i++)
        if (this->args[i] != NULL)
            destroy_arg(this->args[i]);
    free(this);
    return EXEC_SUCCESS;
}