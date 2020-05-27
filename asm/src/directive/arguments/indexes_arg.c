/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** indexes_arg.c
*/

#include "utils.h"
#include "asm.h"

op_index_t get_indexes_op(op_e op_type)
{
    int i = 0;

    for (i = 0; i < NB_INDEXES_OP; i++) {
        if (INDEXED_OP[i].op == op_type)
            return INDEXED_OP[i];
    }
    return (op_index_t) {LIVE, {-1}};
}

bool is_indexes_op(op_e op_type)
{
    int i = 0;

    for (i = 0; i < NB_INDEXES_OP; i++) {
        if (INDEXED_OP[i].op == op_type)
            return true;
    }
    return false;
}

int get_arg_size_indexed_op(op_e op, token_type_e token, int pos_arg)
{
    op_index_t properties = get_indexes_op(op);
    bool is_index = properties.is_index_arg[pos_arg];

    if (is_index && token != REG_TOKEN)
        return T_IND;
    else
        return get_type_arg_from_token(token);
}

bool is_indexed_arg(op_e op, int pos_arg)
{
    op_index_t properties = get_indexes_op(op);
    return properties.is_index_arg[pos_arg];
}