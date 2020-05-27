/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_arg.c
*/

#include <asm/operations.h>
#include "utils.h"
#include "my.h"
#include "asm.h"

static bool is_label_used(parser_t *parser)
{
    if (parser->tokens
    ->info_tokens[parser->curr_line]->str_v[parser->index_token])
        return true;
    return false;
}

static void get_value_simple(args_t *this, parser_t *parser, int pos_arg)
{
    op_t op = parser->cmds[parser->curr_line]->instruction;

    if (!is_indexes_op(op.op_type)) {
        if (this->type == T_IND)
            this->args_value.ind = (short) parser->tokens
            ->info_tokens[parser->curr_line]->nbr_v[parser->index_token];
        else
            this->args_value.dir = parser->tokens
            ->info_tokens[parser->curr_line]->nbr_v[parser->index_token];
        return;
    }
    if (is_indexed_arg(op.op_type, pos_arg) || this->type == T_IND) {
        this->is_index = true;
        this->args_value.ind = (short) parser->tokens
        ->info_tokens[parser->curr_line]->nbr_v[parser->index_token];
    } else
        this->args_value.dir = parser->tokens
        ->info_tokens[parser->curr_line]->nbr_v[parser->index_token];
}

args_t *create_arg(parser_t *this, args_type_t type, int pos_arg)
{
    args_t *arg = malloc(sizeof(args_t));

    CHECK_MALLOC(arg)
    arg->is_index = false;
    if (type == T_REG) {
        arg->type = type;
        arg->args_value.reg = (char) this->tokens
        ->info_tokens[this->curr_line]->nbr_v[this->index_token];
        return arg;
    }
    arg->type = type;
    if (is_label_used(this)) {
        if (find_value_label_behind(this) == EXEC_FAIL)
            CHECK_ERR_PTR(find_value_label_after(this))
    }
    get_value_simple(arg, this, pos_arg);
    return arg;
}