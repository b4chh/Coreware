/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** exec_instruction.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int launch_instruction(vm_t *this, champion_t *champ)
{
    op_t op;

    if (champ->finished)
        return EXEC_SUCCESS;
    champ->wait_for_op += 1;
    CHECK_ERR(get_operation(this->memory[CIRCULAR(champ->reg[PC_IDX])],
    &op))
    if (champ->wait_for_op < op.nbr_cycles)
        return EXEC_SUCCESS;
    exec_instruction(this, champ, op);
    champ->wait_for_op = 0;
    if (op.op_type != ZJMP)
        find_pc(this, champ);
    return EXEC_SUCCESS;
}

static int get_size_no_byte(op_t op)
{
    if (is_indexes_op(op.op_type))
        return IND_SIZE;
    return (op.type[0] == T_DIR) ? DIR_SIZE : T_REG;
}

int get_size_instruction(vm_t *this, int curr_idx)
{
    int size = 0;
    op_t op;
    args_type_t type[MAX_ARGS_NUMBER] = {0};

    CHECK_ERR(get_operation(CIRCULAR(this->memory[curr_idx]), &op))
    size++;
    if (has_param_byte(op)) {
        size++;
        CHECK_ERR(get_args_type_from_byte(
        this->memory[curr_idx + 1], op, type))
        size += get_size_from_args(op, type);
    } else
        size += get_size_no_byte(op);
    return size;
}

static void copy_types_in_args(op_t op, args_t *args, args_type_t *type)
{
    int i = 0;

    for (i = 0; i < op.nbr_args; i++) {
        args[i].type = type[i];
        args[i].op = op;
    }
}

int exec_instruction(vm_t *this, champion_t *champ, op_t op)
{
    args_type_t type[MAX_ARGS_NUMBER] = {0};
    args_t args[MAX_ARGS_NUMBER] = {0};

    if (has_param_byte(op)) {
        CHECK_ERR(get_args_type_from_byte(
                this->memory[CIRCULAR(champ->reg[PC_IDX] + 1)],
                op,
                type
            )
        )
    } else
        type[0] = op.type[0];
    copy_types_in_args(op, args, type);
    CHECK_ERR(get_args(this, args, champ->reg[PC_IDX] +
    (has_param_byte(op) ? 2 : 1)));
    op.callback(this, champ, args);
    return EXEC_SUCCESS;
}
