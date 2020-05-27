/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_operation.c
*/

#include "utils.h"
#include "vm.h"

int get_operation(unsigned char code, op_t *op)
{
    int i = 0;

    for (i = 0; i < NB_OPERATIONS; i++)
        if (OPERATIONS[i].code == code) {
            *op = OPERATIONS[i];
            return EXEC_SUCCESS;
        }
    return EXEC_FAIL;
}

bool has_param_byte(op_t op)
{
    if (op.op_type != LIVE && op.op_type != ZJMP && op.op_type != FORK
        && op.op_type != LFORK)
        return true;
    return false;
}