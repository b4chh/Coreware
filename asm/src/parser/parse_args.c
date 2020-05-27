/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_args.c
*/

#include <asm/operations.h>
#include "utils.h"
#include "asm.h"

args_type_t get_type_arg_from_token(token_type_e type)
{
    int i = 0;

    for (i = 0; i < NB_LINK_ARGS; i++) {
        if (TOKEN_ARGS[i].type_token == type)
            return TOKEN_ARGS[i].type_arg;
    }
    return -1;
}

bool is_valid_type(parser_t *this, token_type_e type, int index, args_type_t *a)
{
    args_type_t mask = this->cmds[this->curr_line]->instruction.type[index];
    args_type_t curr_type = get_type_arg_from_token(type);

    if ((mask & curr_type) != curr_type)
        return false;
    *a = curr_type;
    return true;
}

int parse_args(parser_t *this)
{
    int i = 0;
    int tmp_i = this->index_token;
    token_type_e t_type;
    args_type_t type_arg = 0;

    for (i = 0; i < this->cmds[this->curr_line]->nb_args; i++) {
        t_type = this->tokens->info_tokens[this->curr_line]
        ->token_type[this->index_token];
        CHECK_FALSE(is_valid_type(this, t_type, i, &type_arg))
        this->cmds[this->curr_line]->args[i] = create_arg(this, type_arg, i);
        CHECK_NULL(this->cmds[this->curr_line]->args[i]);
        this->index_token += 1;
    }
    CHECK_FALSE(this->index_token - tmp_i
    == this->cmds[this->curr_line]->nb_args)
    return EXEC_SUCCESS;
}