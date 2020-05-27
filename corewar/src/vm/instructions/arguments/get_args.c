/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_args.c
*/

#include "utils.h"
#include "vm.h"

int get_value_arg_from_mem(vm_t *this, args_t arg, int pos_arg, int idx)
{
    op_e op_type = arg.op.op_type;

    if (arg.type == T_REG)
        return (int) this->memory[idx];
    if ((is_indexes_op(op_type) && is_indexed_arg(op_type, pos_arg))
    ||  arg.type == T_IND)
        return (int) store_short(this->memory, idx);
    else
        return (int) store_int(this->memory, idx);
}

int get_args(vm_t *this, args_t *args, int idx)
{
    int i = 0;
    int offset = 0;

    for (i = 0; i < args[i].op.nbr_args; i++) {
        args[i].value = get_value_arg_from_mem(
                this,
                args[i],
                i,
                idx + offset
        );
        offset += (args[i].type == T_REG)
        ? T_REG
        : ((is_indexes_op(args[i].op.op_type)
        && is_indexed_arg(args[i].op.op_type, i)) || args[i].type == T_IND)
        ? IND_SIZE
        : DIR_SIZE;
    }
    return EXEC_SUCCESS;
}