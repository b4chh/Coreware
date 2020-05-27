/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** indexes_arg.c
*/

#include "utils.h"
#include "vm.h"

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

bool is_indexed_arg(op_e op, int pos_arg)
{
    op_index_t properties = get_indexes_op(op);
    return properties.is_index_arg[pos_arg];
}