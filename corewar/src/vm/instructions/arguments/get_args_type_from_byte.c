/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_args_from_byte.c
*/

#include "utils.h"
#include "vm.h"

int get_args_type_from_byte
(unsigned char params_byte, op_t op, args_type_t *params)
{
    int i = 0;
    char mask = 0;

    for (i = 0; i < op.nbr_args; i++, mask = 0) {
        mask = (params_byte >> (MAX_ARGS_NUMBER - i * 2 + 2)) & 0x03;
        if (mask != 3 && mask != T_DIR && mask != T_REG)
            return EXEC_FAIL;
        params[i] = (mask == 3) ? T_IND : mask;
    }
    return EXEC_SUCCESS;
}

int get_size_from_args(op_t op, args_type_t *type)
{
    int size = 0;
    int i = 0;

    for (i = 0; i < op.nbr_args; i++) {
        if (type[i] == T_REG)
            size += T_REG;
        else if
        ((is_indexes_op(op.op_type) && is_indexed_arg(op.op_type, i))
        || type[i] == T_IND)
            size += IND_SIZE;
        else
            size += DIR_SIZE;
    }
    return size;
}